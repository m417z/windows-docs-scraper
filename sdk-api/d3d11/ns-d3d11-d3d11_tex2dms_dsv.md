# D3D11_TEX2DMS_DSV structure

## Description

Specifies the subresource from a multisampled 2D texture that is accessible to a depth-stencil view.

## Members

### `UnusedField_NothingToDefine`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Unused.

## Remarks

Because a multisampled 2D texture contains a single subtexture, there is nothing to specify; this unused member is included so that this structure will compile in C.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)