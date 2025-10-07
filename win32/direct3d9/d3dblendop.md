# D3DBLENDOP enumeration

Defines the supported blend operations. See Remarks for definitions of terms.

## Constants

**D3DBLENDOP\_ADD**

The result is the destination added to the source. Result = Source + Destination

**D3DBLENDOP\_SUBTRACT**

The result is the destination subtracted from to the source. Result = Source - Destination

**D3DBLENDOP\_REVSUBTRACT**

The result is the source subtracted from the destination. Result = Destination - Source

**D3DBLENDOP\_MIN**

The result is the minimum of the source and destination. Result = MIN(Source, Destination)

**D3DBLENDOP\_MAX**

The result is the maximum of the source and destination. Result = MAX(Source, Destination)

**D3DBLENDOP\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Source, Destination, and Result are defined as:

| Term | Type | Description |
|-------------|--------|------------------------------------------------------------------------|
| Source | Input | Color of the source pixel before the operation. |
| Destination | Input | Color of the pixel in the destination buffer before the operation. |
| Result | Output | Returned value that is the blended color resulting from the operation. |

This enumerated type defines values used by the following render states:

- D3DRS\_BLENDOP
- D3DRS\_BLENDOPALPHA

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DCAPS9**](https://learn.microsoft.com/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9)

[**D3DRENDERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3drenderstatetype)

