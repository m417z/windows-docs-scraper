# D3DVS\_VERSION macro

Create a vertex shader version number token.

## Parameters

*\_Major*

The major vertex shader version. See remarks for appropriate values.

*\_Minor*

The minor vertex shader version. See remarks for appropriate values.

## Return value

Returns a DWORD value that is a vertex shader version.

## Remarks

Version Numbers

The version number is a combination of the major version and the minor vertex shader version numbers. Valid numbers are shown in the table.

| Major | Minor | Example |
|-------|-------|---------------------|
| 1 | 1 | D3DVS\_VERSION(1,1) |
| 2 | 0 | D3DVS\_VERSION(2,0) |
| 3 | 0 | D3DVS\_VERSION(3,0) |

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Macros](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-macros)

