# D3D12DDICB_DEALLOCATE_0022 structure

## Description

The **D3D12DDICB_DEALLOCATE_0022** structure contains information needed by the runtime's [**pfnDeallocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_deallocate_cb_0022) callback function to deallocate resources.

## Members

### `hResource`

[in] The handle of the resource to be deallocated.

### `NumAllocations`

[in] The number of allocations in the **HandleList** array to be deallocated.

### `HandleList`

[in] A pointer to an array of handles to be deallocated.

### `Flags`

A [**D3D12DDI_DEALLOCATE_FLAGS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_deallocate_flags_0022) enumeration that specifies flag(s) that the runtime should use when doing the deallocation.

## See also

[**D3D12DDI_DEALLOCATE_FLAGS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_deallocate_flags_0022)

[**pfnDeallocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_deallocate_cb_0022)