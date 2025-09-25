# D3D12_RAYTRACING_GEOMETRY_AABBS_DESC structure

## Description

Describes a set of Axis-aligned bounding boxes that are used in the [D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_build_raytracing_acceleration_structure_inputs) structure to provide input data to a raytracing acceleration structure build operation.

## Members

### `AABBCount`

The number of AABBs pointed to in the contiguous array at *AABBs*.

### `AABBs`

the GPU memory location where an array of AABB descriptions is to be found, including the data stride between AABBs. The address and stride must each be aligned to 8 bytes, defined as The address must be aligned to 16 bytes, defined as  [D3D12_RAYTRACING_AABB_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants). The stride can be 0.