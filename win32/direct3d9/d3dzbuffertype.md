# D3DZBUFFERTYPE enumeration

Defines constants that describe depth-buffer formats.

## Constants

**D3DZB\_FALSE**

Disable depth buffering.

**D3DZB\_TRUE**

Enable z-buffering.

**D3DZB\_USEW**

Enable w-buffering.

**D3DZB\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Members of this enumerated type are used with the D3DRS\_ZENABLE render state.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

