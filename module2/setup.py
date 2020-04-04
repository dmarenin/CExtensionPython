from distutils.core import setup, Extension


sfc_module = Extension('module2', sources=['module2.c'])

setup(name='superfastcode', version='1.0',
      description='Python Package with C extension',
      ext_modules=[sfc_module]
      )
