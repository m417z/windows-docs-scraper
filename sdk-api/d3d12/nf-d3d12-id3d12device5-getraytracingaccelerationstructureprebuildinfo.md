## Description

Query the driver for resource requirements to build an acceleration structure.

## Parameters

### `pDesc` [in]

Description of the acceleration structure build. This structure is shared with [BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-buildraytracingaccelerationstructure). For more information, see [D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_build_raytracing_acceleration_structure_inputs).

The implementation is allowed to look at all the CPU parameters in this struct and nested structs. It may not inspect/dereference any GPU virtual addresses, other than to check to see if a pointer is NULL or not, such as the optional transform in [D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_triangles_desc), without dereferencing it. In other words, the calculation of resource requirements for the acceleration structure does not depend on the actual geometry data (such as vertex positions), rather it can only depend on overall properties, such as the number of triangles, number of instances etc.

### `pInfo` [out]

The result of the query (in a [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_prebuild_info) structure).

## Remarks

The input acceleration structure description is the same as what goes into [BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-buildraytracingaccelerationstructure). The result of this function lets the application provide the correct amount of output storage and scratch storage to **BuildRaytracingAccelerationStructure** given the same geometry.

Builds can also be done with the same configuration passed to **GetAccelerationStructurePrebuildInfo** overall except equal or smaller counts for the number of geometries/instances or the number of vertices/indices/AABBs in any given geometry. In this case the storage requirements reported with the original sizes passed to **GetRaytracingAccelerationStructurePrebuildInfo** will be valid – the build may actually consume less space but not more. This is handy for app scenarios where having conservatively large storage allocated for acceleration structures is fine.

This method is on the device interface as opposed to command list on the assumption that drivers must be able to calculate resource requirements for an acceleration structure build from only looking at the CPU-visible portions of the call, without having to dereference any pointers to GPU memory containing actual vertex data, index data, etc.

## See also

[ID3D12Device5](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device5)