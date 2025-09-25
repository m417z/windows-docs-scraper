# RtlUnicodeToMultiByteN function

## Description

The **RtlUnicodeToMultiByteN** routine translates the specified Unicode string into a new character string, using the current system ANSI code page (ACP). The translated string is not necessarily from a multibyte character set.

## Parameters

### `MultiByteString` [out]

Pointer to a caller-allocated buffer to receive the translated string. *MultiByteString* buffer must not overlap with *UnicodeString* buffer.

### `MaxBytesInMultiByteString` [in]

Maximum number of bytes to be written to *MultiByteString*. If this value causes the translated string to be truncated, **RtlUnicodeToMultiByteN** does not return an error status.

### `BytesInMultiByteString` [out, optional]

Pointer to a caller-allocated variable that receives the length, in bytes, of the translated string. This parameter is optional and can be **NULL**.

### `UnicodeString` [in]

Pointer to the Unicode source string to be translated.

### `BytesInUnicodeString` [in]

Size, in bytes, of the string at *UnicodeString*.

## Return value

**RtlUnicodeToMultiByteN** returns STATUS_SUCCESS.

## Remarks

**RtlUnicodeToMultiByteN** translates the given Unicode string using the current system ANSI code page that was installed at system boot time.

Although *BytesInMultiByteString* is optional and can be **NULL**, callers should provide storage for it, because the received length can be used to determine whether the conversion was successful.

This routine does not modify the source string. It returns a null-terminated multibyte string if the given *BytesInUnicodeString* included a NULL terminator and if the given *MaxBytesInMultiByteString* did not cause truncation.

Like **RtlUnicodeToMultiByteSize**, **RtlUnicodeToMultiByteN** supports only precomposed Unicode characters that are mapped to the current system ANSI code page installed at system boot.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlMultiByteToUnicodeN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlmultibytetounicoden)

[RtlUnicodeToMultiByteSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetomultibytesize)

[RtlUpcaseUnicodeToMultiByteN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodetomultibyten)