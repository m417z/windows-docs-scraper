# IDirectDraw7::CreatePalette

## Description

Creates a DirectDrawPalette object for this DirectDraw object.

## Parameters

### `unnamedParam1` [in]

This value consists of one or more of the following flags:

#### DDPCAPS_1BIT

The index is 1 bit. There are two entries in the color table.

#### DDPCAPS_2BIT

The index is 2 bits. There are four entries in the color table.

#### DDPCAPS_4BIT

The index is 4 bits. There are 16 entries in the color table.

#### DDPCAPS_8BIT

The index is 8 bits. There are 256 entries in the color table.

#### DDPCAPS_8BITENTRIES

The index refers to an 8-bit color index. This flag is valid only when used with the DDPCAPS_1BIT, DDPCAPS_2BIT, or DDPCAPS_4BIT flag, and when the target surface is 8 bpp. Each color entry is 1 byte long and is an index to a destination surface's 8-bpp palette.

#### DDPCAPS_ALPHA

The **peFlags** member of the associated [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structure is to be interpreted as a single 8-bit alpha value (in addition to the **peRed**, **peGreen**, and **peBlue** members). A palette created by using this flag can be attached only to a texture: a surface created with the DDSCAPS_TEXTURE capability flag.

#### DDPCAPS_ALLOW256

This palette can have all 256 entries defined.

#### DDPCAPS_INITIALIZE

Obsolete. DirectDraw always initializes this palette with the colors in the color array passed at *lpDDColorArray*.

#### DDPCAPS_PRIMARYSURFACE

This palette is attached to the primary surface. Changing this palette's color table immediately affects the display unless DDPSETPAL_VSYNC is specified and supported.

#### DDPCAPS_PRIMARYSURFACELEFT

This palette is the one attached to the left-eye primary surface. Changing this palette's color table immediately affects the left-eye display unless DDPSETPAL_VSYNC is specified and supported.

#### DDPCAPS_VSYNC

This palette can have modifications to it synchronized with the monitor's refresh rate.

### `unnamedParam2` [in]

Address of an array of 2, 4, 16, or 256 [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures to initialize the DirectDrawPalette object.

### `unnamedParam3` [out]

Address of a variable to be set to a valid [IDirectDrawPalette](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawpalette) interface pointer if the call succeeds.

### `unnamedParam4` [in]

Allows for future compatibility with COM aggregation features. Currently, this method returns an error if this parameter is not NULL.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOCOOPERATIVELEVELSET
* DDERR_OUTOFMEMORY
* DDERR_UNSUPPORTED

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)