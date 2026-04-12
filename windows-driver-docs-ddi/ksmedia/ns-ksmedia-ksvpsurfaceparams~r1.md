# KSVPSURFACEPARAMS structure

## Description

The **KSVPSURFACEPARAMS** structure describes the surface parameters for a video port operation, including pitch, origin coordinates, and surface dimensions.

## Members

### `dwPitch`

Specifies the pitch (width in bytes) of the video surface. This value indicates the number of bytes between the start of one scan line and the start of the next scan line in the surface buffer.

### `dwXOrigin`

Specifies the horizontal origin (X coordinate) of the video data within the surface. This value determines the starting pixel position for horizontal placement of the video data.

### `dwYOrigin`

Specifies the vertical origin (Y coordinate) of the video data within the surface. This value determines the starting pixel position for vertical placement of the video data.

## Remarks

This structure is used with video port properties to specify the surface parameters for video port operations. These parameters define how video data is organized and positioned within a surface buffer, which is essential for proper video rendering and display.

The pitch value is particularly important for video processing as it accounts for any alignment requirements or additional padding that may exist between scan lines in the surface buffer. The origin coordinates allow for flexible positioning of video data within a larger surface area.

## See also

- [KSVPMAXPIXELRATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksvpmaxpixelrate-r1)
- [KSVPSIZE_PROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksvpsize_prop-r1)