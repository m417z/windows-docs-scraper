# PFND3D12DDI_CALC_PRIVATE_ADD_TO_STATE_OBJECT_SIZE_0072 callback function

## Description

**PFND3D12DDI_CALC_PRIVATE_ADD_TO_STATE_OBJECT_SIZE_0072** calculates the size of the state object.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2` [in]

Pointer to a [**D3D12DDIARG_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_add_to_state_object_0072) structure.

## Return value

Returns the size of the state object in bytes.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_ADD_TO_STATE_OBJECT_SIZE_0072 Pfnd3d12ddiCalcPrivateAddToStateObjectSize0072;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateAddToStateObjectSize0072
(
    D3D12DDI_HDEVICE,
    CONST D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0072*
)
{...}

PFND3D12DDI_CALC_PRIVATE_ADD_TO_STATE_OBJECT_SIZE_0072

```

## Remarks

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

## See also

[**D3D12DDIARG_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_add_to_state_object_0072)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)