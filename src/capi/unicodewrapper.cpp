#include "types.h"
#include "unicodewrapper.h"

extern "C" void unicodeSetChr(PyUnicodeObject *obj, int pos, Py_UNICODE chr)
{
    // Probably do some bounds checking, don't you think?
    obj->str[pos] = chr;
}

extern "C" int unicodeGetStrLen(PyUnicodeObject *obj)
{
    return obj->str.size();
}

extern "C" Py_UNICODE* unicodeGetWritableStr(PyUnicodeObject *obj)
{
    // See str.cpp for why this works...
    return &obj->str[0];
}

// extern "C" void Py_UNICODE_COPY(PyUnicodeObject* target, const Py_UNICODE* source, int length)
// {
//     Py_FatalError("unimplemented");
// }

extern "C" int Py_UNICODE_MATCH(PyUnicodeObject *string, Py_ssize_t offset, PyUnicodeObject *substring)
{
    Py_FatalError("unimplemented");
}

// Stub implementation to continue with compiling unicodeobject.c --- XXX replace this afterwards.
extern "C" void * PyObject_Malloc(size_t) noexcept
{
    Py_FatalError("unimplemented");
}

extern "C" int unicode_decode_call_errorhandler(const char *errors, PyObject **errorHandler,
                                     const char *encoding, const char *reason,
                                     const char *input, Py_ssize_t insize, Py_ssize_t *startinpos,
                                     Py_ssize_t *endinpos, PyObject **exceptionObject, const char **inptr,
                                     PyUnicodeObject **output, Py_ssize_t *outpos, Py_UNICODE **outptr)
{
    Py_FatalError("unimplemented");
}

extern "C" void raise_encode_exception(PyObject **exceptionObject,
                                       const char *encoding,
                                       const Py_UNICODE *unicode, Py_ssize_t size,
                                       Py_ssize_t startpos, Py_ssize_t endpos,
                                       const char *reason)
{
    Py_FatalError("unimplemented");
}


extern "C" PyObject *unicode_encode_call_errorhandler(const char *errors,
                                                      PyObject **errorHandler,
                                                      const char *encoding, const char *reason,
                                                      const Py_UNICODE *unicode, Py_ssize_t size, PyObject **exceptionObject,
                                                      Py_ssize_t startpos, Py_ssize_t endpos,
                                                      Py_ssize_t *newpos)
{
    Py_FatalError("unimplemented");
}

extern "C" void raise_translate_exception(PyObject **exceptionObject,
                               const Py_UNICODE *unicode, Py_ssize_t size,
                               Py_ssize_t startpos, Py_ssize_t endpos,
                               const char *reason)
{
    Py_FatalError("unimplemented");
}


extern "C" PyObject *unicode_translate_call_errorhandler(const char *errors,
                                                     PyObject **errorHandler,
                                                     const char *reason,
                                                     const Py_UNICODE *unicode, Py_ssize_t size, PyObject **exceptionObject,
                                                     Py_ssize_t startpos, Py_ssize_t endpos,
                                                         Py_ssize_t *newpos)
{
    Py_FatalError("unimplemented");
}
