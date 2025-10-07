# D3DSTENCILOP enumeration

Defines stencil-buffer operations.

## Constants

**D3DSTENCILOP\_KEEP**

Do not update the entry in the stencil buffer. This is the default value.

**D3DSTENCILOP\_ZERO**

Set the stencil-buffer entry to 0.

**D3DSTENCILOP\_REPLACE**

Replace the stencil-buffer entry with a reference value.

**D3DSTENCILOP\_INCRSAT**

Increment the stencil-buffer entry, clamping to the maximum value.

**D3DSTENCILOP\_DECRSAT**

Decrement the stencil-buffer entry, clamping to zero.

**D3DSTENCILOP\_INVERT**

Invert the bits in the stencil-buffer entry.

**D3DSTENCILOP\_INCR**

Increment the stencil-buffer entry, wrapping to zero if the new value exceeds the maximum value.

**D3DSTENCILOP\_DECR**

Decrement the stencil-buffer entry, wrapping to the maximum value if the new value is less than zero.

**D3DSTENCILOP\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Stencil-buffer entries are integer values ranging from 0 through 2ⁿ - 1, where n is the bit depth of the stencil buffer.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

