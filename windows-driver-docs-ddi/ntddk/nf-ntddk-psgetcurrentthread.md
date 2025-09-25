# PsGetCurrentThread function (ntddk.h)

## Description

The **PsGetCurrentThread** routine identifies the current thread.

## Return value

**PsGetCurrentThread** returns a pointer to the executive thread object that represents the currently executing thread.

## Remarks

You can use the **ExGetCurrentResourceThread** macro to return the thread ID of the current thread.

`#define ExGetCurrentResourceThread() ((ULONG_PTR)PsGetCurrentThread())`

## See also

[**ExSetResourceOwnerPointerEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsetresourceownerpointerex)

[**ExReleaseResourceForThreadLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceforthreadlite)

[KeGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)

[PsCreateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread)

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[PsGetCurrentProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid)

[PsIsSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psissystemthread)