# D3D10_VIEWPORT structure

## Description

Defines the dimensions of a [viewport](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-getting-started).

## Members

### `TopLeftX`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

X position of the left hand side of the viewport. Ranges between D3D10_VIEWPORT_BOUNDS_MIN and D3D10_VIEWPORT_BOUNDS_MAX.

### `TopLeftY`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Y position of the top of the viewport. Ranges between D3D10_VIEWPORT_BOUNDS_MIN and D3D10_VIEWPORT_BOUNDS_MAX.

### `Width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Width of the viewport.

### `Height`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Height of the viewport.

### `MinDepth`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum depth of the viewport. Ranges between 0 and 1.

### `MaxDepth`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum depth of the viewport. Ranges between 0 and 1.

## Remarks

In all cases, **Width** and **Height** must be ≥ 0 and **TopLeftX** + **Width** and **TopLeftY** + **Height** must be ≤ D3D10_VIEWPORT_BOUNDS_MAX.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)