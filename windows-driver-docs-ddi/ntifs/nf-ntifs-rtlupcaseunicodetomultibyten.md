# RtlUpcaseUnicodeToMultiByteN function

## Description

The **RtlUpcaseUnicodeToMultiByteN** routine translates the specified Unicode string into a new uppercase character string, using the current system ANSI code page (ACP). The translated string is not necessarily from a multibyte character set.

## Parameters

### `MultiByteString` [out]

Pointer to a caller-allocated buffer to receive the translated string.

### `MaxBytesInMultiByteString` [in]

Maximum number of bytes to be written at *MultiByteString*. If this value causes the translated string to be truncated, **RtlUpcaseUnicodeToMultiByteN** does not return an error status.

### `BytesInMultiByteString` [out, optional]

Pointer to a caller-allocated variable that receives the length, in bytes, of the translated string. This parameter can be **NULL**.

### `UnicodeString` [in]

Pointer to the Unicode source string to be translated.

### `BytesInUnicodeString` [in]

Size, in bytes, of the string at *UnicodeString*.

## Return value

**RtlUpcaseUnicodeToMultiByteN** returns STATUS_SUCCESS.

## Remarks

**RtlUpcaseUnicodeToMultiByteN** translates the given Unicode string using the current system ANSI code page installed at system boot time and converts the translated string to uppercase.

This routine does not modify the source string. It returns a NULL-terminated ANSI string if the given *BytesInUnicodeString* included a NULL terminator and if the given *MaxBytesInMultiByteString* did not cause truncation.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlMultiByteToUnicodeN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlmultibytetounicoden)

[RtlUnicodeToMultiByteN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetomultibyten)

[RtlUnicodeToMultiByteSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetomultibytesize)