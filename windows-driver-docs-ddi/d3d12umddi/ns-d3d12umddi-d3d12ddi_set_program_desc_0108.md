## Description

The **D3D12DDI_SET_PROGRAM_DESC_0108** structure describes the program that [**PFND3D12DDI_SET_PROGRAM_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_program_0108) should set on a command list.

## Members

### `Type`

A [**D3D12DDI_PROGRAM_TYPE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_program_type_0108) enumeration that specifies the type of program to set.

### `GenericPipeline`

A [**D3D12DDI_SET_GENERIC_PIPELINE_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_generic_pipeline_desc_0108) structure that describes the generic pipeline to set when **Type** is **D3D12DDI_PROGRAM_TYPE_GENERIC_PIPELINE_0108**.

### `RaytracingPipeline`

A [**D3D12DDI_SET_RAYTRACING_PIPELINE_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_raytracing_pipeline_desc_0108) structure that describes the raytracing pipeline to set when **Type** is **D3D12DDI_PROGRAM_TYPE_RAYTRACING_PIPELINE_0108**. Not currently supported.

### `WorkGraph`

A [**D3D12DDI_SET_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_work_graph_desc_0108) structure that describes the work graph to set when **Type** is **D3D12DDI_PROGRAM_TYPE_WORK_GRAPH_0108**.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_PROGRAM_TYPE_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_program_type_0108)

[**D3D12DDI_SET_GENERIC_PIPELINE_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_generic_pipeline_desc_0108)

[**D3D12DDI_SET_RAYTRACING_PIPELINE_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_raytracing_pipeline_desc_0108)

[**D3D12DDI_SET_WORK_GRAPH_DESC_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_set_work_graph_desc_0108)

[**PFND3D12DDI_SET_PROGRAM_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_program_0108)