# _D3DDDITEXTURESTAGESTATETYPE enumeration

## Description

The texture stage state type.

## Constants

### `D3DDDITSS_TEXTUREMAP`

A [D3DTEXTUREOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3dtextureop) that specifies the texture map.

### `D3DDDITSS_COLOROP`

A D3DTEXTUREOP that specifies per-stage blending controls for color channels.

### `D3DDDITSS_COLORARG1`

A D3DTA_TEXTURE that represents texture arguments. The D3DTA_TEXTURE constant is used to select a texture color.

### `D3DDDITSS_COLORARG2`

A D3DTA_TEXTURE that represents texture arguments. The D3DTA_TEXTURE constant is used to select a texture color.

### `D3DDDITSS_ALPHAOP`

A D3DTEXTUREOP that specifies per-stage blending controls for alpha channel.

### `D3DDDITSS_ALPHAARG1`

A D3DTA_TEXTURE that represents texture arguments. The D3DTA_TEXTURE constant is used to select a texture color.

### `D3DDDITSS_ALPHAARG2`

A D3DTA_TEXTURE that represents texture arguments. The D3DTA_TEXTURE constant is used to select a texture color.

### `D3DDDITSS_BUMPENVMAT00`

A float that represents a bump mapping matrix.

### `D3DDDITSS_BUMPENVMAT01`

A float that represents a bump mapping matrix.

### `D3DDDITSS_BUMPENVMAT10`

A float that represents a bump mapping matrix.

### `D3DDDITSS_BUMPENVMAT11`

A float that represents a bump mapping matrix.

### `D3DDDITSS_TEXCOORDINDEX`

Identifies which set of texture coordinates index for this texture.

### `D3DDDITSS_ADDRESSU`

### `D3DDDITSS_ADDRESSV`

### `D3DDDITSS_BORDERCOLOR`

### `D3DDDITSS_MAGFILTER`

### `D3DDDITSS_MINFILTER`

### `D3DDDITSS_MIPFILTER`

### `D3DDDITSS_MIPMAPLODBIAS`

### `D3DDDITSS_MAXMIPLEVEL`

### `D3DDDITSS_MAXANISOTROPY`

### `D3DDDITSS_BUMPENVLSCALE`

A float scale for bump map luminance.

### `D3DDDITSS_BUMPENVLOFFSET`

A float offset for bump map luminance.

### `D3DDDITSS_TEXTURETRANSFORMFLAGS`

A [D3DTEXTURETRANSFORMFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3dtexturetransformflags) that controls texture transform.

### `D3DDDITSS_ADDRESSW`

### `D3DDDITSS_COLORARG0`

A third argument for triadic operations.

### `D3DDDITSS_ALPHAARG0`

A third argument for triadic operations.

### `D3DDDITSS_RESULTARG`

Arguments for the result, either D3DTA_CURRENT or D3DTA_TEMP.

D3DTA_TEMP is used to select a temporary register color.
D3DTA_CURRENT is used to select a stage destination register.

### `D3DDDITSS_SRGBTEXTURE`

### `D3DDDITSS_ELEMENTINDEX`

### `D3DDDITSS_DMAPOFFSET`

### `D3DDDITSS_CONSTANT`

A D3DTA_CONSTANT that indicates per-stage constant.

### `D3DDDITSS_DISABLETEXTURECOLORKEY`

Disable texture color key.

### `D3DDDITSS_TEXTURECOLORKEYVAL`

The texture color key value.

### `D3DDDITSS_FORCE_DWORD`

Forces this enumeration to compile to 32 bits in size.

## Remarks

## See also