# KeSetSystemGroupAffinityThread function

## Description

The **KeSetSystemGroupAffinityThread** routine changes the group number and affinity mask of the calling thread.

## Parameters

### `Affinity` [in]

A pointer to a [GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) structure that specifies the new group number and group-relative affinity mask for the calling thread.

### `PreviousAffinity` [out, optional]

A pointer to a caller-allocated **GROUP_AFFINITY** structure into which the routine writes information about the previous group affinity of the calling thread. The caller can later use this pointer as an input parameter to the [KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread) routine to restore the previous thread affinity. Frequently, **KeSetSystemGroupAffinityThread** writes values to this structure that are not valid group affinities but that have special meaning to **KeRevertToUserGroupAffinityThread**. Do not supply pointers to these special values as *Affinity* parameters in subsequent **KeSetSystemGroupAffinityThread** calls.

If necessary, the caller can change the thread affinity more than once by calling **KeSetSystemGroupAffinityThread** multiple times. During the first of these calls, the caller should specify a non-**NULL** value for *PreviousAffinity* so that the original thread affinity can be captured and later restored. However, the later calls to **KeSetSystemGroupAffinityThread** can, as an option, set *PreviousAffinity* = **NULL**. For more information, see Remarks.

## Remarks

This routine changes the group number and group-relative affinity mask of the calling thread. The *Affinity* parameter points to a [GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) structure. The group number and affinity mask in this structure identify a set of processors on which the thread can run. If successful, the routine schedules the thread to run on a processor in this set.

If the *PreviousAffinity* parameter is non-**NULL**, the routine saves information about the previous group affinity, which were in effect at the start of the call, in the **GROUP_AFFINITY** structure that *PreviousAffinity* points to. To restore the previous thread affinity, the caller can supply the pointer to this structure as an input parameter to the [KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread) routine.

In a multiprocessor system, a kernel-mode driver routine that runs in the context of a user-mode thread might need to call **KeSetSystemGroupAffinityThread** to temporarily change the group affinity of the thread. Before the routine exits, it should call **KeRevertToUserGroupAffinityThread** to restore the affinity mask of the thread to its original value.

A process can have affinity for more than one group at a time. However, a thread can be assigned to only one group at any time. That group is always in the affinity of the thread's process. A thread can change the group to which it is assigned by calling **KeSetSystemGroupAffinityThread**.

**KeSetSystemGroupAffinityThread** changes the group number and affinity mask to the values that are specified in **Affinity* only if the following are true:

* The group number is valid.
* The affinity mask is valid (that is, only mask bits that correspond to logical processors in the group are set).
* At least one of the processors that is specified in the affinity mask is active.

If any of these conditions is not met, the group number and affinity mask of the thread remain unchanged. If *PreviousAffinity* is non-**NULL**, the routine writes zero to both the group number and the affinity mask in **PreviousAffinity*.

Additionally, **KeSetSystemGroupAffinityThread** writes zero to both the group number and the affinity mask in **PreviousAffinity* if the previous group affinity was assigned to the thread in user mode. In response to a **GROUP_AFFINITY** structure in which the group number and affinity mask are both zero, **KeRevertToUserGroupAffinityThread** restores the current user-mode thread affinity. If the user-mode thread affinity changes between the **KeSetSystemGroupAffinityThread** and **KeRevertToUserGroupAffinityThread** calls, the most recent user-mode affinity is assigned to the thread. (An application can call a function such as [SetThreadGroupAffinity](https://learn.microsoft.com/windows/win32/api/processtopologyapi/nf-processtopologyapi-setthreadgroupaffinity) to change the user-mode group affinity of a thread.)

Before the new affinity mask in **Affinity* takes effect, **KeSetSystemGroupAffinityThread** removes (sets to zero) any affinity mask bits that correspond to processors that are not currently active. In a subsequent **KeSetSystemGroupAffinityThread** call, the value that the routine writes to **PreviousAffinity* might contain an affinity mask that has been modified in this way.

A related routine, [KeSetSystemAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythreadex), changes the affinity mask of the calling thread, but this routine, unlike **KeSetSystemGroupAffinityThread**, does not accept a group number as an input parameter. Starting with Windows 7, **KeSetSystemAffinityThreadEx** assumes that the affinity mask refers to processors in group 0, which is compatible with the behavior of this routine in earlier versions of Windows that do not support groups. This behavior ensures that existing drivers that call **KeSetSystemAffinityThreadEx** and that use no group-oriented features will run correctly in multiprocessor systems that have two or more groups. However, drivers that use any group-oriented features in Windows 7 and later versions of the Windows operating system should call **KeSetSystemGroupAffinityThread** instead of **KeSetSystemAffinityThreadEx**.

**KeSetSystemGroupAffinityThread** and **KeRevertToUserGroupAffinityThread** support a variety of calling patterns. Two examples are shown in the following diagrams.

The following diagram represents a driver thread that calls **KeSetSystemGroupAffinityThread** three times to change the thread affinity, and then calls **KeRevertToUserGroupAffinityThread** to restore the original thread affinity.

![Diagram illustrating multiple calls to set affinity.](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/images/affinity1.png)

In the preceding diagram, the three boxes labeled "Set affinity" are calls to **KeSetSystemGroupAffinityThread**, and the box labeled "Revert affinity" is a call to **KeRevertToUserGroupAffinityThread**. The first **KeSetSystemGroupAffinityThread** call uses the *PreviousAffinity* output pointer to save the original thread affinity. In the next two calls to **KeSetSystemGroupAffinityThread** (marked with asterisks), the caller sets *PreviousAffinity* to **NULL**. Before the thread exits, it calls **KeRevertToUserGroupAffinityThread** to restore the thread affinity that was saved by the first **KeSetSystemGroupAffinityThread** call.

The following diagram shows a somewhat different calling pattern in which pairs of **KeSetSystemGroupAffinityThread** and **KeRevertToUserGroupAffinityThread** calls are nested. In this diagram, each call to **KeSetSystemGroupAffinityThread** in the driver thread uses the *PreviousAffinity* output parameter to save the previous thread affinity, and each of these calls is paired with a call to **KeRevertToUserGroupAffinityThread** that restores the saved thread affinity.

![Diagram illustrating nested calls to set and restore affinity.](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/images/affinity2.png)

In the preceding diagram, function A in the driver thread calls function B twice. Assume that on entry to function A, the thread still has the affinity assigned to it by the user-mode application. Thus, the **KeSetSystemGroupAffinityThread** call in function A saves the original, user-mode thread affinity. During the first call to function B, the **KeSetSystemGroupAffinityThread** saves the thread affinity assigned by the driver in function A, and the corresponding call to **KeRevertToUserGroupAffinityThread** restores this affinity. After B returns, the **KeRevertToUserGroupAffinityThread** in A restores the original, user-mode thread affinity. During the second call to B, the **KeSetSystemGroupAffinityThread** call saves the original, user-mode thread affinity, and the corresponding call to **KeRevertToUserGroupAffinityThread** restores this affinity. The point of this example is that function B does not need to know whether the caller (function A) changed the thread affinity to a driver-defined value before calling B.

If **KeSetSystemGroupAffinityThread** is called at IRQL <= APC_LEVEL and the call is successful, the new group affinity takes effect immediately. When the call returns, the calling thread is already running on a processor that is specified in the new group affinity. If **KeSetSystemGroupAffinityThread** is called at IRQL = DISPATCH_LEVEL and the call is successful, the pending processor change is deferred until the caller lowers the IRQL below DISPATCH_LEVEL.

Starting with Windows 11 and Windows Server 2022, on a system with more than 64 processors, process and thread affinities span all processors in the system, across all [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups), by default.
In order to set a thread's system group affinity over multiple processor groups, use [PsSetSystemMultipleGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pssetsystemmultiplegroupaffinitythread).

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)

[KeRevertToUserGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttousergroupaffinitythread)

[KeSetSystemAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemaffinitythreadex)

[PsSetSystemMultipleGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pssetsystemmultiplegroupaffinitythread)