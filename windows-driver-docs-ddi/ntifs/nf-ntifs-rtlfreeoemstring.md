# RtlFreeOemString function

## Description

The **RtlFreeOemString** routine releases storage that was allocated by any of the **Rtl..ToOemString** routines.

## Parameters

### `OemString` [in, out]

Pointer to the OEM string buffer that was allocated by a preceding call to **RtlUnicodeStringToCountedOemString**, **RtlUnicodeStringToOemString**, **RtlUpcaseUnicodeStringToCountedOemString**, or **RtlUpcaseUnicodeStringToOemString**.

## Return value

None

## Remarks

**RtlFreeOemString** deallocates memory only for the buffered OEM string. This routine does not free the buffered Unicode string passed in a preceding call to the **Rtl..ToOemString** routine.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[OEM_STRING](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff558741(v=vs.85))

[RtlUnicodeStringToCountedOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtocountedoemstring)

[RtlUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodestringtooemstring)

[RtlUpcaseUnicodeStringToCountedOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtocountedoemstring)

[RtlUpcaseUnicodeStringToOemString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodestringtooemstring)