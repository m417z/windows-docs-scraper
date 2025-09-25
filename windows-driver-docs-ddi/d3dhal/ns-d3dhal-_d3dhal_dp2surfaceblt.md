# _D3DHAL_DP2SURFACEBLT structure

## Description

 DirectX 9.0 and later versions only.

D3DHAL_DP2SURFACEBLT is used for two dimensional system memory to video memory surface blts when [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) responds to the D3DDP2OP_SURFACEBLT command token.

## Members

### `dwSource`

Specifies the handle to the source surface.

### `rSource`

Specifies a RECTL structure that specifies the upper left and lower right points of a rectangle on the source surface. These points define the area of the source blit data and its position on the source surface.

### `dwSourceMipLevel`

Specifies the sublevel of a MIP-map texture that is the source of the blt.

### `dwDest`

Specifies the handle to the destination surface.

### `rDest`

Specifies a RECTL structure that specifies the upper left and lower right points of a rectangle on the destination surface. These points define the area in which the blit should occur and its position on the destination surface.

### `dwDestMipLevel`

Specifies the sublevel of a MIP-map texture that is the destination for the blt.

### `Flags`

Unused

## Remarks

The D3DDP2OP_SURFACEBLT operation code is identical to the D3DDP2OP_BLT operation code except that D3DDP2OP_SURFACEBLT is only used to copy system memory to video memory and is never used for stretch blts or color conversion. Because D3DDP2OP_SURFACEBLT is not used for stretch blts, no flags are currently defined.

The **dwSource** or **dwDest** member specifies the kernel handle to the top-level surface and the **dwSourceMipLevel** or **dwDestMiplevel** member specifies the sublevel for the MIP-map chain where the blt occurs.

## See also

D3DDP2OP_BLT

D3DDP2OP_SURFACEBLT

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)