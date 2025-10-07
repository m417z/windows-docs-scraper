# D3DXTRANSITION\_TYPE enumeration

Defines the transition style between values of a mesh animation.

## Constants

**D3DXTRANSITION\_LINEAR**

Linear transition between values.

**D3DXTRANSITION\_EASEINEASEOUT**

Ease-in, ease-out spline transition between values.

**D3DXTRANSITION\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The calculation for the ramp from ease in to ease out is calculated as follows:

Q(t) = 2(x - y)t³ + 3(y - x)t² + x

where the ramp is a function Q(t) with the following properties:

- Q(t) is a cubic spline.
- Q(t) interpolates between x and y as t ranges from 0 to 1.
- Q(t) is horizontal when t = 0 and t = 1.

Mathematically, this translates into:

Q(t) = At³ + Bt² + Ct + D (and therefore, Q'(t) = 3At² + 2Bt + C)
2a) Q(0) = x
2b) Q(1) = y
3a) Q'(0) = 0
3b) Q'(1) = 0

Solving for A, B, C, D:

D = x (from 2a)
C = 0 (from 3a)
3A + 2B = 0 (from 3b)
A + B = y - x (from 2b and D = x)

Therefore:

A = 2(x - y), B = 3(y - x), C = 0, D = x

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

