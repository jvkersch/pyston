/* C interface to provide acccess to BoxedUnicode internals. */

#include "unicodeobject.h"

#ifdef __cplusplus
extern "C" {
#endif

void unicodeSetChr(PyUnicodeObject *obj, int pos, Py_UNICODE chr);
int unicodeGetStrLen(PyUnicodeObject *obj);
Py_UNICODE* unicodeGetWritableStr(PyUnicodeObject *obj);

int Py_UNICODE_MATCH(PyUnicodeObject *string, Py_ssize_t offset, PyUnicodeObject *substring);

/* The functions below are implemented in src/runtime/unicode.cpp */
PyUnicodeObject *_PyUnicode_New(Py_ssize_t length);
int _PyUnicode_Resize(PyUnicodeObject **unicode, Py_ssize_t length);

int unicode_decode_call_errorhandler(const char *errors, PyObject **errorHandler,
                                     const char *encoding, const char *reason,
                                     const char *input, Py_ssize_t insize, Py_ssize_t *startinpos,
                                     Py_ssize_t *endinpos, PyObject **exceptionObject, const char **inptr,
                                     PyUnicodeObject **output, Py_ssize_t *outpos, Py_UNICODE **outptr);

PyObject *unicode_encode_call_errorhandler(const char *errors,
                                           PyObject **errorHandler,
                                           const char *encoding, const char *reason,
                                           const Py_UNICODE *unicode, Py_ssize_t size, PyObject **exceptionObject,
                                           Py_ssize_t startpos, Py_ssize_t endpos,
                                           Py_ssize_t *newpos);

void raise_encode_exception(PyObject **exceptionObject,
                            const char *encoding,
                            const Py_UNICODE *unicode, Py_ssize_t size,
                            Py_ssize_t startpos, Py_ssize_t endpos,
                            const char *reason);

void raise_translate_exception(PyObject **exceptionObject,
                               const Py_UNICODE *unicode, Py_ssize_t size,
                               Py_ssize_t startpos, Py_ssize_t endpos,
                               const char *reason);

PyObject *unicode_translate_call_errorhandler(const char *errors,
                                              PyObject **errorHandler,
                                              const char *reason,
                                              const Py_UNICODE *unicode, Py_ssize_t size, PyObject **exceptionObject,
                                              Py_ssize_t startpos, Py_ssize_t endpos,
                                              Py_ssize_t *newpos);


#ifdef __cplusplus
}
#endif
