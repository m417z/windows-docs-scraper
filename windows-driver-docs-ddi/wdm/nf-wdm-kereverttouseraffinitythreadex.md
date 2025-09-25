# KeRevertToUserAffinityThreadEx function

## Description

The **KeRevertToUserAffinityThreadEx** routine restores the previous affinity of the current thread.

## Parameters

### `Affinity` [in]

A [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed variable that specifies the new system affinity of the current thread. Set this parameter to the value that was returned by a previous call to the [KeSetSystemAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythreadex) routine.

## Remarks

**KeRevertToUserAffinityThreadEx** changes the affinity of the current thread. The affinity value is a mask that identifies a set of processors on which the thread can run. If successful, the routine schedules the thread to run on a processor in this set.

If the *Affinity* value is nonzero, **KeRevertToUserAffinityThreadEx** sets the affinity mask of the thread to the *Affinity* value. If the *Affinity* value is zero, **KeRevertToUserAffinityThreadEx** restores the original user affinity mask of the thread. This original user affinity mask was saved in the [thread object](https://learn.microsoft.com/windows-hardware/drivers/kernel/thread-objects) by a previous call to [KeSetSystemAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythreadex). A call to **KeRevertToUserAffinityThreadEx** has no effect unless it is preceded by a call to **KeSetSystemAffinityThreadEx**.

If the *Affinity* value is nonzero, the routine changes the affinity mask of the current thread to the *Affinity* value only if both of the following are true:

* The *Affinity* value is valid (that is, only mask bits that correspond to logical processors are set).
* At least one of the processors that is specified in the *Affinity* value is active.

If either of these conditions is not met, the call to **KeRevertToUserAffinityThreadEx** has no effect.

Windows 7 and later versions of Windows support processor groups. Drivers that are designed to handle information about processor groups should use the [KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread) routine, which specifies a processor group, instead of **KeRevertToUserAffinityThreadEx**, which does not. However, the implementation of **KeRevertToUserAffinityThreadEx** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows, which do not support processor groups. In this implementation, a nonzero *Affinity* value is an affinity mask that specifies a set of logical processors in group 0 on which the thread can run. If *Affinity* is zero, the thread reverts to its original user-mode group number and affinity mask.

If **KeRevertToUserAffinityThreadEx** is called at IRQL <= APC_LEVEL and the call is successful, the new (reverted) affinity mask takes effect immediately. When the call returns, the calling thread is already running on a processor that is specified in the new affinity mask. If **KeRevertToUserAffinityThreadEx** is called at IRQL = DISPATCH_LEVEL and the call is successful, the pending processor change is deferred until the caller lowers the IRQL below DISPATCH_LEVEL.

## See also

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread)

[KeSetSystemAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythreadex)