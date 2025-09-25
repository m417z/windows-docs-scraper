# ExIsResourceAcquiredExclusiveLite function

## Description

The **ExIsResourceAcquiredExclusiveLite** routine returns whether the current thread has exclusive access to a given resource.

## Parameters

### `Resource` [in]

A pointer to the resource to be queried.

## Return value

**ExIsResourceAcquiredExclusiveLite** returns **TRUE** if the caller already has exclusive access to the given resource.

## See also

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85))

[ExIsResourceAcquiredSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredsharedlite)