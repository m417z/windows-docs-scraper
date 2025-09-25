## Description

The **ExAcquireResourceExclusiveLite** routine acquires the given resource for exclusive access by the calling thread.

## Parameters

### `Resource` [in, out]

A pointer to the resource to acquire.

### `Wait` [in]

Specifies the routine's behavior whenever the resource cannot be acquired immediately. If **TRUE**, the caller is put into a wait state until the resource can be acquired. If **FALSE**, the routine immediately returns, regardless of whether the resource can be acquired.

## Return value

**ExAcquireResourceExclusiveLite** returns **TRUE** if the resource is acquired. This routine returns **FALSE** if the input *Wait* is **FALSE** and exclusive access cannot be granted immediately.

## Remarks

The following list describes whether and when a caller is given exclusive access to a given resource:

- If the resource is currently not owned, exclusive access is granted immediately to the current thread.

- If the caller already had acquired the resource for exclusive access, the current thread is granted the same type of access recursively.-

- If the caller has shared access to the resource, the caller must release the lock before it attempts to reacquire it exclusively.

- If the resource is currently owned as exclusive by another thread, or if the caller only has shared access to the resource, the current thread is put into a wait state until the resource can be acquired.

If two threads each hold a shared lock on the same resource and both attempt to acquire the lock exclusively without releasing their shared lock, they will deadlock. This means that each thread will wait for the other to release its shared hold on the lock, and neither will release its shared hold until the other does.

The caller can release the resource by calling either [ExReleaseResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite) or [ExReleaseResourceForThreadLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceforthreadlite).

Normal kernel APC delivery must be disabled before calling this routine. Disable normal kernel APC delivery by calling [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion). Delivery must remain disabled until the resource is released, at which point it can be reenabled by calling [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion). For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

## See also

[ExAcquireResourceSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourcesharedlite)

[ExGetExclusiveWaiterCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetexclusivewaitercount)

[ExGetSharedWaiterCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exgetsharedwaitercount)

[ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[ExIsResourceAcquiredExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredexclusivelite)

[ExReinitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite)

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceforthreadlite)

[ExReleaseResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite)

[KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)

[KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion)