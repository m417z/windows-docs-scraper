# RtlOemStringToUnicodeSize macro

## Description

The **RtlOemStringToUnicodeSize** routine determines the size, in bytes, that a given OEM string will be after it is translated into a null-terminated Unicode string.

## Parameters

### `STRING`

Pointer to a caller-allocated OEM string.

## Remarks

**RtlOemStringToUnicodeSize** can be called to determine how much memory to allocate when translating an OEM string to Unicode with **RtlOemStringToUnicodeString**. The returned value includes space for the NULL terminator.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlOemStringToCountedUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodesize)

[RtlOemStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtounicodestring)