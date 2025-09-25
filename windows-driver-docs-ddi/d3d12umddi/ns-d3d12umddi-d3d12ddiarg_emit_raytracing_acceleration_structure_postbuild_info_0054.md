# D3D12DDIARG_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_0054 structure

## Description

Arguments used in the [PFND3D12DDI_EMIT_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_emit_raytracing_acceleration_structure_postbuild_info_0054) callback function.

## Members

### `Desc`

A [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_postbuild_info_desc_0054) structure.

### `NumSourceAccelerationStructures`

Number of pointers to acceleration structure GPUVAs (graphical processing unit virtual address) pointed to by *pSourceAccelerationStructureData*.

This number also affects the destination (output), which will be a contiguous array of *NumSourceAccelerationStructures* output structures, where the type of the structures depends on *InfoType*.

### `pSourceAccelerationStructureData`

Pointer to array of GPUVAs of size *NumSourceAccelerationStructures*. Each GPUVA points to the start of an existing acceleration structure.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE.

## Remarks

## See also