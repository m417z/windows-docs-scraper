# D3D10_TEX2D_ARRAY_RTV structure

## Description

Specifies the [subresource(s)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from an array of [2D textures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to use in a render-target view.

## Members

### `MipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the mipmap level to use (see [mip slice](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types)).

### `FirstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first texture to use in an array of textures (see [array slice](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types))

### `ArraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of textures in the array to use in the render target view, starting from **FirstArraySlice**.

## Remarks

This structure is one member of a render-target-view description (see [D3D10_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_render_target_view_desc)).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)