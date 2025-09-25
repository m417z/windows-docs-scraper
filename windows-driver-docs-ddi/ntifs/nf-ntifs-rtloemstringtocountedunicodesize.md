# RtlOemStringToCountedUnicodeSize macro

## Description

The **RtlOemStringToCountedUnicodeSize** routine determines the size, in bytes, that a given OEM string will be after it is translated into a counted Unicode string.

## Parameters

### `STRING`

Pointer to a caller-allocated OEM string.

## Remarks

**RtlOemStringToCountedUnicodeSize** can be called to determine how much memory to allocate when translating an OEM string to Unicode with **RtlOemStringToCountedUnicodeString**. The returned value does not include space for a NULL terminator for the Unicode string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlOemStringToCountedUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodestring)

[RtlOemStringToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtounicodesize)