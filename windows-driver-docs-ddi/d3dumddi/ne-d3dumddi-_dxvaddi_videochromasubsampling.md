# _DXVADDI_VIDEOCHROMASUBSAMPLING enumeration

## Description

The DXVADDI_VIDEOCHROMASUBSAMPLING enumeration type contains values that identify the chroma encoding scheme for Y'Cb'Cr' data.

## Constants

### `DXVADDI_VideoChromaSubsamplingMask`

The video chroma subsampling mask. The first four (0x0F) bits of a DWORD can be used to specify video chroma subsampling.

### `DXVADDI_VideoChromaSubsampling_Unknown`

The video chroma subsampling is not specified.

### `DXVADDI_VideoChromaSubsampling_ProgressiveChroma`

The video chroma subsampling is progressive.

### `DXVADDI_VideoChromaSubsampling_Horizontally_Cosited`

Chroma samples are aligned on multiples of the luma samples horizontally.

### `DXVADDI_VideoChromaSubsampling_Vertically_Cosited`

Chroma samples are aligned on multiples of the luma samples vertically.

### `DXVADDI_VideoChromaSubsampling_Vertically_AlignedChromaPlanes`

The Pb and Pr (or Cb and Cr) planes have the same phase alignment. This value can be set only to 0 in the **VideoChromaSubsampling** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure if the data is vertically cosited.

### `DXVADDI_VideoChromaSubsampling_MPEG2`

A bitwise OR of the **DXVADDI_VideoChromaSubsampling_Horizontally_Cosited** and **DXVADDI_VideoChromaSubsampling_Vertically_AlignedChromaPlanes** values that are used with 4:2:0 data.

### `DXVADDI_VideoChromaSubsampling_MPEG1`

The **DXVADDI_VideoChromaSubsampling_Vertically_AlignedChromaPlanes** value that is used with 4:2:0 data.

### `DXVADDI_VideoChromaSubsampling_DV_PAL`

A bitwise OR of the **DXVADDI_VideoChromaSubsampling_Horizontally_Cosited** and **DXVADDI_VideoChromaSubsampling_Vertically_Cosited** values that are used with 4:2:0 data.

### `DXVADDI_VideoChromaSubsampling_Cosited`

A bitwise OR of the **DXVADDI_VideoChromaSubsampling_Horizontally_Cosited**, and **DXVADDI_VideoChromaSubsampling_Vertically_Cosited**, and **DXVADDI_VideoChromaSubsampling_Vertically_AlignedChromaPlanes** values that are used with 4:4:4, 4:2:2, and 4:1:1 data.

## Remarks

A bitwise OR of the values of DXVADDI_VIDEOCHROMASUBSAMPLING can be used to create a value in the **VideoChromaSubsampling** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure.

Cosite variations indicate that the chroma samples are aligned with the luma samples. Typically, 4:2:0 data with chroma is aligned in one or more directions with the luma data. Note that 4:4:4, 4:2:2, and 4:1:1 data are always cosited in both directions.

## See also

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)