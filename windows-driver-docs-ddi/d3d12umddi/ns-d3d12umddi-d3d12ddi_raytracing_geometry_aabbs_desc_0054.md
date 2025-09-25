# D3D12DDI_RAYTRACING_GEOMETRY_AABBS_DESC_0054 structure

## Description

Describes a ray tracing AABB (axis-aligned bounding box) geometry.

## Members

### `AABBCount`

The number of AABBs pointed to in the contiguous array at AABBs.

### `AABBs`

A [D3D12DDI_GPU_VIRTUAL_ADDRESS_AND_STRIDE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_gpu_virtual_address_and_stride) structure describing the GPU memory location where an array of AABB descriptions is to be found, including the data stride between AABBs. The address and stride must each be aligned to 4 bytes. The stride can be 0. The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.

## Remarks

## See also