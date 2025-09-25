# PFND3D12DDI_ADD_TO_STATE_OBJECT_0072 callback function

## Description

**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072** incrementally adds to an existing state object.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2` [in]

Pointer to a [**D3D12DDIARG_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_add_to_state_object_0072) structure containing subobject(s) to add to a state object.

### `unnamedParam3`

Handle to a state object.

### `unnamedParam4`

Handle to a runtime handle type state object.

## Return value

Returns HRESULT.

## Remarks

A state object is created via [**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054).

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

## See also

[**D3D12DDIARG_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)