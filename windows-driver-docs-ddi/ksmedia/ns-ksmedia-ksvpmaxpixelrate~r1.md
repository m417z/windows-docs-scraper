# KSVPMAXPIXELRATE structure

## Description

The **KSVPMAXPIXELRATE** structure describes the maximum pixel processing rate for a video port in pixels per second.

## Members

### `Size`

Specifies the size of the structure in bytes. This field is used to ensure proper structure versioning and validation.

### `MaxPixelsPerSecond`

Specifies the maximum number of pixels that the video port can process per second. This value determines the bandwidth limitations of the video port and affects the supported video formats and resolutions.

### `Reserved`

Reserved for system use. This field should be set to zero and should not be modified by applications.

## Remarks

This structure is used with video port-related properties to specify or query the maximum pixel processing capabilities of a video port. The maximum pixel rate is an important factor in determining what video formats and resolutions can be supported by a particular video port configuration.

Video port drivers use this information to validate requested video formats and to optimize performance by selecting appropriate processing parameters within the hardware's capabilities.

## See also

- [KSVPSIZE_PROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksvpsize_prop-r1)
- [KSVPSURFACEPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksvpsurfaceparams-r1)