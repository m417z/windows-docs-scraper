# D3DBOX structure

Defines a volume.

## Members

**Left**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position of the left side of the box on the x-axis.

**Top**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position of the top of the box on the y-axis.

**Right**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position of the right side of the box on the x-axis.

**Bottom**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position of the bottom of the box on the y-axis.

**Front**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position of the front of the box on the z-axis.

**Back**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position of the back of the box on the z-axis.

## Remarks

**D3DBOX** includes the left, top, and front edges; however, the right, bottom, and back edges are not included. For example, a box that is 100 units wide and begins at 0 (thus, including the points up to and including 99) would be expressed with a value of 0 for the Left member and a value of 100 for the Right member. Note that a value of 99 is not used for the Right member.

The restrictions on side ordering observed for **D3DBOX** are left to right, top to bottom, and front to back.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

