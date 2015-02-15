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

#include "runtime/types.h"

namespace pyston {

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

extern "C" PyObject* PyUnicode_FromFormat(const char* format, ...) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_FromFormatV(const char* format, va_list vargs) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_UNICODE* PyUnicode_AsUnicode(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_ssize_t PyUnicode_GetSize(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_FromEncodedObject(PyObject* obj, const char* encoding, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_FromObject(PyObject* obj) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_FromWideChar(const wchar_t* w, Py_ssize_t size) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_ssize_t PyUnicode_AsWideChar(PyUnicodeObject* unicode, wchar_t* w, Py_ssize_t size) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Decode(const char* s, Py_ssize_t size, const char* encoding,
                                      const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Encode(const Py_UNICODE* s, Py_ssize_t size, const char* encoding,
                                      const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsEncodedObject(PyObject* unicode, const char* encoding, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsEncodedString(PyObject* unicode, const char* encoding, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF8(const char* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF8Stateful(const char* s, Py_ssize_t size, const char* errors,
                                                  Py_ssize_t* consumed) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeUTF8(const Py_UNICODE* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsUTF8String(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF32(const char* s, Py_ssize_t size, const char* errors,
                                           int* byteorder) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF32Stateful(const char* s, Py_ssize_t size, const char* errors, int* byteorder,
                                                   Py_ssize_t* consumed) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeUTF32(const Py_UNICODE* s, Py_ssize_t size, const char* errors,
                                           int byteorder) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsUTF32String(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF16(const char* s, Py_ssize_t size, const char* errors,
                                           int* byteorder) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF16Stateful(const char* s, Py_ssize_t size, const char* errors, int* byteorder,
                                                   Py_ssize_t* consumed) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeUTF16(const Py_UNICODE* s, Py_ssize_t size, const char* errors,
                                           int byteorder) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsUTF16String(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF7(const char* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUTF7Stateful(const char* s, Py_ssize_t size, const char* errors,
                                                  Py_ssize_t* consumed) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeUTF7(const Py_UNICODE* s, Py_ssize_t size, int base64SetO, int base64WhiteSpace,
                                          const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeUnicodeEscape(const char* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeUnicodeEscape(const Py_UNICODE* s, Py_ssize_t size) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsUnicodeEscapeString(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeRawUnicodeEscape(const char* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeRawUnicodeEscape(const Py_UNICODE* s, Py_ssize_t size) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsRawUnicodeEscapeString(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeLatin1(const char* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeLatin1(const Py_UNICODE* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsLatin1String(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeASCII(const char* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeASCII(const Py_UNICODE* s, Py_ssize_t size, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsASCIIString(PyObject* unicode) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_DecodeCharmap(const char* s, Py_ssize_t size, PyObject* mapping,
                                             const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_EncodeCharmap(const Py_UNICODE* s, Py_ssize_t size, PyObject* mapping,
                                             const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_AsCharmapString(PyObject* unicode, PyObject* mapping) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_TranslateCharmap(const Py_UNICODE* s, Py_ssize_t size, PyObject* table,
                                                const char* errors) noexcept {
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

extern "C" PyObject* PyUnicode_Concat(PyObject* left, PyObject* right) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Split(PyObject* s, PyObject* sep, Py_ssize_t maxsplit) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Splitlines(PyObject* s, int keepend) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Translate(PyObject* str, PyObject* table, const char* errors) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Join(PyObject* separator, PyObject* seq) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_ssize_t PyUnicode_Tailmatch(PyObject* str, PyObject* substr, Py_ssize_t start, Py_ssize_t end,
                                          int direction) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_ssize_t PyUnicode_Find(PyObject* str, PyObject* substr, Py_ssize_t start, Py_ssize_t end,
                                     int direction) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" Py_ssize_t PyUnicode_Count(PyObject* str, PyObject* substr, Py_ssize_t start, Py_ssize_t end) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Replace(PyObject* str, PyObject* substr, PyObject* replstr,
                                       Py_ssize_t maxcount) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int PyUnicode_Compare(PyObject* left, PyObject* right) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_RichCompare(PyObject* left, PyObject* right, int op) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" PyObject* PyUnicode_Format(PyObject* format, PyObject* args) noexcept {
    Py_FatalError("unimplemented");
}

extern "C" int PyUnicode_Contains(PyObject* container, PyObject* element) noexcept {
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
                                                Py_ssize_t format_spec_len) {
    Py_FatalError("unimplemented");
}


void setupUnicode() {
    unicode_cls->freeze();
}

void teardownUnicode() {
}
}
