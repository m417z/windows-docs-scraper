# D3D12DDI_DEALLOCATE_FLAGS_0022 enumeration

## Description

The **D3D12DDI_DEALLOCATE_FLAGS_0022** enumeration contains bit-wise flags for the runtime's [**pfnDeallocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_deallocate_cb_0022) callback function.

## Constants

### `D3D12DDI_DEALLOCATE_FLAGS_0022_NONE:0x0`

No flags are specified.

### `D3D12DDI_DEALLOCATE_FLAGS_0022_ASSUME_NOT_IN_USE:0x1`

Assume that the allocation is not in use.

### `D3D12DDI_DEALLOCATE_FLAGS_0022_SYNCHRONOUS_DESTROY:0x2`

Ensure that the resource is destroyed synchronously.

## Remarks

The UMD provides these flags when it calls the runtime's [**pfnDeallocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_deallocate_cb_0022) callback to deallocate resources.

## See also

[**D3D12DDICB_DEALLOCATE_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_deallocate_0022)

[**pfnDeallocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_deallocate_cb_0022)