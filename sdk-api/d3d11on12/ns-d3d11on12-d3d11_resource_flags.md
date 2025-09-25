# D3D11_RESOURCE_FLAGS structure

## Description

Used with [ID3D11On12Device::CreateWrappedResource](https://learn.microsoft.com/windows/desktop/api/d3d11on12/nf-d3d11on12-id3d11on12device-createwrappedresource) to override flags that would be inferred by the resource properties or heap properties, including bind flags, misc flags, and CPU access flags.

## Members

### `BindFlags`

Bind flags must be either completely inferred, or completely specified, to allow the graphics driver to scope a general D3D12 resource to something that D3D11 can understand.

If a bind flag is specified which is not supported by the provided resource, an error will be returned.

The following bind flags ([D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) enumeration constants) will not be assumed, and must be specified in order for a resource to be used in such a fashion:

* D3D11_BIND_VERTEX_BUFFER
* D3D11_BIND_INDEX_BUFFER
* D3D11_BIND_CONSTANT_BUFFER
* D3D11_BIND_STREAM_OUTPUT
* D3D11_BIND_DECODER
* D3D11_BIND_VIDEO_ENCODER

The following bind flags will be assumed based on the presence of the corresponding D3D12 resource flag, and can be removed by specifying bind flags:

* D3D11_BIND_SHADER_RESOURCE, as long as D3D12_RESOURCE_MISC_DENY_SHADER_RESOURCE is not present
* D3D11_BIND_RENDER_TARGET, if D3D12_RESOURCE_MISC_ALLOW_RENDER_TARGET is present
* D3D11_BIND_DEPTH_STENCIL, if D3D12_RESOURCE_MISC_ALLOW_DEPTH_STENCIL is present
* D3D11_BIND_UNORDERED_ACCESS, if D3D12_RESOURCE_MISC_ALLOW_UNORDERED_ACCESS is present

A render target or UAV buffer can be wrapped without overriding flags; but a VB/IB/CB/SO buffer must have bind flags manually specified, since these are mutually exclusive in Direct3D 11.

### `MiscFlags`

If misc flags are nonzero, then any specified flags will be OR’d into the final resource desc with inferred flags.
Misc flags can be partially specified in order to add functionality, but misc flags which are implied cannot be masked out.

The following misc flags ([D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) enumeration constants) will not be assumed:

* D3D11_RESOURCE_MISC_GENERATE_MIPS (conflicts with CLAMP).
* D3D11_RESOURCE_MISC_TEXTURECUBE (alters default view behavior).
* D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS (exclusive with some bind flags).
* D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS (exclusive with other types of UAVs).
* D3D11_RESOURCE_MISC_BUFFER_STRUCTURED (exclusive with other types of UAVs).
* D3D11_RESOURCE_MISC_RESOURCE_CLAMP (prohibits D3D10 QIs, conflicts with GENERATE_MIPS).
* D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX. It is possible to create a D3D11 keyed mutex resource, create a shared handle for it, and open it via 11on12 or D3D11.

The following misc flags will be assumed, and cannot be removed from the produced resource desc.
If one of these is set, and the D3D12 resource does not support it, creation will fail:

* D3D11_RESOURCE_MISC_SHARED, D3D11_RESOURCE_MISC_SHARED_NTHANDLE, D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE, if appropriate heap misc flags are present.
* D3D11_RESOURCE_MISC_GDI_COMPATIBLE, if D3D12 resource is GDI-compatible.
* D3D11_RESOURCE_MISC_TILED, if D3D12 resource was created via [CreateReservedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createreservedresource).
* D3D11_RESOURCE_MISC_TILE_POOL, if a D3D12 heap was passed in.

The following misc flags are invalid to specify for this API:

* D3D11_RESOURCE_MISC_RESTRICTED_CONTENT, since D3D12 only supports hardware protection.
* D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER does not exist in 12, and cannot be added in after resource creation.
* D3D11_RESOURCE_MISC_GUARDED is only meant to be set by an internal creation mechanism.

### `CPUAccessFlags`

The **CPUAccessFlags** are not inferred from the D3D12 resource.
This is because all resources are treated as D3D11_USAGE_DEFAULT, so **CPUAccessFlags** force validation which assumes [Map](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-map) of default buffers or textures.
Wrapped resources do not support **Map(DISCARD)**.
Wrapped resources do not support **Map(NO_OVERWRITE)**, but that can be implemented by mapping the underlying D3D12 resource instead.
Issuing a **Map** call on a wrapped resource will synchronize with all D3D11 work submitted against that resource, unless the DO_NOT_WAIT flag was used.

### `StructureByteStride`

The size of each element in the buffer structure (in bytes) when the buffer represents a structured buffer.

## Remarks

Use this structure with [CreateWrappedResource](https://learn.microsoft.com/windows/desktop/api/d3d11on12/nf-d3d11on12-id3d11on12device-createwrappedresource).

## See also

[11on12 Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-11on12-structures)