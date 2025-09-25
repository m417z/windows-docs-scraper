## Description

The **DXGK_ALLOCATIONINFOFLAGS2** structure contains additional properties for an allocation.

## Members

### `ShareBackingStoreWithKmd`

When set, the kernel-mode driver (KMD) is notifying *Dxgkrnl* that it needs to know the address of the allocation backing store. The allocation must be created shared and must reside only in the aperture memory segment.

### `NoImplicitSynchronization`

When set, KMD is opting out of implicit primary synchronization. This flag was introduced in Windows 11, version 24H2 (WDDM 3.2).

### `DisablePartialResidency`

When set, indicates that the allocation doesn't support partial residency. The allocation must either be entirely evicted or entirely resident. This flag was introduced in Windows 11, version 24H2 (WDDM 3.2).

### `RestrictedToSingleSegment`

When set, indicates that the allocation doesn't support cross-segment residency. The allocation must be entirely resident within a single segment. This flag was introduced in Windows 11, version 24H2 (WDDM 3.2).

### `NotifyEviction`

When set, indicates that *Dxgkrnl* should issue a [**DXGK_OPERATION_NOTIFY_ALLOC NotifyEviction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation) operation to KMD before evicting an allocation. This flag was introduced in Windows 11, version 24H2 (WDDM 3.2). For more information, see [Allocation notification](https://learn.microsoft.com/windows-hardware/drivers/display/allocation-notification).

### `NotifyIoMmuUnmap`

When set, indicates that *Dxgkrnl* should issue a [**DXGK_OPERATION_NOTIFY_ALLOC NotifyIoMmuUnmap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation) operation to KMD before unmapping an allocation from the IOMMU. This flag was introduced in Windows 11, version 24H2 (WDDM 3.2). For more information, see [Allocation notification](https://learn.microsoft.com/windows-hardware/drivers/display/allocation-notification).

### `Reserved`

Reserved; do not use.

### `Value`

An alternative way to access the bits of this structure.

## Remarks

## See also

[**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[**DXGKDDI_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)