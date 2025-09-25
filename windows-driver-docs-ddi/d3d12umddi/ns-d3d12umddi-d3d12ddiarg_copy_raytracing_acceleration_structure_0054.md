# D3D12DDIARG_COPY_RAYTRACING_ACCELERATION_STRUCTURE_0054 structure

## Description

Arguments used in the [CopyRayTracingAccelerationStructure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_copy_raytracing_acceleration_structure_0054) callback function.

## Members

### `DestAccelerationStructureData`

Destination memory. The required size can be discovered by calling [EmitRaytracingAccelerationStructurePostBuildInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_emit_raytracing_acceleration_structure_postbuild_info_0054) beforehand, if necessary, depending on the *Mode*.

Destination start address must be 256 byte aligned, regardless of the *Mode*.

Destination memory range cannot overlap source otherwise results are undefined.

The resource state that the memory pointed to must be dependent on the *Mode* parameter. See [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_copy_mode).

### `SourceAccelerationStructureData`

Acceleration structure to copy or transform based on the specified *Mode*. The source acceleration structure remains unchanged and still usable. The operation only involves the source acceleration structure directly specified and not others it may point to. For example, in the case of a top-level acceleration structure, any bottom-level acceleration structures that it points to are not involved in the operation.

The resource state that the memory pointed to must be dependent on the *Mode* parameter. See [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_copy_mode).

### `Mode`

Type of copy operation to perform.

## Remarks

## See also