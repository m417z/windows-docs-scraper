# _D3DHAL_DP2VOLUMEBLT structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2VOLUMEBLT structure is used for volume texture blts when [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) responds to the D3DDP2OP_VOLUMEBLT command token.

## Members

### `dwDDDestSurface`

Specifies the handle to the destination volume texture.

### `dwDDSrcSurface`

Specifies the handle to the source volume texture.

### `dwDestX`

Specify the location in the destination volume texture to copy the defined source subvolume. These members (**dwDestX**, **dwDestY**, and **dwDestZ**) are specified in screen coordinates.

### `dwDestY`

See **dwDestX** above.

### `dwDestZ`

See **dwDestX** above.

### `srcBox`

Specifies a subvolume of the source volume texture to copy to the destination.

### `dwFlags`

Reserved for system use.

## Remarks

The [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) callback creates the small integer handles to the volume textures that can be used as source and destination volume textures for volume texture blts.

See Remarks for [D3DHAL_DP2TEXBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2texblt).

## See also

D3DDP2OP_VOLUMEBLT

[D3DHAL_DP2TEXBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2texblt)

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)