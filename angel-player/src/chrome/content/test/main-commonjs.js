const url = require ('jetpack/sdk/url');
const fs = require('jetpack/sdk/io/fs');
const { Cu, Cc, Ci } = require('chrome');
const console =
    Cu.import("resource://gre/modules/devtools/Console.jsm").console;
const appStartup =
    Cc["@mozilla.org/toolkit/app-startup;1"].getService(Ci.nsIAppStartup);

const TEST_DIR = 'chrome://angel-player/content/test/tests';

exports.onLoad = function(window) {
    let testDir = url.toFilename(TEST_DIR);
    let tests = [];

    // Walk down the directory tree, and include all files in subdirectories.
    // Will get stuck on directory loops.
    function addFiles (root, relative) {
      // Invariant: (root + '/' + relative) ends with '/'
      for (let f of fs.readdirSync(root + '/' + relative)) {
        let path = root + '/' + relative + f;
        let stat = fs.statSync(path);
        if (stat.isDirectory()) {
          addFiles(root, relative + f + '/');
        } else {
          tests.push(relative + f);
        }
      }
    }

    addFiles(testDir, '');

    appStartup.quit(appStartup.eForceQuit);

    let testsAllPassed = true;

    for (let testFileName of tests) {
        let testFilePath = 'tenshi/test/tests/' + testFileName;
        console.log("Running unit test " + testFileName);
        let testModule;
        try {
            testModule = require(testFilePath);
        } catch(e) {
            testsAllPassed = false;
            console.log("Test " + testFileName + " failed to load!");
        }
        
        let ret;
        try {
            ret = testModule.run(window);
            if (!ret) {
                testsAllPassed = false;
                console.log("Test " + testFileName + " failed!");
            } else {
                console.log("OK");
            }
        } catch(e) {
            testsAllPassed = false;
            console.log("Test " + testFileName + " threw an exception!");
        }
    }

    if (testsAllPassed) {
        console.log("All tests passed!");
    } else {
        console.log("SOME TESTS DID NOT PASS!");
    }

    // Quit
    appStartup.quit(appStartup.eForceQuit);
};
