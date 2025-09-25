# D3D12DDI_RESOURCE_FLAGS_0003 enumeration

## Description

The **D3D12DDI_RESOURCE_FLAGS_0003** enumeration specifies resource flag values.

## Constants

### `D3D12DDI_RESOURCE_FLAG_0003_NONE:0x0`

No flags are specified.

### `D3D12DDI_RESOURCE_FLAG_0003_RENDER_TARGET:0x1`

When set, allows a render target view to be created for the resource.

### `D3D12DDI_RESOURCE_FLAG_0003_DEPTH_STENCIL:0x2`

When set, allows a depth stencil view to be created for the resource.

### `D3D12DDI_RESOURCE_FLAG_0003_CROSS_ADAPTER:0x4`

When set, allows the resource to be used for cross-adapter data.

### `D3D12DDI_RESOURCE_FLAG_0003_SIMULTANEOUS_ACCESS:0x8`

When set, allows a resource to be accessed simultaneously by multiple different queues, devices, or processes.

### `D3D12DDI_RESOURCE_FLAG_0003_SHADER_RESOURCE:0x10`

When set, allows a shader resource view to be created for the resource.

### `D3D12DDI_RESOURCE_FLAG_0020_VIDEO_DECODE_REFERENCE_ONLY:0x20`

When set, this resource can only be used as a decode reference frame. It can only be written to or read by the video decode operation.

### `D3D12DDI_RESOURCE_FLAG_0020_CONTENT_PROTECTION:0x40`

When set, the resource can be used to support content protection.

### `D3D12DDI_RESOURCE_FLAG_0022_UNORDERED_ACCESS:0x80`

When set, allows unordered access. This value is available as a resource flag for the fallback plans.

### `D3D12DDI_RESOURCE_FLAG_0041_ONLY_NON_RT_DS_TEXTURE_PLACEMENT:0x100`

Not currently used.

### `D3D12DDI_RESOURCE_FLAG_0041_ONLY_RT_DS_TEXTURE_PLACEMENT:0x200`

Not currently used.

### `D3D12DDI_RESOURCE_FLAG_0041_4MB_ALIGNED:0x400`

Not currently used.

### `D3D12DDI_RESOURCE_FLAG_0073_SAMPLER_FEEDBACK:0x800`

When set, allows the resource to be used for sampler feedback.

### `D3D12DDI_RESOURCE_FLAG_0080_VIDEO_ENCODE_REFERENCE_ONLY:0x1000`

When set, this resource can only be used as a video encode reference frame. It can only be written to or read by the video encode operation.

### `D3D12DDI_RESOURCE_FLAG_0088_RAYTRACING_ACCELERATION_STRUCTURE:0x2000`

When set, the resource can be used as an acceleration structure for ray tracing.

## See also

[**D3D12DDIARG_CREATERESOURCE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createresource_0088)