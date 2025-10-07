# D3DPS\_VERSION macro

Create a pixel shader version token.

## Parameters

*\_Major*

The major pixel shader version.

*\_Minor*

The minor pixel shader version.

## Return value

Returns a DWORD value that is a pixel shader version.

## Remarks

Version Numbers

The version number is a combination of the major version and the minor vertex shader version numbers. Valid numbers are shown in the table.

| Major | Minor | Example |
|-------|-------|---------------------|
| 1 | 1 | D3DPS\_VERSION(1,1) |
| 1 | 2 | D3DPS\_VERSION(1,2) |
| 1 | 3 | D3DPS\_VERSION(1,3) |
| 1 | 4 | D3DPS\_VERSION(1,4) |
| 2 | 0 | D3DPS\_VERSION(2,0) |
| 3 | 0 | D3DPS\_VERSION(3,0) |

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Macros](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-macros)

[D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9)

