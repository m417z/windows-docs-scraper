# D3D12DDIARG_CREATE_STATE_OBJECT_0054 structure

## Description

Arguments used in the [CreateStateObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054) callback function to create a state object.

## Members

### `Type`

The [D3D12DDI_STATE_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_object_type) type.

### `NumSubobjects`

The number of [D3D12DDI_STATE_SUBOBJECT_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054) structures in the *pSubobjects* array.

### `pSubobjects`

Pointer to an array of [D3D12DDI_STATE_SUBOBJECT_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054) structures.

## Remarks

## See also