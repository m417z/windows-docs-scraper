# D3DTEXTUREADDRESS enumeration

Defines constants that describe the supported texture-addressing modes.

## Constants

**D3DTADDRESS\_WRAP**

Tile the texture at every integer junction. For example, for u values between 0 and 3, the texture is repeated three times; no mirroring is performed.

**D3DTADDRESS\_MIRROR**

Similar to D3DTADDRESS\_WRAP, except that the texture is flipped at every integer junction. For u values between 0 and 1, for example, the texture is addressed normally; between 1 and 2, the texture is flipped (mirrored); between 2 and 3, the texture is normal again; and so on.

**D3DTADDRESS\_CLAMP**

Texture coordinates outside the range \[0.0, 1.0\] are set to the texture color at 0.0 or 1.0, respectively.

**D3DTADDRESS\_BORDER**

Texture coordinates outside the range \[0.0, 1.0\] are set to the border color.

**D3DTADDRESS\_MIRRORONCE**

Similar to D3DTADDRESS\_MIRROR and D3DTADDRESS\_CLAMP. Takes the absolute value of the texture coordinate (thus, mirroring around 0), and then clamps to the maximum value. The most common usage is for volume textures, where support for the full D3DTADDRESS\_MIRRORONCE texture-addressing mode is not necessary, but the data is symmetric around the one axis.

**D3DTADDRESS\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DSAMPLERSTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dsamplerstatetype)

