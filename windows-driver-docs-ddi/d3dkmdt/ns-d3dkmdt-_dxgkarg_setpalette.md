# _DXGKARG_SETPALETTE structure

## Description

The DXGKARG_SETPALETTE structure describes the palette to set for a display.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the palette is set on.

### `FirstEntry` [in]

The location in the device palette that the first entry in the array of color entries that **pLookupTable** specifies is copied to. The remaining entries that **pLookupTable** specifies are copied sequentially, from this starting point into the device's palette.

### `NumEntries` [in]

The number of color entries in the array that **pLookupTable** specifies.

### `pLookupTable` [in]

An array of color entries to copy into the device's color palette (that is, the device's color registers). Each color entry is accessed as a generic 32-bit value or as the **Red**, **Green**, **Blue**, and **Unused** members of a [D3DKMDT_PALETTEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_palettedata) structure.

## See also

[D3DKMDT_PALETTEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_palettedata)

[DxgkDdiSetPalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpalette)