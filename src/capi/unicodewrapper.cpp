#include "types.h"
#include "unicodewrapper.h"

extern "C" void unicodeSetChr(PyUnicodeObject *obj, int pos, Py_UNICODE chr)
{
    // Probably do some bounds checking, don't you think?
    obj->str[pos] = chr;
}

extern "C" Py_UNICODE* unicodeGetWritableStr(PyUnicodeObject *obj)
{
    // See str.cpp for why this works...
    return &obj->str[0];
}

extern "C" void Py_UNICODE_COPY(PyUnicodeObject* target, const Py_UNICODE* source, int length)
{
    Py_FatalError("unimplemented");
}
