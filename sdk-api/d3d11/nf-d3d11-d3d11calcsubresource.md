# D3D11CalcSubresource function

## Description

Calculates a subresource index for a texture.

## Parameters

### `MipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index for the mipmap level to address; 0 indicates the first, most detailed mipmap level.

### `ArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index for the array level to address; always use 0 for volume (3D) textures.

### `MipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of mipmap levels in the resource.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index which equals MipSlice + (ArraySlice * MipLevels).

## Remarks

A buffer is an unstructured resource and is therefore defined as containing a single subresource. APIs that take buffers do not need a subresource index.
A texture on the other hand is highly structured. Each texture object may contain one or more subresources depending on the size of the array and the
number of mipmap levels.

For volume (3D) textures, all slices for a given mipmap level are a single subresource index.

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-functions)

[Resource Functions](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-functions)