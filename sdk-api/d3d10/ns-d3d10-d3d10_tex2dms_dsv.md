# D3D10_TEX2DMS_DSV structure

## Description

Specifies the [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from a multisampled [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) that is accessible to a depth-stencil view.

## Members

### `UnusedField_NothingToDefine`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Unused.

## Remarks

Since a multisampled 2D texture contains a single subtexture, there is nothing to specify; this unused member is included so that this structure will compile in C.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)