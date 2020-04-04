#include <Python.h>
#include <stdio.h>


/*
 * Implements an example function.
 */
PyDoc_STRVAR(module2_example_doc, "example(obj, number)\
\
Example function");

PyObject *module2_example(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
    PyObject *obj = NULL;
    int number = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "obj", "number", NULL };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi", keywords, &obj, &number)) {
        return NULL;
    }

    /* Function implementation starts here */

    if (number < 0) {
        PyErr_SetObject(PyExc_ValueError, obj);
        return NULL;    /* return NULL indicates error */
    }


    PyObject* PyObject_CallFunction(PyObject * callable);

    PyObject* t;

    t = PyTuple_New(3);
    PyTuple_SetItem(t, 0, PyLong_FromLong(1L));
    PyTuple_SetItem(t, 1, PyLong_FromLong(2L));
    PyTuple_SetItem(t, 2, PyUnicode_FromString("three"));

    return t;

    printf("Hello, world!\n");

    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name)) {
        return NULL;
    }

    printf("Hello, %s!\n", name);
    Py_RETURN_NONE;

    //return Py_BuildValue("ii", a + b, a - b);

    return PyFloat_FromDouble(1);

    Py_RETURN_NONE;
}

/*
 * List of functions to add to module2 in exec_module2().
 */
static PyMethodDef module2_functions[] = {
    { "example", (PyCFunction)module2_example, METH_VARARGS | METH_KEYWORDS, module2_example_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize module2. May be called multiple times, so avoid
 * using static state.
 */
int exec_module2(PyObject *module) {
    PyModule_AddFunctions(module, module2_functions);

    PyModule_AddStringConstant(module, "__author__", "dmarenin");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2020);
    PyModule_AddIntConstant(module, "year", 2021);

    return 0; /* success */
}

/*
 * Documentation for module2.
 */
PyDoc_STRVAR(module2_doc, "The module2 module");


static PyModuleDef_Slot module2_slots[] = {
    { Py_mod_exec, exec_module2 },
    { 0, NULL }
};

static PyModuleDef module2_def = {
    PyModuleDef_HEAD_INIT,
    "module2",
    module2_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    module2_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_module2() {
    return PyModuleDef_Init(&module2_def);
}





//#include <Python.h>
//
//// Function 1: A simple 'hello world' function
//static PyObject* helloworld(PyObject* self, PyObject* args)
//{
//    printf("Hello World\n");
//    return Py_None;
//}
//
//// Our Module's Function Definition struct
//// We require this `NULL` to signal the end of our method
//// definition
//static PyMethodDef myMethods[] = {
//    { "helloworld", helloworld, METH_NOARGS, "Prints Hello World" },
//    { NULL, NULL, 0, NULL }
//};
//
//// Our Module Definition struct
//static struct PyModuleDef myModule = {
//    PyModuleDef_HEAD_INIT,
//    "myModule",
//    "Test Module",
//    -1,
//    myMethods
//};
//
//// Initializes our module using our above struct
//PyMODINIT_FUNC PyInit_myModule(void)
//{
//    return PyModule_Create(&myModule);
//}