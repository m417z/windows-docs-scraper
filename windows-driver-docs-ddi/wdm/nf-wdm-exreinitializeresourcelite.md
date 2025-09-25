# ExReinitializeResourceLite function

## Description

The **ExReinitializeResourceLite** routine reinitializes an existing resource variable.

## Parameters

### `Resource` [in, out]

A pointer to the caller-supplied resource variable to be reinitialized.

## Return value

**ExReinitializeResourceLite** returns STATUS_SUCCESS.

## Remarks

With a single call to **ExReinitializeResource**, a driver writer can replace three calls: one to **ExDeleteResourceLite**, another to **ExAllocatePool**, and a third to **ExInitializeResourceLite**. As contention for a resource variable increases, memory is dynamically allocated and attached to the resource in order to track this contention. As an optimization, **ExReinitializeResourceLite** retains and zeros this previously allocated memory.

The **ERESOURCE** structure is opaque; that is, the members are reserved for system use.

## See also

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85))

[ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/previous-versions/ff544367(v=vs.85))

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/previous-versions/ff544370(v=vs.85))

[ExConvertExclusiveToSharedLite](https://learn.microsoft.com/previous-versions/ff544558(v=vs.85))

[ExDeleteResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeleteresourcelite)

[ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[ExIsResourceAcquiredExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredexclusivelite)

[ExIsResourceAcquiredSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredsharedlite)

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/previous-versions/ff545585(v=vs.85))