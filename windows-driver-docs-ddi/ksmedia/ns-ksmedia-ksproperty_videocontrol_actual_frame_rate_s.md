# KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE_S structure

## Description

The KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE_S structure describes actual frame rate information in response to KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE property requests.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `StreamIndex`

Contains the zero-based index of the stream.

### `RangeIndex`

Contains the zero-based index into the range list. The value contained at this location specifies the range in which frame rate information is being requested.

### `Dimensions`

Specifies the width and height of the image.

### `CurrentActualFrameRate`

Specifies the actual frame rate for the specified stream and range. Frame rate values are expressed in 100-nanosecond units.

### `CurrentMaxAvailableFrameRate`

Specifies the maximum frame rate for the specified stream and range. Frame rate values are expressed in 100-nanosecond units.

## Remarks

The minidriver should return STATUS_NOT_SUPPORTED if the pin is not open.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEOCONTROL_ACTUAL_FRAME_RATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocontrol-actual-frame-rate)

[PROPSETID_VIDCAP_VIDEOCONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videocontrol)