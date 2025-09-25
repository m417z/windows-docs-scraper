# D3D10CalcSubresource function

## Description

Calculate a [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) index for a texture.

## Parameters

### `MipSlice` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index into an array of subtextures; 0 indicates the first, most detailed subtexture (or mipmap level).

### `ArraySlice` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the first texture to use (in an array of textures).

### `MipLevels` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of mipmap levels (or subtextures) to use.

## Return value

Type: **inline UINT**

The index which equals *MipSlice* + (*ArraySlice* * *MipLevels*).

## Remarks

A buffer is an unstructured resource and is therefore defined as containing a single subresource. APIs that take buffers do not need a subresource index. A texture on the other hand is highly structured. Each texture object may contain one or more subresources depending on the size of the array and the number of mipmap levels.

## See also

[Core Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-functions)

[Resource Functions](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-functions)