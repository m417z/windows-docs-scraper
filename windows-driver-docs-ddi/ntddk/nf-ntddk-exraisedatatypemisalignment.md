# ExRaiseDatatypeMisalignment function

## Description

The **ExRaiseDatatypeMisalignment** routine can be used with structured exception handling to throw a driver-determined exception for a misaligned data type that occurs when a driver processes I/O requests.

## Remarks

**ExRaiseDatatypeMisalignment** raises an exception with the exception code set to STATUS_DATATYPE_MISALIGNMENT.

Because **ExRaiseDatatypeMisalignment** can only be used at IRQL = PASSIVE_LEVEL, only high-level drivers typically use this routine — for example, file system drivers.

## See also

[ExRaiseAccessViolation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exraiseaccessviolation)

[ExRaiseStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exraisestatus)

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[KeBugCheckEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kebugcheckex)