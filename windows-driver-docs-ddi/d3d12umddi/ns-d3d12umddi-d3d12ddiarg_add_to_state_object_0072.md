## Description

Structure used to add subobject(s) to a state object via the [**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072) callback.

## Members

### `Type`

A [**D3D12DDI_STATE_OBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_object_type) value indicating the type of GPU pipeline the state object is to be used with.

### `NumSubobjects`

Number of subobjects in **pSubobjects**.

### `pSubobjects`

Array of [**D3D12DDI_STATE_SUBOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054) structures.

### `StateObjectToGrowFrom`

Handle to the state object to grow from.

## Remarks

See the [DirectX RayTracing (DXR) Specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

## See also

[**D3D12DDI_STATE_OBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_object_type)

[**D3D12DDI_STATE_SUBOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)

[**PFND3D12DDI_CALC_PRIVATE_ADD_TO_STATE_OBJECT_SIZE_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calc_private_add_to_state_object_size_0072)