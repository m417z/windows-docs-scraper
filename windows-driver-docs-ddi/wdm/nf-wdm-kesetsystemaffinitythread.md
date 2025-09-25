# KeSetSystemAffinityThread function

## Description

The **KeSetSystemAffinityThread** routine sets the system affinity of the current thread.

## Parameters

### `Affinity` [in]

A [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed variable that specifies the new system affinity of the current thread.

## Remarks

The implementation of **KeSetSystemAffinityThread** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows, which do not support processor groups. In this implementation, **KeSetSystemAffinityThread** assigns the thread to group 0, and uses the affinity mask to specify a set of logical processors in this group on which the thread can run.

If **KeSetSystemAffinityThread** is called at IRQL <= APC_LEVEL and the call is successful, the new affinity mask takes effect immediately. When the call returns, the calling thread is already running on a processor that is specified in the new affinity mask. If **KeSetSystemAffinityThread** is called at IRQL = DISPATCH_LEVEL and the call is successful, the pending processor change is deferred until the caller lowers the IRQL below DISPATCH_LEVEL.

## See also

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[KeSetSystemAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythreadex)