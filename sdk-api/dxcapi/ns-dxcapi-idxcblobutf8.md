## Description

A blob containing a null-terminated string, and using the UTF-8 character encoding. Depending on the `-encoding` option passed to the compiler, this interface is used to return string output blobs (such as errors/warnings, preprocessed HLSL, or other text). The methods of **IDxcBlobUtf8** guarantee null-terminated text, and UTF-8 character encoding. [IDxcBlobUtf16](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf16) is used to return output name strings in DXC.

## Remarks

## See also