# RtlOemToUnicodeN function

## Description

The **RtlOemToUnicodeN** routine translates the specified source string into a Unicode string, using the current system OEM code page.

## Parameters

### `UnicodeString` [out]

Pointer to a caller-allocated buffer that receives the translated string.

### `MaxBytesInUnicodeString` [in]

Maximum number of bytes to be written at *UnicodeString*. If this value causes the translated string to be truncated, **RtlOemToUnicodeN** does not return an error status.

### `BytesInUnicodeString` [out, optional]

Pointer to a caller-allocated variable that receives the length, in bytes, of the translated string. This parameter can be **NULL**.

### `OemString` [in]

Pointer to the OEM source string to be translated into Unicode. If the current code page describes a single-byte character set, this pointer can be the same address as *UnicodeString*.

### `BytesInOemString` [in]

Length, in bytes, of the string at *OemString*.

## Return value

**RtlOemToUnicodeN** returns STATUS_SUCCESS if the full string at *OemString* was successfully translated and returned at *UnicodeString*. Otherwise, it can return STATUS_BUFFER_OVERFLOW if the destination string must be truncated to fit the given *MaxBytesInUnicodeString*. STATUS_BUFFER_OVERFLOW is a warning NTSTATUS value.

## Remarks

**RtlOemToUnicodeN** supports only precomposed Unicode characters that are mapped to the current system OEM code page installed at system boot time.

If the current system code page defines a single-byte character set, all single-byte characters in the range 0x00 to 0x7f are simply zero-extended in the corresponding Unicode string to speed the conversion operation. The character value 0x5c in such a code page is translated into the backslash character, even if the current code page defines this character as the Yen sign.

For the return value STATUS_SUCCESS, the value of *BytesInUnicodeString*, if any, indicates the length of the returned Unicode string, rather than the given *MaxBytesInUnicodeString*.

This routine does not modify the source string unless the *UnicodeString* and *OemString* pointers are equivalent. The returned Unicode string is null-terminated if it is not truncated.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlOemStringToCountedUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodestring)

[RtlOemStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtounicodestring)

[RtlUnicodeToOemN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetooemn)