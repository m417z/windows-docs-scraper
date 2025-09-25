# D3D12_TEXTURE_COPY_LOCATION structure

## Description

Describes a portion of a texture for the purpose of texture copies.

## Members

### `pResource`

Specifies the resource which will be used for the copy operation.When **Type** is D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT, **pResource** must point to a buffer resource.When **Type** is D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX, **pResource** must point to a texture resource.

### `Type`

Specifies which type of resource location this is: a subresource of a texture, or a description of a texture layout which can be applied to a buffer.
This [D3D12_TEXTURE_COPY_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_copy_type) enum indicates which union member to use.

### `PlacedFootprint`

Specifies a texture layout, with offset, dimensions, and pitches, for the hardware to understand how to treat a section of a buffer resource as a multi-dimensional texture.
To fill-in the correct data for a [CopyTextureRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion) call,
see [D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint).

### `SubresourceIndex`

Specifies the index of the subresource of an arrayed, mip-mapped, or planar texture should be used for the copy operation.

## Remarks

Use this structure with [CopyTextureRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion).

## See also

[CD3DX12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-texture-copy-location)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint)