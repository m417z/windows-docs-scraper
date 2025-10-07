# D3DTEXTURETRANSFORMFLAGS enumeration

Defines texture coordinate transformation values.

## Constants

**D3DTTFF\_DISABLE**

Texture coordinates are passed directly to the rasterizer.

**D3DTTFF\_COUNT1**

The rasterizer should expect 1D texture coordinates. This value is used by fixed function vertex processing; it should be set to 0 when using a programmable vertex shader.

**D3DTTFF\_COUNT2**

The rasterizer should expect 2D texture coordinates. This value is used by fixed function vertex processing; it should be set to 0 when using a programmable vertex shader.

**D3DTTFF\_COUNT3**

The rasterizer should expect 3D texture coordinates. This value is used by fixed function vertex processing; it should be set to 0 when using a programmable vertex shader.

**D3DTTFF\_COUNT4**

The rasterizer should expect 4D texture coordinates. This value is used by fixed function vertex processing; it should be set to 0 when using a programmable vertex shader.

**D3DTTFF\_PROJECTED**

This flag is honored by the fixed function pixel pipeline, as well as the programmable pixel pipeline in versions ps\_1\_1 to ps\_1\_3. When texture projection is enabled for a texture stage, all four floating point values must be written to the corresponding texture register. Each texture coordinate is divided by the last element before being passed to the rasterizer. For example, if this flag is specified with the D3DTTFF\_COUNT3 flag, the first and second texture coordinates are divided by the third coordinate before being passed to the rasterizer.

**D3DTTFF\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Texture coordinates can be transformed using a 4 x 4 matrix before the results are passed to the rasterizer. The texture coordinate transforms are set by calling [**IDirect3DDevice9::SetTextureStageState**](https://learn.microsoft.com/windows/desktop/api), and by passing in the D3DTSS\_TEXTURETRANSFORMFLAGS texture stage state and one of the values from **D3DTEXTURETRANSFORMFLAGS**. For more information about texture transforms, see [Texture Coordinate Transformations (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/texture-coordinate-transformations).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**D3DTEXTURESTAGESTATETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dtexturestagestatetype)

