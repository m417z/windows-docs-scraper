# _DXVADDI_VIDEOSAMPLE structure

## Description

The DXVADDI_VIDEOSAMPLE structure describes the format of a video sample that is used in a video processing operation.

## Members

### `Start` [in]

A REFERENCE_TIME value that identifies the start time of the sample.

### `End` [in]

A REFERENCE_TIME value that identifies the end time of the sample.

### `SampleFormat` [in]

A [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure that describes the extended format of the video sample.

### `SampleFlags` [in]

A [DXVADDI_VIDEOSAMPLEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_videosampleflags) structure that identifies changes in the current sample frame from the previous sample frame.

### `SrcResource` [in]

A handle to the resource that contains the source surface.

### `SrcSubResourceIndex` [in]

The index to the source surface within the resource.

### `SrcRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that describes the upper-left and lower-right points of a rectangle on the source surface. These points define the area of the source data for the bit-block transfer (bitblt) and its position on the source surface.

### `DstRect` [in]

A RECT structure that describes the upper-left and lower-right points of a rectangle on the destination surface. These points define the area in which the bit-block transfer (bitblt) should occur and its position on the destination surface.

### `Pal` [in]

An array of [DXVADDI_AYUVSAMPLE8](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_ayuvsample8) structures that represent a complete 16-color palette for palletized video substream pixel formats. The driver uses this palette to composite the substream sample. For nonpalletized pixel formats, the **Pal** member is **NULL** and can be ignored.

### `PlanarAlpha` [in]

A [DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32) structure that specifies the transparency value that the driver should apply to the composited background color and video stream and substream image (the entire video plane) as it is written to the destination surface. A value of 0.0 indicates transparent. A value of 1.0 indicates opaque.

## See also

[D3DDDIARG_VIDEOPROCESSBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_videoprocessblt)

[DXVADDI_AYUVSAMPLE8](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_ayuvsample8)

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)

[DXVADDI_FIXED32](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_fixed32)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)