# PFND3D12DDI_DEALLOCATE_CB_0022 callback function

## Description

The D3D12 runtime's **pfnDeallocateCb** callback function controls resource deallocation.

## Parameters

### `unnamedParam1`

[in] The handle to the runtime's device.

### `unnamedParam2`

[in] Pointer to a [**D3D12DDICB_DEALLOCATE_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_deallocate_0022) structure that contains information for a deallocation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This callback function is used by the driver to request the Direct3D runtime to allocate resources.

Access this callback function by using the [**D3D12DDI_CORELAYER_DEVICECALLBACKS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_corelayer_devicecallbacks_0022) structure.

The driver must check the return value of the function.

## See also

[**D3D12DDICB_DEALLOCATE_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_deallocate_0022)

[**D3D12DDI_CORELAYER_DEVICECALLBACKS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_corelayer_devicecallbacks_0022)

[**pfnAllocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_allocate_cb_0022)