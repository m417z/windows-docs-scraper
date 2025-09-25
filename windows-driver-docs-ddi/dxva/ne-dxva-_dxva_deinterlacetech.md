# _DXVA_DeinterlaceTech enumeration

## Description

The DXVA_DeinterlaceTech enumeration identifies the underlying technology used to implement a particular deinterlace algorithm.

## Constants

### `DXVA_DeinterlaceTech_Unknown`

Indicates that the algorithm is unknown or proprietary to the hardware manufacturer.

### `DXVA_DeinterlaceTech_BOBLineReplicate`

Indicates that the algorithm creates the missing lines by repeating the line either above or below it. This method looks jagged and is not recommended.

### `DXVA_DeinterlaceTech_BOBVerticalStretch`

Specifies an algorithm that creates the missing lines by vertically stretching each video field by a factor of two. Vertical adjustments are made to ensure that the resulting image does not move up and down.

### `DXVA_DeinterlaceTech_BOBVerticalStretch4Tap`

Creates the missing lines by vertically stretching each video field by a factor of two, using a 4-tap filter.

### `DXVA_DeinterlaceTech_MedianFiltering`

Specifies that the pixels in the missing line are recreated by a median filtering operation.

### `DXVA_DeinterlaceTech_EdgeFiltering`

Specifies that pixels in the missing line are recreated by an edge filter. In this process, spatial directional filters are applied to determine the orientation of edges in the picture content, and missing pixels are created by filtering along (rather than across) the detected edges.

### `DXVA_DeinterlaceTech_FieldAdaptive`

Specifies that pixels in the missing line are recreated by switching on a field-by-field basis between either spatial or temporal interpolation, depending on the amount of motion.

### `DXVA_DeinterlaceTech_PixelAdaptive`

Specifies that pixels in the missing line are recreated by switching on a pixel-by-pixel basis between either spatial or temporal interpolation, depending on the amount of motion.

### `DXVA_DeinterlaceTech_MotionVectorSteered`

Identifies objects within a sequence of video fields. The missing pixels are recreated after first aligning the movement axis of the individual objects in the scene to make them parallel with the time axis.

## See also

[DXVA_DeinterlaceCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_deinterlacecaps)