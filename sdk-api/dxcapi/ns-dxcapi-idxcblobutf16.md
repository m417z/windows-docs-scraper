## Description

A blob containing a null-terminated wide string, and using the native UTF-16 wide character encoding of Windows. **IDxcBlobUtf16** is a legacy alias for **IDxcBlobWide**. This interface is used to return output name strings in DXC. Other string output blobs (such as errors/warnings, preprocessed HLSL, or other text) are returned using encodings based on the `-encoding` option passed to the compiler. The methods of **IDxcBlobUtf16** guarantee null-terminated text, and native wide character encoding.

## Remarks

## See also