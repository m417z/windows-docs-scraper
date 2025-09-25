## Description

The **KSCAMERA_METADATA_BACKGROUNDSEGMENTATIONMASK** structure contains information about the dimensions of the background mask as well as its coverage of the frame it is inferred from, which is the frame that is outputted by the stream.

## Members

### `Header`

A [**KSCAMERA_METADATA_ITEMHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) structure that contains the metadata header information that is filled by the camera driver.

### `MaskCoverageBoundingBox`

Bounding box of processed mask area, in original image coordinates.

If the driver can supply a mask that covers the whole field of view, then this bounding box should be of the same dimension as the frame it corresponds to.

### `MaskResolution`

Width and height of mask data contained in the contiguous *MaskData* buffer in this struct.

This should correspond to the *MaskResolution* member of the related [**KSCAMERA_EXTENDEDPROP_BACKGROUNDSEGMENTATION_CONFIGCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_backgroundsegmentation_configcaps) returned by a GET of the [**KSPROPERTY_CAMERACONTROL_EXTENDED_BACKGROUNDSEGMENTATION**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-backgroundsegmentation)property.

### `ForegroundBoundingBox`

Bounding box of all foreground pixels in the mask, in mask coordinates.

This may help speed up processing by the app by considering only a portion of the mask. This can be left to cover the whole mask if not calculated by the driver. However when it does not cover the whole mask, then the mask data outside of this bounding box shall be considered background (zero) values regardless of their actual values.

### `MaskData`

MaskResolution.cx * MaskResolution.cy BYTE values are populated as a contiguous buffer.

The value represents the normalized confidence score of a pixel being part of the background or the foreground, where a value of "0" designates 100% certainty of a background pixel and "255" designates 100% certainty of a foreground pixel.

The size of the buffer trails beyond the MaskData field and the size is determined by the size of the MetadataSize field. MetadataSize should be equal to FIELD_OFFSET(KSCAMERA_METADATA_BACKGROUNDSEGMENTATIONMASK, MaskData) + [MaskResolution.cx * MaskResolution.cy].

## Remarks

## See also

[KSPROPERTY_CAMERACONTROL_EXTENDED_BACKGROUNDSEGMENTATION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-extended-backgroundsegmentation)

[KSCAMERA_EXTENDEDPROP_BACKGROUNDSEGMENTATION_CONFIGCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_extendedprop_backgroundsegmentation_configcaps)