# _DXGK_OPENALLOCATIONINFO structure

## Description

The DXGK_OPENALLOCATIONINFO structure contains handles to nondevice-specific and device-specific allocations that the [DxgkDdiOpenAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo) function associates.

## Members

### `hAllocation` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the nondevice-specific allocation that the [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function created. The Microsoft DirectX graphics kernel subsystem (which is part of *Dxgkrnl.sys*) assigned this handle for the allocation.

### `pPrivateDriverData` [in/out]

A pointer to a block of private data that is passed between the user-mode display driver and the display miniport driver. This block of private data is the same allocation-specific data that is passed in the **pPrivateDriverData** member of the [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure in the call to the [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function. The display miniport driver's [DxgkDdiOpenAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo) function can modify this block of private data if the **Create** bit-field flag is set in the **Flags** member of the [DXGKARG_OPENALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_openallocation) structure. The user-mode display driver can access modifications to the block of private data.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the block of private data that **pPrivateDriverData** points to.

### `hDeviceSpecificAllocation` [out]

A handle to the device-specific allocation that corresponds to the non device-specific allocation that **hAllocation** specifies. The display miniport driver must set **hDeviceSpecificAllocation** to a handle value that it can use to refer to its private tracking structure for the allocation.

## See also

[DXGKARG_OPENALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_openallocation)

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiOpenAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_openallocationinfo)