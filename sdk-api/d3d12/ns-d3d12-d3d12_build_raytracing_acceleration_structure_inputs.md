# D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS structure

## Description

Defines the inputs for a raytracing acceleration structure build operation. This structure is used by [ID3D12GraphicsCommandList4::BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-buildraytracingaccelerationstructure) and [ID3D12Device5::GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-getraytracingaccelerationstructureprebuildinfo).

## Members

### `Type`

The type of acceleration structure to build.

### `Flags`

The build flags.

### `NumDescs`

If *Type* is **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TOP_LEVEL**, this value is the number of instances, laid out based on *DescsLayout*.

If *Type* is **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BOTTOM_LEVEL**, this value is the number of elements referred to by *pGeometryDescs* or *ppGeometryDescs*. Which of these fields is used depends on *DescsLayout*.

### `DescsLayout`

How geometry descriptions are specified; either an array of descriptions or an array of pointers to descriptions.

### `InstanceDescs`

If *Type* is **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TOP_LEVEL**, this refers to *NumDescs*[D3D12_RAYTRACING_INSTANCE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_instance_desc) structures in GPU memory describing instances. Each instance must be aligned to 16 bytes, defined as [D3D12_RAYTRACING_INSTANCE_DESC_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

If *Type* is not **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TOP_LEVEL**, this parameter is unused.

If *DescLayout* is **D3D12_ELEMENTS_LAYOUT_ARRAY**, *InstanceDescs* points to an array of instance descriptions in GPU memory.

If *DescLayout* is **D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS**, *InstanceDescs* points to an array in GPU memory of [D3D12_GPU_VIRTUAL_ADDRESS](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12_gpu_virtual_address) pointers to instance descriptions.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

### `pGeometryDescs`

If *Type* is **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BOTTOM_LEVEL**, and *DescsLayout* is **D3D12_ELEMENTS_LAYOUT_ARRAY**, this field is used and points to *NumDescs* contiguous **D3D12_RAYTRACING_GEOMETRY_DESC** structures on the CPU, describing individual geometries.

If *Type* is not **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BOTTOM_LEVEL** or *DescsLayout* is not **D3D12_ELEMENTS_LAYOUT_ARRAY**, this parameter is unused.

### `ppGeometryDescs`

If *Type* is **D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BOTTOM_LEVEL**, and *DescsLayout* is **D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS**, this field is used and points to an array of *NumDescs* pointers to [D3D12_RAYTRACING_GEOMETRY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_desc) structures on the CPU, describing individual geometries.

## Remarks

When used with [GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-getraytracingaccelerationstructureprebuildinfo), which actually perform a build, any parameter that is referenced via [D3D12_GPU_VIRTUAL_ADDRESS](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12_gpu_virtual_address) (an address in GPU memory), like *InstanceDescs*, will not be accessed by the operation. So this memory does not need to be initialized yet or be in a particular resource state. Whether GPU addresses are null or not can be inspected by the operation, even though the pointers are not dereferenced.