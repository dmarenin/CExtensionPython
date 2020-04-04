from distutils.core import setup, Extension


sfc_module = Extension('superfastcode', sources=['module.cpp'])

setup(name='superfastcode', version='1.0',
      description='Python Package with superfastcode C++ extension',
      ext_modules=[sfc_module]
      )



#from distutils.core import setup, Extension
#setup(name = 'myModule', version = '1.0',  \
#   ext_modules = [Extension('myModule', ['test.c'])])


#python setup.py build
#python setup.py install


# $ python3.6 setup.py build
#running build
#running build_ext
#building 'myModule' extension
#/usr/bin/clang -fno-strict-aliasing -Wsign-compare -fno-common -dynamic -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes -arch i386 -arch x86_64 -g -I/Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m -c test.c -o build/temp.macosx-10.6-intel-3.6/test.o
#/usr/bin/clang -bundle -undefined dynamic_lookup -arch i386 -arch x86_64 -g build/temp.macosx-10.6-intel-3.6/test.o -o build/lib.macosx-10.6-intel-3.6/myModule.cpython-36m-darwin.so

# $ python3.6 setup.py install
#running install
#running build
#running build_ext
#running install_lib
#copying build/lib.macosx-10.6-intel-3.6/myModule.cpython-36m-darwin.so -> /Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/site-packages
#running install_egg_info
#Removing /Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/site-packages/myModule-1.0-py3.6.egg-info
#Writing /Library/Frameworks/Python.framework/Versions/3.6/lib/python3.6/site-packages/myModule-1.0-py3.6.egg-info

# $ python3.6
#Python 3.6.0 (v3.6.0:41df79263a11, Dec 22 2016, 17:23:13)
#[GCC 4.2.1 (Apple Inc. build 5666) (dot 3)] on darwin
#Type "help", "copyright", "credits" or "license" for more information.
#>>> import myModule
#>>> myModule.helloworld()
#Hello World
#>>>