# _D3DHAL_DP2UPDATEPALETTE structure

## Description

The D3DHAL_DP2UPDATEPALETTE structure alters the palette that is used for palletized textures.

## Members

### `dwPaletteHandle`

Specifies a handle to the palette to be altered.

### `wStartIndex`

Specifies the index in the palette beyond which data is updated.

### `wNumEntries`

Specifies the number of PALETTEENTRYs being updated.

## Remarks

The D3DHAL_DP2UPDATEPALETTE structure is used when responding to the D3DDP2OP_UPDATEPALETTE opcode in [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

The palette handle attached to a surface is updated with **wNumEntries** PALETTEENTRYs starting at a specific **wStartIndex** member of the palette. A PALETTEENTRY (defined in *wingdi.h* and *wtypes.h*) is actually a DWORD with an ARGB color for each byte.

After the D3DHAL_DP2UPDATEPALETTE structure in the command stream, the actual palette data follows (without any padding), consisting of one DWORD per palette entry (in ARGB format, with 8 bits for each of the four channels). There is only one D3DHAL_DP2UPDATEPALETTE structure (plus palette data) following the [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure regardless of the value of **wStateCount** (a member of the D3DHAL_DP2COMMAND structure).

## See also

D3DDP2OP_UPDATEPALETTE

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)