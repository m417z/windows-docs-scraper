# RtlUpcaseUnicodeToOemN function

## Description

The **RtlUpcaseUnicodeToOemN** routine translates a given Unicode string into an uppercase OEM string, using the current system OEM code page.

## Parameters

### `OemString` [out]

Pointer to a caller-allocated buffer to receive the translated string.

### `MaxBytesInOemString` [in]

Maximum number of bytes to be written to *OemString*.

### `BytesInOemString` [out, optional]

Pointer to a caller-allocated variable that receives the number of bytes in the translated string. This parameter can be **NULL**.

### `UnicodeString` [in]

Pointer to the Unicode source string to be translated.

### `BytesInUnicodeString` [in]

Size, in bytes, of the string at *UnicodeString*.

## Return value

**RtlUnicodeToOemN** returns STATUS_SUCCESS if the full string at *UnicodeString* was successfully translated, converted to uppercase, and returned at *OemString*. Otherwise, it can return STATUS_BUFFER_OVERFLOW if the destination string must be truncated to fit the given *MaxBytesInOemString*.

## Remarks

For the return value STATUS_BUFFER_OVERFLOW, the truncated string at *OemString* was translated without error.

For the return value STATUS_SUCCESS, the value at *BytesInOemString*, if any, indicates the length of the returned string, rather than the given *MaxBytesInOemString*.

This routine does not modify the source string. It returns a null-terminated OEM string if the given *BytesInUnicodeString* included a NULL terminator and if the given *MaxBytesInOemString* did not cause truncation.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlUnicodeStringToOemSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemsize)

[RtlUnicodeToOemN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetooemn)

[RtlUpcaseUnicodeStringToCountedOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtocountedoemstring)

[RtlUpcaseUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtooemstring)