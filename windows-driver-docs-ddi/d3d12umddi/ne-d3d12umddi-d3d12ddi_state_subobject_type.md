# D3D12DDI_STATE_SUBOBJECT_TYPE enumeration

## Description

The **D3D12DDI_STATE_SUBOBJECT_TYPE** enumeration specifies the supported subobject types within a Direct3D12 state object. The structure that [**D3D12DDI_STATE_SUBOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054)'s **pDesc** member points to is determined by the **D3D12DDI_STATE_SUBOBJECT_TYPE** enumeration value specified in its **Type** member.

## Constants

### `D3D12DDI_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG`

The configuration state of the subobject.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE`

The global root signatures.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:2`

The local root signatures.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_NODE_MASK`

The node mask.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY`

The DXIL (DirectX Intermediate Language) library.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION`

The existing collection.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG`

The ray tracing shader configuration.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG`

The ray tracing pipeline configuration.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_HIT_GROUP`

The HIT group configuration. A hit group is one or more shaders consisting of:

* 0 or 1 intersection shader
* 0 or 1 any hit shader
* 0 or 1 closest hit shader

### `D3D12DDI_STATE_SUBOBJECT_TYPE_WORK_GRAPH`

Subobject type is a work graph; **pDesc** points to a [**D3D12DDI_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_desc_0108) structure.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT`

Subobject type is stream output.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_BLEND`

Subject type is blend.

### `D3D12DDI_STATE_SUBOBJECT_TYPE_SAMPLE_MASK`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_RASTERIZER`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT`

### - D3D12DDI_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE

### `D3D12DDI_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS`

### - D3D12DDI_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT

### `D3D12DDI_STATE_SUBOBJECT_TYPE_SAMPLE_DESC`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_FLAGS`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_GENERIC_PROGRAM`

### `D3D12DDI_STATE_SUBOBJECT_TYPE_SHADER_EXPORT_SUMMARY`

The export summary configuration.

## Remarks

State objects have a type that dictates rules about the subobjects they contain and how the state objects can be used.

## See also

[**D3D12DDI_STATE_OBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_state_object_type)

[**D3D12DDI_STATE_SUBOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_subobject_0054)

[**PFND3D12DDI_CREATE_STATE_OBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054)