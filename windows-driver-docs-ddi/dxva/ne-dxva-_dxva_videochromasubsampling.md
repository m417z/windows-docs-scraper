# _DXVA_VideoChromaSubsampling enumeration

## Description

The DXVA_VideoChromaSubsampling enumeration type contains enumerators that identify the chroma encoding scheme for Y'Cb'Cr' data.

## Constants

### `DXVA_VideoChromaSubsamplingShift`

Specifies to shift bits by 8 positions (DXVA_ExtColorData_ShiftBase + 0, or 8 + 0).

### `DXVA_VideoChromaSubsamplingMask`

Specifies the video chroma subsampling mask. 4 (0x00000F00) bits of a DWORD can be used to specify video chroma subsampling.

### `DXVA_VideoChromaSubsampling_Unknown`

Specifies that the video chroma subsampling is not specified.

### `DXVA_VideoChromaSubsampling_ProgressiveChroma`

Specifies that the video chroma subsampling is progressive chroma.

### `DXVA_VideoChromaSubsampling_Horizontally_Cosited`

Specifies that chroma samples are aligned on multiples of the luma samples horizontally.

### `DXVA_VideoChromaSubsampling_Vertically_Cosited`

Specifies that chroma samples are aligned on multiples of the luma samples vertically.

### `DXVA_VideoChromaSubsampling_Vertically_AlignedChromaPlanes`

Specifies that the Pb and Pr (or Cb and Cr) planes have the same phase alignment. This enumerator can only be set to 0 in the **VideoChromaSubsampling** member of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure if the data is vertically cosited.

### `DXVA_VideoChromaSubsampling_MPEG2`

A bitwise OR of the DXVA_VideoChromaSubsampling_Horizontally_Cosited and DXVA_VideoChromaSubsampling_Vertically_AlignedChromaPlanes values that are used with 4:2:0 data.

### `DXVA_VideoChromaSubsampling_MPEG1`

The DXVA_VideoChromaSubsampling_Vertically_AlignedChromaPlanes value that is used with 4:2:0 data.

### `DXVA_VideoChromaSubsampling_DV_PAL`

A bitwise OR of the DXVA_VideoChromaSubsampling_Horizontally_Cosited and DXVA_VideoChromaSubsampling_Vertically_Cosited values that are used with 4:2:0 data.

### `DXVA_VideoChromaSubsampling_Cosited`

A bitwise OR of the DXVA_VideoChromaSubsampling_Horizontally_Cosited, and DXVA_VideoChromaSubsampling_Vertically_Cosited, and DXVA_VideoChromaSubsampling_Vertically_AlignedChromaPlanes values that are used with 4:4:4, 4:2:2, and 4:1:1 data.

## Remarks

The enumerators of DXVA_VideoChromaSubsampling can be ORed together to create a value in the **VideoChromaSubsampling** member of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure.

Cosite variations indicate that the chroma samples are aligned with the luma samples. Typically, 4:2:0 data with chroma is aligned in one or more directions with the luma data. Note that 4:4:4, 4:2:2 and 4:1:1 data are always cosited in both directions.

## See also

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)