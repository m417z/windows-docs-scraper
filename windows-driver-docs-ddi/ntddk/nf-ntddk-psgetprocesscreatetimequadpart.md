# PsGetProcessCreateTimeQuadPart function

## Description

The **PsGetProcessCreateTimeQuadPart** routine returns a LONGLONG value that represents the time at which the process was created.

## Parameters

### `Process` [in]

A pointer to the EPROCESS structure that represents the process. Drivers can use the [PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess) and [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) routines to obtain a pointer to the EPROCESS structure for a process.

## Return value

**PsGetProcessCreateTimeQuadPart** returns the process creation time, in 100-nanosecond intervals, since January 1, 1601. The return value is the same as the value that the [KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime) routine returns when the process was created. (Note that if the system time is changed, the value that **PsGetProcessCreateTimeQuadPart** returns is unaffected.)

## See also

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)