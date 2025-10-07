# D3DCMPFUNC enumeration

Defines the supported compare functions.

## Constants

**D3DCMP\_NEVER**

Always fail the test.

**D3DCMP\_LESS**

Accept the new pixel if its value is less than the value of the current pixel.

**D3DCMP\_EQUAL**

Accept the new pixel if its value equals the value of the current pixel.

**D3DCMP\_LESSEQUAL**

Accept the new pixel if its value is less than or equal to the value of the current pixel.

**D3DCMP\_GREATER**

Accept the new pixel if its value is greater than the value of the current pixel.

**D3DCMP\_NOTEQUAL**

Accept the new pixel if its value does not equal the value of the current pixel.

**D3DCMP\_GREATEREQUAL**

Accept the new pixel if its value is greater than or equal to the value of the current pixel.

**D3DCMP\_ALWAYS**

Always pass the test.

**D3DCMP\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The values in this enumerated type define the supported compare functions for the D3DRS\_ZFUNC, D3DRS\_ALPHAFUNC, and D3DRS\_STENCILFUNC render states.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

