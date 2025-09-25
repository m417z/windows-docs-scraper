# RtlUnicodeStringToOemSize macro

## Description

The **RtlUnicodeStringToOemSize** routine determines the size, in bytes, that a given Unicode string will be after it is translated into an OEM string.

## Parameters

### `STRING`

Pointer to a caller-allocated Unicode string.

## Remarks

**RtlUnicodeStringToOemSize** can be called to determine how much memory to allocate when translating a Unicode string to OEM characters with **RtlUnicodeStringToOemString** or **RtlUpcaseUnicodeStringToOemString**. The returned value includes space for a NULL terminator for the OEM string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlOemStringToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtounicodesize)

[RtlUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemstring)

[RtlUpcaseUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtooemstring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)