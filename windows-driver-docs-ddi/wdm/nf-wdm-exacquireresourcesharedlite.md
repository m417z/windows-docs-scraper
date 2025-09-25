# ExAcquireResourceSharedLite function

## Description

The **ExAcquireResourceSharedLite** routine acquires the given resource for shared access by the calling thread.

## Parameters

### `Resource` [in, out]

A pointer to the resource to acquire.

### `Wait` [in]

Specifies the routine's behavior whenever the resource cannot be acquired immediately. If **TRUE**, the caller is put into a wait state until the resource can be acquired. If **FALSE**, the routine immediately returns, regardless of whether the resource can be acquired.

## Return value

The caller can release the resource by calling either [ExReleaseResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite) or [ExReleaseResourceForThreadLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceforthreadlite).

**ExAcquireResourceSharedLite** returns **TRUE** if (or when) the resource is acquired. This routine returns **FALSE** if the input *Wait* is **FALSE** and shared access cannot be granted immediately.

## Remarks

Whether or when the caller is given shared access to the given resource depends on the following:

* If the resource is currently unowned, shared access is granted immediately to the current thread.

* If the caller already has acquired the resource (for shared or exclusive access), the current thread is granted the same type of access recursively. Note that making this call does not convert a caller's exclusive access of a given resource to shared access.

* If the resource is currently owned as shared by another thread and no thread is waiting for exclusive access to the resource, shared access is granted to the caller immediately. The caller is put into a wait state if there is an exclusive waiter.

* If the resource is currently owned as exclusive by another thread or if there is another thread waiting for exclusive access and the caller does not already have shared access to the resource, the current thread either is put into a wait state (*Wait* set to **TRUE**) or **ExAcquireResourceSharedLite** returns **FALSE**.

Normal kernel APC delivery must be disabled before calling this routine. Disable normal kernel APC delivery by calling [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion). Delivery must remain disabled until the resource is released, at which point it can be reenabled by calling [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion). For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

## See also

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourceexclusivelite)

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedstarveexclusive)

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedwaitforexclusive)

[ExConvertExclusiveToSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exconvertexclusivetosharedlite)

[ExGetExclusiveWaiterCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetexclusivewaitercount)

[ExGetSharedWaiterCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetsharedwaitercount)

[ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[ExIsResourceAcquiredSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredsharedlite)

[ExReinitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite)

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceforthreadlite)