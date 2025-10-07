# D3DRASTER\_STATUS structure

Describes the raster status.

## Members

**InVBlank**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** if the raster is in the vertical blank period. **FALSE** if the raster is not in the vertical blank period.

**ScanLine**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If InVBlank is **FALSE**, then this value is an integer roughly corresponding to the current scan line painted by the raster. Scan lines are numbered in the same way as Direct3D surface coordinates: 0 is the top of the primary surface, extending to the value (height of the surface - 1) at the bottom of the display.

If InVBlank is **TRUE**, then this value is set to zero and can be ignored.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetRasterStatus**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getrasterstatus)

