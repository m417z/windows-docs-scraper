# RtlMultiByteToUnicodeN function

## Description

The **RtlMultiByteToUnicodeN** routine translates the specified source string into a Unicode string, using the current system ANSI code page (ACP). The source string is not necessarily from a multibyte character set.

## Parameters

### `UnicodeString` [out]

Pointer to a caller-allocated buffer that receives the translated string. *UnicodeString* buffer must not overlap with *MultiByteString* buffer.

### `MaxBytesInUnicodeString` [in]

Maximum number of bytes to be written at *UnicodeString*. If this value causes the translated string to be truncated, **RtlMultiByteToUnicodeN** does not return an error status.

### `BytesInUnicodeString` [out, optional]

Pointer to a caller-allocated variable that receives the length, in bytes, of the translated string. This parameter can be **NULL**.

### `MultiByteString` [in]

Pointer to the string to be translated.

### `BytesInMultiByteString` [in]

Size, in bytes, of the string at *MultiByteString*.

## Return value

**RtlMultiByteToUnicodeN** returns STATUS_SUCCESS.

## Remarks

**RtlMultiByteToUnicodeN** supports only precomposed Unicode characters that are mapped to the current system ANSI code page installed at system boot.

Although *BytesInUnicodeString* is optional and can be **NULL**, callers should provide storage for it, because the received length can be used to determine whether the conversion was successful.

If the current system code page defines a single-byte character set, all ANSI characters in the range 0x00 to 0x7f are simply zero-extended in the corresponding Unicode string to speed the conversion operation. The ANSI value 0x5c in such a code page is translated into the backslash character, even if the current single-byte code page defines this character as the Yen sign.

**RtlMultiByteToUnicodeN** does not modify the source string unless the *UnicodeString* and *MultiByteString* pointers are equivalent. The returned Unicode string is not null-terminated.

Like **RtlMultiByteToUnicodeSize**, **RtlMultiByteToUnicodeN** supports only precomposed Unicode characters that are mapped to the current system ANSI code page installed at system boot.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlMultiByteToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlmultibytetounicodesize)

[RtlUnicodeToMultiByteN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetomultibyten)