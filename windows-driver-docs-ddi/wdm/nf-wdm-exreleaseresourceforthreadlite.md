# ExReleaseResourceForThreadLite function

## Description

The **ExReleaseResourceForThreadLite** routine releases the input resource of the indicated thread.

## Parameters

### `Resource` [in, out]

A pointer to the resource to release.

### `ResourceThreadId` [in]

Identifies the thread that originally acquired the resource. If this is not the currently executing thread, the caller must have transferred ownership of the resource by calling the [ExSetResourceOwnerPointerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsetresourceownerpointerex) routine first on the thread that originally acquired the resource.

## Remarks

If this is not the currently executing thread, the caller must have transferred ownership of the resource by calling the [ExSetResourceOwnerPointerEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsetresourceownerpointerex) routine first on the thread that originally acquired the resource. This is to ensure that thread A does not get terminated or deleted before thread B has a chance to release the resource.

Unless the caller is running in a system thread, the caller must explicitly disable the delivery of normal kernel APCs before calling this routine. This requirement prevents threads from being suspended while they manipulate or hold a resource. The caller can disable normal kernel APC delivery by calling the [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) routine. Delivery must remain disabled until the resource is released, at which point it can be reenabled by calling the [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion) routine. For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

This requirement does not apply to calls made to **ExReleaseResourceForThreadLite** from a system thread. A caller running in a system thread does not need to explicitly disable APCs before calling this routine.

## See also

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourceexclusivelite)

[ExAcquireResourceSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourcesharedlite)

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedstarveexclusive)

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedwaitforexclusive)

[ExGetCurrentResourceThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[ExReinitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite)