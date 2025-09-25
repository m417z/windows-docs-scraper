# KSPROPERTY_VIDEOCOMPRESSION_GETINFO_S structure

## Description

The KSPROPERTY_VIDEOCOMPRESSION_GETINFO_S structure describes information about the video compression capabilities supported by a device.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `StreamIndex`

Specifies the zero-based index of the stream being queried.

### `DefaultKeyFrameRate`

Indicates the estimated number of frames per key frame.

### `DefaultPFrameRate`

Indicates the predicted number of frames per key frame.

### `DefaultQuality`

Specifies the default quality value. This value should be in the range from 0 through 10000.

### `NumberOfQualitySettings`

Indicates the number of discrete compression quality settings the device supports.

### `Capabilities`

Specifies the compression capabilities of the device. This member can be one or more (logically ORed) of the values from the [KS_CompressionCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_compressioncaps) enumeration.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KS_CompressionCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_compressioncaps)

[PROPSETID_VIDCAP_VIDEOCOMPRESSION](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videocompression)