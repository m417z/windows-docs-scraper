# D3DXCOMPRESSION\_FLAGS enumeration

Defines the compression mode used for storing compressed animation set data.

## Constants

**D3DXCOMPRESS\_DEFAULT**

Implements fast compression.

**D3DXCOMPRESS\_STRONG**

Implements slow compression. Typically results in a better quality compressed animation set than if D3DXCOMPRESS\_DEFAULT is used.

**D3DXCOMPRESS\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9anim.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

