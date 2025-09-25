# ExGetExclusiveWaiterCount function

## Description

The **ExGetExclusiveWaiterCount** routine returns the number of waiters on exclusive access to a given resource.

## Parameters

### `Resource` [in]

A pointer to the resource to be tested.

## Return value

**ExGetExclusiveWaiterCount** returns the number of threads currently waiting to acquire the given resource for exclusive access.

## Remarks

**ExGetExclusiveWaiterCount** can be called to get an estimate of how many other threads might be waiting to modify the data protected by a particular resource variable. The caller cannot assume that the returned value remains constant for any particular interval.

## See also

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85))

[ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/previous-versions/ff544367(v=vs.85))

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/previous-versions/ff544370(v=vs.85))

[ExGetSharedWaiterCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetsharedwaitercount)

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/previous-versions/ff545585(v=vs.85))