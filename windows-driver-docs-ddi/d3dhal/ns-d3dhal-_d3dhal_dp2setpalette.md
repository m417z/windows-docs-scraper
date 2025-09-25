# _D3DHAL_DP2SETPALETTE structure

## Description

The D3DHAL_DP2SETPALETTE structure is used to associate a palette with a texture when a driver responds to D3DDP2OP_SETPALETTE in [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb). This opcode is used to map an association between a palette handle and a surface handle, and specify the characteristics of the palette.

## Members

### `dwPaletteHandle`

Specifies a handle to the palette to be set up. If the value is zero, the surface specified by **dwSurfaceHandle** should be uncoupled from any palette it might have been associated with previously.

### `dwPaletteFlags`

Specifies a set of flags that specify the attributes of the palette.
|Flag|Meaning|
|--- |--- |
|DDRAWIPAL_2|The palette has 2 entries. Currently unused.|
|DDRAWIPAL_4|The palette has 4 entries. Currently unused.|
|DDRAWIPAL_16|The palette has 16 entries. Currently unused.|
|DDRAWIPAL_256|The palette has 256 entries. Currently unused.|
|DDRAWIPAL_ALLOW256|The palette can be fully updated. Currently unused.|
|DDRAWIPAL_ALPHA|The palette's alpha data channel is valid and should be used.|
|DDRAWIPAL_DIRTY|The palette has been changed so the GDI palette is out of sync. Currently unused.|
|DDRAWIPAL_EXCLUSIVE|The palette is being used in exclusive mode. Currently unused.|
|DDRAWIPAL_GDI|The palette is allocated through GDI. Currently unused.|
|DDRAWIPAL_INHEL|The palette is done in the HEL (hardware emulation layer). Currently unused.|
|DDRAWIPAL_STORED_8|The palette is stored using 8 bpp per entry. Currently unused.|
|DDRAWIPAL_STORED_16|The palette is stored using 16 bpp per entry. Currently unused.|
|DDRAWIPAL_STORED_24|The palette is stored using 24 bpp per entry. Currently unused.|
|DDRAWIPAL_STORED_8INDEX|The palette is stored as an 8-bit index into a destination palette. Currently unused.|

### `dwSurfaceHandle`

Specifies a handle to the Direct3D surface (texture) that this palette (identified by **dwPaletteHandle**) is associated to.

## Remarks

The number of D3DHAL_DP2SETPALETTE structures to follow is specified by the **wStateCount** member of the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure that precedes them in the command stream.

## See also

D3DDP2OP_SETPALETTE

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)