# PFND3D12DDI_ALLOCATE_CB_0022 callback function

## Description

The *pfnAllocateCb* callback function controls heap allocation by using a [D3D12DDICB_ALLOCATE_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_allocate_0022) value.

## Parameters

### `unnamedParam1`

The handle for a device.

### `unnamedParam2`

A [D3D12DDICB_ALLOCATE_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_allocate_0022) structure that contains information for an allocation.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Access this callback function by using the [D3D12DDI_CORELAYER_DEVICECALLBACKS_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_corelayer_devicecallbacks_0022) structure.

The driver must check the return value of the function.

## See also

[D3D12DDICB_ALLOCATE_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_allocate_0022)

[D3D12DDI_CORELAYER_DEVICECALLBACKS_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_corelayer_devicecallbacks_0022)

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_deallocate_cb_0022)