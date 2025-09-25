# ExRaiseStatus function

## Description

The **ExRaiseStatus** routine is called by drivers that supply structured exception handlers to handle particular errors that occur while they are processing I/O requests.

## Parameters

### `Status` [in]

Specifies one of the system-defined STATUS_*XXX* values.

## Remarks

Highest-level drivers, particularly file systems, can call **ExRaiseStatus**.

## See also

[ExRaiseAccessViolation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exraiseaccessviolation)

[ExRaiseDatatypeMisalignment](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exraisedatatypemisalignment)

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[KeBugCheckEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kebugcheckex)