# KeRevertToUserGroupAffinityThread function

## Description

The **KeRevertToUserGroupAffinityThread** routine restores the group affinity of the calling thread to its original value at the time that the thread was created.

## Parameters

### `PreviousAffinity` [in]

A pointer to the group affinity to restore. This parameter points to a [GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) structure that contains a group number and an affinity mask. The affinity mask specifies the set of logical processors that the user thread can run on.

## Remarks

This routine changes the group number and group-relative affinity mask of the calling thread. The group number and affinity mask identify a set of processors on which the thread can run. If successful, the routine schedules the thread to run on a processor in this set.

The *PreviousAffinity* parameter points to a **GROUP_AFFINITY** structure that specifies the new group number (**Group** member) and affinity mask (**Mask** member) for the thread. If *PreviousAffinity*->**Mask** is nonzero, **KeRevertToUserGroupAffinityThread** sets the group number and affinity mask of the calling thread to the values in the structure. If *PreviousAffinity*->**Mask** is zero, the routine restores the group number and affinity mask to their original values at the time that the thread was initialized.

A process can have affinity for more than one group at a time. However, a thread can be assigned to only one group at any time, and that group is always in the affinity of the thread's process.

A thread can change the group to which it is assigned by calling the [KeSetSystemGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemgroupaffinitythread) routine. Following one or more calls to **KeSetSystemGroupAffinityThread**, the thread can restore the original group affinity that it had when the thread was created by calling **KeRevertToUserGroupAffinityThread**.

After the thread is created, a call to **KeRevertToUserGroupAffinityThread** has no effect (that is, the group number and affinity mask of the thread remain unchanged) unless the thread first calls **KeSetSystemGroupAffinityThread**. Following a call to **KeRevertToUserGroupAffinityThread**, a second call to **KeRevertToUserGroupAffinityThread** has no effect unless the thread first calls **KeSetSystemGroupAffinityThread**.

The routine changes the group number and affinity mask to the values that are specified in **PreviousAffinity* only if the following are true:

* The group number is valid.
* The affinity mask is valid (that is, only mask bits that correspond to logical processors in the group are set).
* At least one of the processors that is specified in the affinity mask is active.

If any of these conditions is not met, the call to **KeRevertToUserGroupAffinityThread** has no effect.

A related routine, [KeRevertToUserAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttouseraffinitythreadex), changes the affinity mask of the calling thread, but this routine, unlike **KeRevertToUserGroupAffinityThread**, does not accept a group number as an input parameter. In Windows 7 and later versions of the Windows operating system, **KeRevertToUserAffinityThreadEx** assumes that the affinity mask refers to processors in group 0, which is compatible with the behavior of this routine in earlier versions of Windows that do not support groups. This behavior ensures that existing drivers that call **KeRevertToUserAffinityThreadEx** and that use no group-oriented features will run correctly in multiprocessor systems that have two or more groups. However, drivers that use any group-oriented features in Windows 7 and later versions of the Windows operating system should call **KeRevertToUserGroupAffinityThread** instead of **KeRevertToUserAffinityThreadEx**.

If **KeRevertToUserGroupAffinityThread** is called at IRQL <= APC_LEVEL and the call is successful, the new (reverted) group affinity takes effect immediately. When the call returns, the calling thread is already running on a processor that is specified in the new group affinity. If **KeRevertToUserGroupAffinityThread** is called at IRQL = DISPATCH_LEVEL and the call is successful, the pending processor change is deferred until the caller lowers the IRQL below DISPATCH_LEVEL.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)

[KeRevertToUserAffinityThreadEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereverttouseraffinitythreadex)

[KeSetSystemGroupAffinityThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetsystemgroupaffinitythread)