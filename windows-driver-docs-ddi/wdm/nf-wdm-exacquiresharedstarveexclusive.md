# ExAcquireSharedStarveExclusive function

## Description

The **ExAcquireSharedStarveExclusive** routine acquires a given resource for shared access without waiting for any pending attempts to acquire exclusive access to the same resource.

## Parameters

### `Resource` [in, out]

A pointer to the resource to be acquired for shared access.

### `Wait` [in]

Specifies the routine's behavior whenever the resource cannot be acquired immediately. If **TRUE**, the caller is put into a wait state until the resource can be acquired. If **FALSE**, the routine immediately returns, regardless of whether the resource can be acquired.

## Return value

**ExAcquireSharedStarveExclusive** returns **TRUE** if the requested access is granted. This routine returns **FALSE** if the input *Wait* is **FALSE** and shared access cannot be granted immediately.

## Remarks

Whether or when the caller is given shared access to the given resource depends on the following:

* If the resource is currently unowned, shared access is granted immediately to the current thread.
* If the caller already has acquired the resource (for shared or exclusive access), the current thread is granted the same type of access recursively. Note that making this call does not convert a caller's exclusive access of a given resource to shared access.
* If the resource is currently owned as shared by another thread, shared access is granted to the caller immediately, even if another thread is waiting for exclusive access to that resource.
* If the resource is currently owned as exclusive by another thread, the caller either is put into a wait state (*Wait* set to **TRUE**) or **ExAcquireSharedStarveExclusive** returns **FALSE**.

Callers of **ExAcquireSharedStarveExclusive** usually need quick access to a shared resource in order to save an exclusive accessor from doing redundant work. For example, a file system might call this routine to modify a cached resource, such as a BCB pinned in the cache, before the cache manager can acquire exclusive access to the resource and write the cache out to disk.

Normal kernel APC delivery must be disabled before calling this routine. Disable normal kernel APC delivery by calling [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion). Delivery must remain disabled until the resource is released, at which point it can be reenabled by calling [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion). For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

The caller can release the resource by calling either [ExReleaseResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite) or [ExReleaseResourceForThreadLite](https://learn.microsoft.com/previous-versions/ff545585(v=vs.85)).

## See also

[ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/previous-versions/ff544370(v=vs.85))

[ExConvertExclusiveToSharedLite](https://learn.microsoft.com/previous-versions/ff544558(v=vs.85))

[ExGetExclusiveWaiterCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetexclusivewaitercount)

[ExIsResourceAcquiredExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredexclusivelite)

[ExIsResourceAcquiredSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredsharedlite)