# D3DDEGREETYPE enumeration

Defines the degree of the variables in the equation that describes a curve.

## Constants

**D3DDEGREE\_LINEAR**

Curve is described by variables of first order.

**D3DDEGREE\_QUADRATIC**

Curve is described by variables of second order.

**D3DDEGREE\_CUBIC**

Curve is described by variables of third order.

**D3DDEGREE\_QUINTIC**

Curve is described by variables of fourth order.

**D3DCULL\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The values in this enumeration are used to describe the curves used by rectangle and triangle patches. For more information, see D3DRS\_CULLMODE.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

