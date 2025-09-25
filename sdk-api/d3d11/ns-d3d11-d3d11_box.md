# D3D11_BOX structure

## Description

Defines a 3D box.

## Members

### `left`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The x position of the left hand side of the box.

### `top`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The y position of the top of the box.

### `front`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The z position of the front of the box.

### `right`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The x position of the right hand side of the box.

### `bottom`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The y position of the bottom of the box.

### `back`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The z position of the back of the box.

## Remarks

The following diagram shows a 3D box, where the origin is the left, front, top corner.

![Diagram of a 3D box, where the origin is the left, front, top corner](https://learn.microsoft.com/windows/win32/api/d3d11/images/D3D10_box.png)

The values for **right**, **bottom**, and **back** are each one pixel past the end of the pixels that are included in the box region. That is, the values for **left**, **top**, and **front** are included in the box region while the values for right, bottom, and back are excluded from the box region. For example, for a box that is one pixel wide, (right - left) == 1; the box region includes the left pixel but not the right pixel.

Coordinates of a box are in bytes for buffers and in texels for textures.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)