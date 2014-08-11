#!/usr/bin/env python
from __future__ import print_function
import traceback

def run_dir(ctx, name):
    try:
        ctx.recurse(name, mandatory=False)
    except:
        print('Exception in build system in subdirectory ', name, ':')
        traceback.print_exc()


def recurse(ctx, dirs=None):
    if dirs is None:
        dirs = ['eda', 'controller', 'smartsensor_fw', 'grizzly_firmware',
                'network', 'vm/angelic', 'vm/lua']
    for d in dirs:
        run_dir(ctx, d)


def options(ctx):
    ctx.add_option('--emcc-only',
                   action='store_true',
                   help='Only configure enough (emcc) to build angel-player.')
    recurse(ctx)


def configure(ctx):
    ctx.env['root'] = ctx.path.abspath()
    if ctx.options.emcc_only:
        recurse(ctx, ['network', 'vm/angelic', 'vm/lua'])
    else:
        recurse(ctx)


def build(ctx):
    recurse(ctx)
