# ExInitializeResourceLite function

## Description

The **ExInitializeResourceLite** routine initializes a resource variable.

## Parameters

### `Resource` [out]

A pointer to the caller-supplied storage, which must be at least ```sizeof(ERESOURCE)```, for the resource variable being initialized. The storage must be 4-byte aligned on 32-bit platforms, and 8-byte aligned on 64-bit platforms.

## Return value

**ExInitializeResourceLite** returns STATUS_SUCCESS.

## Remarks

The storage for **ERESOURCE** must be allocated from nonpaged pool.

The resource variable can be used for synchronization by a set of threads. Although the caller provides the storage for the resource variable, the **ERESOURCE** structure is opaque; that is, its members are reserved for system use.

Call [**ExDeleteResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeleteresourcelite) before freeing the memory for the resource.

For more information, see [ERESOURCE routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines).

## See also

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourceexclusivelite)

[ExAcquireResourceSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquireresourcesharedlite)

[ExAcquireSharedStarveExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedstarveexclusive)

[ExAcquireSharedWaitForExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquiresharedwaitforexclusive)

[ExConvertExclusiveToSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exconvertexclusivetosharedlite)

[ExDeleteResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeleteresourcelite)

[ExIsResourceAcquiredExclusiveLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredexclusivelite)

[ExIsResourceAcquiredSharedLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exisresourceacquiredsharedlite)

[ExReinitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite)

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourceforthreadlite)