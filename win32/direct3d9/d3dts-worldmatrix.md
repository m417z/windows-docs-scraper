# D3DTS\_WORLDMATRIX macro

Maps indices in the range 0 through 255 to the corresponding transform states.

## Parameters

*index*

An index value in the range 0 through 255.

## Return value

The [**D3DTRANSFORMSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtransformstatetype) that maps to the given *index*.

## Remarks

Transform states in the range 256 through 511 are reserved to store up to 256 matrices that can be indexed using 8-bit indices.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Macros](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-macros)

[**SetTransform**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settransform)

