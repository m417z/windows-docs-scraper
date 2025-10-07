# D3DFOGMODE enumeration

Defines constants that describe the fog mode.

## Constants

**D3DFOG\_NONE**

No fog effect.

**D3DFOG\_EXP**

Fog effect intensifies exponentially, according to the following formula.

![formula of fog-effect intensity](https://learn.microsoft.com/windows/win32/direct3d9/images/fogexp.png)

**D3DFOG\_EXP2**

Fog effect intensifies exponentially with the square of the distance, according to the following formula.

![formula of fog-effect intensity based on square of distance](https://learn.microsoft.com/windows/win32/direct3d9/images/fogexp2.png)

**D3DFOG\_LINEAR**

Fog effect intensifies linearly between the start and end points, according to the following formula.

![formula of fog-effect intensity based on start and end points](https://learn.microsoft.com/windows/win32/direct3d9/images/fogliner.png)

This is the only fog mode currently supported.

**D3DFOG\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The values in this enumerated type are used by the D3DRS\_FOGTABLEMODE and D3DRS\_FOGVERTEXMODE render states.

Fog can be considered a measure of visibility: the lower the fog value produced by a fog equation, the less visible an object is.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

