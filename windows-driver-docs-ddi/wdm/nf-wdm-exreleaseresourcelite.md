# ExReleaseResourceLite function

## Description

The **ExReleaseResourceLite** routine releases a specified executive resource owned by the current thread.

## Parameters

### `Resource` [in, out]

A pointer to an executive resource owned by the current thread.

## Remarks

Normal kernel APC delivery must be disabled before calling this routine. Disable normal kernel APC delivery by calling [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion). Delivery must remain disabled until the resource is released, at which point it can be reenabled by calling [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion). For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

## See also

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourceexclusivelite)

[ExAcquireResourceSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourcesharedlite)

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedstarveexclusive)

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedwaitforexclusive)

[ExGetCurrentResourceThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[ExReinitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite)

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceforthreadlite)