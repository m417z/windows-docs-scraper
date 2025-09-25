# D3D10_TEX2D_RTV structure

## Description

Specifies the [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from a [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to use in a render-target view.

## Members

### `MipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the mipmap level to use (see [mip slice](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types)).

## Remarks

This structure is one member of a render-target-view description (see [D3D10_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_render_target_view_desc)).

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)