# ExRaiseAccessViolation function

## Description

The **ExRaiseAccessViolation** routine can be used with structured exception handling to throw a driver-determined exception for a memory access violation that occurs when a driver processes I/O requests.

## Remarks

**ExRaiseAccessViolation** raises an exception with the exception code set to STATUS_ACCESS_VIOLATION.

Because **ExRaiseAccessViolation** can only be used at IRQL = PASSIVE_LEVEL, only high-level drivers typically use this routine—for example, file system drivers.

## See also

[ExRaiseDatatypeMisalignment](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exraisedatatypemisalignment)

[ExRaiseStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exraisestatus)

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[KeBugCheckEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kebugcheckex)