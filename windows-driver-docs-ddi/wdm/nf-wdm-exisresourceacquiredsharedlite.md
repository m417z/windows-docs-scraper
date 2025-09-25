# ExIsResourceAcquiredSharedLite function

## Description

The **ExIsResourceAcquiredSharedLite** routine returns whether the current thread has access (either shared or exclusive) to a given resource.

## Parameters

### `Resource` [in]

A pointer to the resource to be queried.

## Return value

**ExIsResourceAcquiredSharedLite** returns the number of times the caller has acquired the given resource for shared or exclusive access.

## Remarks

The system considers exclusive access to be a subset of shared access. Therefore, a thread that has exclusive access to a resource also has shared access to the resource.

## See also

[ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/previous-versions/ff544367(v=vs.85))

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/previous-versions/ff544370(v=vs.85))

[ExIsResourceAcquiredExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredexclusivelite)