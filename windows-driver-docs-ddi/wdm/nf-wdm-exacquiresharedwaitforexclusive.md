# ExAcquireSharedWaitForExclusive function

## Description

The **ExAcquireSharedWaitForExclusive** routine acquires the given resource for shared access if shared access can be granted and there are no exclusive waiters.

## Parameters

### `Resource` [in, out]

A pointer to the resource to be acquired for shared access.

### `Wait` [in]

Specifies the routine's behavior whenever the resource cannot be acquired immediately. If **TRUE**, the caller is put into a wait state until the resource can be acquired. If **FALSE**, the routine immediately returns, regardless of whether the resource can be acquired.

## Return value

**ExAcquireSharedWaitForExclusive** returns **TRUE** if the requested access is granted or an exclusive owner releases the resource. This routine returns **FALSE** if the input *Wait* is **FALSE** and shared access cannot be granted immediately.

## Remarks

Most drivers should use [ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85)) instead of **ExAcquireSharedWaitForExclusive**.

The caller can release the resource by calling either [ExReleaseResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite) or [ExReleaseResourceForThreadLite](https://learn.microsoft.com/previous-versions/ff545585(v=vs.85)).

If shared access cannot be granted immediately, the caller can wait for other threads to acquire and release exclusive ownership of the resource.

Whether or when the caller is given shared access to the given resource depends on the following:

* If the resource is currently unowned, shared access is granted immediately to the current thread.
* If the caller already has exclusive access to the resource, the current thread is granted the same type of access recursively.
* If the resource is currently owned as shared and there are no pending attempts to acquire exclusive access, shared access is granted to the caller immediately.
* If the resource is currently owned as shared but there is a pending attempt to acquire exclusive access, the caller either is put into a wait state (*Wait* set to **TRUE**) or **ExAcquireSharedWaitForExclusive** returns **FALSE**.

  When the current thread waits to acquire the resource until after a pending exclusive ownership has been released, **ExAcquireSharedWaitForExclusive** returns **TRUE** when the current thread is granted shared access to the resource and resumes execution.

The behavior of **ExAcquireSharedWaitForExclusive** is identical to that of [ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85)) unless the calling thread already owns the resource as shared and there are exclusive waiters. In that case, **ExAcquireSharedWaitForExclusive** allows the exclusive waiters to acquire exclusive ownership of the resource.

If the caller specifies **TRUE** for the *Wait* parameter, the caller blocks until another thread frees the resource on behalf of the caller, using [ExReleaseResourceForThread](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl). Driver writers must be careful to ensure that another thread actually releases the resource; otherwise the caller is deadlocked. **ExAcquireResourceSharedLite** does not have this property, so drivers should use that routine unless they require the particular behavior of **ExAcquireSharedWaitForExclusive**.

Normal kernel APC delivery must be disabled before calling this routine. Disable normal kernel APC delivery by calling [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion). Delivery must remain disabled until the resource is released, at which point it can be reenabled by calling [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion). For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

## See also

[ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/previous-versions/ff544367(v=vs.85))

[ExConvertExclusiveToSharedLite](https://learn.microsoft.com/previous-versions/ff544558(v=vs.85))

[ExGetExclusiveWaiterCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetexclusivewaitercount)

[ExIsResourceAcquiredExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredexclusivelite)

[ExIsResourceAcquiredSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredsharedlite)

[ExReleaseResourceForThread](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)