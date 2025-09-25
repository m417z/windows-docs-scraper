# KeSetSystemAffinityThreadEx function

## Description

The **KeSetSystemAffinityThreadEx** routine sets the system affinity of the current thread.

## Parameters

### `Affinity` [in]

A [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed variable that specifies the new system affinity of the current thread.

## Return value

**KeSetSystemAffinityThreadEx** returns either the previous system affinity of the current thread, or zero to indicate that there was no previous system affinity.

## Remarks

**KeSetSystemAffinityThreadEx** changes the affinity mask of the current thread. The affinity mask identifies a set of processors on which the thread can run. If successful, the routine schedules the thread to run on a processor in this set.

Callers of **KeSetSystemAffinityThreadEx** should save the return value and later pass this value to the **KeRevertToUserAffinityThreadEx** routine to restore the previous affinity mask.

In a multiprocessor system, a kernel-mode driver routine that runs in the context of a user-mode thread might need to call **KeSetSystemAffinityThreadEx** to temporarily change the affinity mask of the thread. Before the routine exits, it should call **KeRevertToUserAffinityThreadEx** to restore the affinity mask of the thread to its original value.

The term *user affinity* refers to the original affinity of the user-mode thread. The affinity that is set by the kernel-mode driver is referred to as the *system affinity*. If a call to **KeSetSystemAffinityThreadEx** replaces the user affinity of a thread with a system affinity, the call returns zero. Later, the driver restores the user affinity by calling **KeRevertToUserAffinityThreadEx** and passing this return value (zero) as the *Affinity* value.

Additionally, a kernel-mode driver routine that requires a particular affinity mask might call another kernel-mode routine that requires a different affinity mask. Each routine can call **KeSetSystemAffinityThreadEx** to set a new affinity mask and then call **KeRevertToUserAffinityThreadEx** to restore the previous affinity mask before returning.

The **KeSetSystemAffinityThreadEx** routine changes the affinity mask of the current thread to the *Affinity* value only if both of the following are true:

* The *Affinity* value is valid (that is, only mask bits that correspond to logical processors are set).
* At least one of the processors that is specified in the *Affinity* value is active.

If either of these conditions is not met, the call to **KeSetSystemAffinityThreadEx** has no effect.

Windows 7 and later versions of Windows support processor groups. Drivers that are designed to handle information about processor groups should use the [KeSetSystemGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemgroupaffinitythread) routine, which specifies a processor group, instead of **KeSetSystemAffinityThreadEx**, which does not. However, the implementation of **KeSetSystemAffinityThreadEx** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows, which do not support processor groups. In this implementation, **KeSetSystemAffinityThreadEx** assigns the thread to group 0, and uses the affinity mask to specify a set of logical processors in this group on which the thread can run. The routine returns the previous group-relative affinity mask, but not the previous group.

If **KeSetSystemAffinityThreadEx** is called at IRQL <= APC_LEVEL and the call is successful, the new affinity mask takes effect immediately. When the call returns, the calling thread is already running on a processor that is specified in the new affinity mask. If **KeSetSystemAffinityThreadEx** is called at IRQL = DISPATCH_LEVEL and the call is successful, the pending processor change is deferred until the caller lowers the IRQL below DISPATCH_LEVEL.

## See also

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[KeRevertToUserAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttouseraffinitythreadex)

[KeSetSystemAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythread)

[KeSetSystemGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemgroupaffinitythread)