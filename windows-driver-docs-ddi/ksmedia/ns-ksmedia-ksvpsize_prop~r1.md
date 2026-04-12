# KSVPSIZE_PROP structure

## Description

The **KSVPSIZE_PROP** structure describes the size properties for a video port operation.

## Members

### `Property`

Specifies a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that identifies the property set, property ID, and request type for the video port size property.

### `Size`

Specifies the size dimensions for the video port operation. This field defines the width and height of the video data to be processed by the video port.

## Remarks

This structure is used with video port properties to specify or query size-related parameters for video port operations. The size information is essential for configuring the video port to handle specific video formats and resolutions.

Video port drivers use this information to set up the appropriate hardware configuration for processing video data of the specified dimensions.

## See also

- [KSVPMAXPIXELRATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksvpmaxpixelrate-r1)
- [KSVPSURFACEPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksvpsurfaceparams-r1)
- [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)