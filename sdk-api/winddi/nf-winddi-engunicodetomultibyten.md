# EngUnicodeToMultiByteN function

## Description

The **EngUnicodeToMultiByteN** function converts the specified Unicode string into an ANSI string using the current ANSI code page.

## Parameters

### `MultiByteString` [out]

Pointer to the buffer that receives the resultant ANSI string.

### `MaxBytesInMultiByteString` [in]

Specifies the maximum number of bytes to be written to *MultiByteString.* If this value is too small, causing *MultiByteString* to be a truncated equivalent of *UnicodeString*, then no error condition results.

### `BytesInMultiByteString` [out, optional]

Pointer to a ULONG that receives the number of bytes written to *MultiByteString*.

### `UnicodeString` [in]

Pointer to the Unicode source string that is to be converted to ANSI.

### `BytesInUnicodeString` [in]

Specifies the number of bytes in *UnicodeString.*

## Return value

None

## See also

[EngMultiByteToUnicodeN](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmultibytetounicoden)

[EngWideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwidechartomultibyte)