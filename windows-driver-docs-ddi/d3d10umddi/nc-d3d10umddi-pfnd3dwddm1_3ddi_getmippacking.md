# PFND3DWDDM1_3DDI_GETMIPPACKING callback function

## Description

For a given tiled resource, returns how many mips are packed, and how many tiles are needed to store all the packed mips.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hTiledResource`

A handle to the tiled resource.

### `pNumPackedMips`

A pointer to a variable that receives the number of mips that are packed, for a given array slice, including any mips that don't use the standard tile shapes.

If there is no packing, a value of zero should be returned.

### `pNumTilesForPackedMips`

A pointer to a variable that receives the number of tiles that the packed mips fit into, for a given array slice.

This parameter is ignored if **pNumPackedMips* returns zero.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code. The driver can set **E_INVALIDARG** if an input parameter does not exist or is **NULL**.

Packed mips include cases where multiple small mips share tile(s) and also mips for which a given device cannot use standard tile shapes. It's possible for an entire resource to be considered packed.

Applications are not told the tile shapes or layout for packed mips and must simply map
all or none of the packed tiles if any of the mipmaps are to be accessed.
Otherwise the observed mapping of individual pixels accessed are undefined and are specific to the independent hardware vendor (IHV).

Mipmaps that have pixel dimensions that fully fill at least one standard-shaped tile in all
dimensions are not allowed to be considered part of the set of packed mips. Otherwise
the runtime will remove the device on an invalid driver.
One example of dimensions that a device can validly lump into
the packed tiles (meaning the IHV can use his or her own custom tile breakdown) is
a mip that is at least one tile wide but less than a tile high. Ideally though,
a device would use the standard tile breakdown for this case (so the application can
manage the tiles in a standard way). If a device does need to use a custom tiling,
the application is not told what the tile breakdown is (only how many tiles are involved
in the packing overall), and thus loses some freedom.

## See also

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)