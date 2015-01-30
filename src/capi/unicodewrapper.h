/* C interface to provide acccess to BoxedUnicode internals. */

#include "unicodeobject.h"

#ifdef __cplusplus
extern "C" {
#endif

void unicodeSetChr(PyUnicodeObject *obj, int pos, Py_UNICODE chr);
Py_UNICODE* unicodeGetWritableStr(PyUnicodeObject *obj);

/* The functions below are implemented in src/runtime/unicode.cpp */
PyUnicodeObject *_PyUnicode_New(Py_ssize_t length);
int _PyUnicode_Resize(PyUnicodeObject **unicode, Py_ssize_t length);

#ifdef __cplusplus
}
#endif
