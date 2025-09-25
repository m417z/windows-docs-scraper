# EngMultiByteToUnicodeN function

## Description

The **EngMultiByteToUnicodeN** function converts the specified ANSI source string into a Unicode string using the current ANSI code page.

## Parameters

### `UnicodeString` [out]

Pointer to the buffer that receives the resultant Unicode string.

### `MaxBytesInUnicodeString` [in]

Supplies the maximum number of bytes to be written to *UnicodeString.* If this value is too small, causing *UnicodeString* to be a truncated equivalent of *MultiByteString*, no error condition results.

### `BytesInUnicodeString` [out, optional]

Pointer to a ULONG that receives the number of bytes written to *UnicodeString*.

### `MultiByteString` [in]

Pointer to the ANSI source string that is to be converted to Unicode.

### `BytesInMultiByteString` [in]

Specifies the number of bytes in *MultiByteString.*

## Return value

None

## See also

[EngMultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmultibytetowidechar)

[EngUnicodeToMultiByteN](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunicodetomultibyten)