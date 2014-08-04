var ubjson = require('./ubjson');

function test(data) {
  console.log(data);
  var b = ubjson.encode(data);
  console.log(b);
  console.log(b.toJSON());
  var str = '';
  for (var i = 0; i < b.length; i++) {
    var s = String.fromCharCode(b[i]);
    if (/[A-z0-9\[\]\{\}\#\$]/.test(s)) {
      str += s + ' ';
    } else {
      str += '\\x' + b[i].toString(16) + ' ';
    }
  }
  console.log(str);
  console.log(ubjson.decode(b));
}

test(1);
test("1");
test([]);
test([1, 2, 3, 4]);
test([0, undefined, 1]);
test({a: 1, b: 2});
test({PiELESDigitalValues: [false, false, false, false, false, false, false, false], PiELESAnalogValues: [127, 127, 127, 127, 127, 127, 127]});

a = {};
a.a = a;
test(a);
