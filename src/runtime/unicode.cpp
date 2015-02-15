// Copyright (c) 2014-2015 Dropbox, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "gc/collector.h"
#include "runtime/types.h"

namespace pyston {

BoxedUnicode::BoxedUnicode(const Py_UNICODE* s, size_t n) : str(s, n) {
    gc::registerGCManagedBytes(this->str.size());
}

BoxedUnicode::BoxedUnicode(unicode_string&& s) : str(std::move(s)) {
    gc::registerGCManagedBytes(this->str.size());
}

BoxedUnicode::BoxedUnicode(const unicode_string& s) : str(s) {
    gc::registerGCManagedBytes(this->str.size());
}

// capi stuff

// XXX Move this allocator to a separate wrapper module.

// XXX TODO make my methods also noexcept

/* We allocate one more byte to make sure the string is
   Ux0000 terminated; some code relies on that.

   XXX This allocator could further be enhanced by assuring that the
   free list never reduces its size below 1.

*/

extern "C" PyUnicodeObject *_PyUnicode_New(Py_ssize_t length) {
    return new BoxedUnicode(std::basic_string<Py_UNICODE>(length, '\x0000'));
}

extern "C" int _PyUnicode_Resize(PyUnicodeObject **unicode, Py_ssize_t length) {
    // Py_FatalError("unimplemented");
    return 0;  // XXX do nothing for now!
}

static std::string unicode_default_encoding = "ascii";
extern "C" const char* PyUnicode_GetDefaultEncoding(void) noexcept {
    return unicode_default_encoding.c_str();
}

extern "C" int PyUnicode_SetDefaultEncoding(const char* encoding) noexcept {
    unicode_default_encoding = encoding;
    return 0;
}

extern "C" int PyUnicode_ClearFreeList() noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_FromEncodedObject(PyObject* obj, const char* encoding, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Decode(const char* s, Py_ssize_t size, const char* encoding,
                                      const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsEncodedObject(PyObject* unicode, const char* encoding, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsEncodedString(PyObject* unicode, const char* encoding, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeMBCS(const char* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeMBCSStateful(const char* s, int size, const char* errors, int* consumed) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeMBCS(const Py_UNICODE* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsMBCSString(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Split(PyObject* s, PyObject* sep, Py_ssize_t maxsplit) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_RichCompare(PyObject* left, PyObject* right, int op) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* _PyUnicode_AsDefaultEncodedString(PyObject*, const char*) noexcept {
    Py_FatalError("unimplemented");
}

// This should get implemented in unicodeobject.c itself!
extern "C" PyObject *PyUnicode_AsDecodedObject(PyObject *unicode,
                                               const char *encoding,
                                               const char *errors) {
    Py_FatalError("unimplemented");
}

extern "C" void _PyUnicode_Fini() noexcept {
    Py_FatalError("unimplemented");
}

extern "C" void _PyUnicode_Init() noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsAlpha(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsDecimalDigit(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsDigit(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsLinebreak(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsLowercase(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsNumeric(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsTitlecase(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsUppercase(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_IsWhitespace(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_ToDecimalDigit(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int _PyUnicode_ToDigit(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_UNICODE _PyUnicode_ToLowercase(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" double _PyUnicode_ToNumeric(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_UNICODE _PyUnicode_ToTitlecase(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_UNICODE _PyUnicode_ToUppercase(Py_UNICODE ch) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject * _PyUnicode_FormatAdvanced(PyObject *obj,
                                                Py_UNICODE *format_spec,
                                                Py_ssize_t format_spec_len) noexcept {
    Py_FatalError("unimplemented");
}


void setupUnicode() {
    unicode_cls->freeze();
}

void teardownUnicode() {
}
}
