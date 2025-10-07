# D3DSAMPLER\_TEXTURE\_TYPE enumeration

Defines the sampler texture types for vertex shaders.

## Constants

**D3DSTT\_UNKNOWN**

Uninitialized value. The value of this element is 0 << D3DSP\_TEXTURETYPE\_SHIFT.

**D3DSTT\_2D**

Declaring a 2D texture. The value of this element is 2 << D3DSP\_TEXTURETYPE\_SHIFT.

**D3DSTT\_CUBE**

Declaring a cube texture. The value of this element is 3 << D3DSP\_TEXTURETYPE\_SHIFT.

**D3DSTT\_VOLUME**

Declaring a volume texture. The value of this element is 4 << D3DSP\_TEXTURETYPE\_SHIFT.

**D3DSTT\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

