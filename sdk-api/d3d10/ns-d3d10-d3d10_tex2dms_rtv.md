# D3D10_TEX2DMS_RTV structure

## Description

Specifies the [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) from a multisampled [2D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) to use in a render-target view.

## Members

### `UnusedField_NothingToDefine`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Integer of any value. See remarks.

## Remarks

Since a multisampled 2D texture contains a single subresource, there is actually nothing to specify in **D3D10_TEX2DMS_RTV**. Consequently, **UnusedField_NothingToDefine** is included so that this structure will compile in C.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)