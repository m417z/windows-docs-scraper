# KSPROPERTY_VIDEOCONTROL_FRAME_RATES_S structure

## Description

The KSPROPERTY_VIDEOCONTROL_FRAME_RATES structure describes available frame rates in 100-nanosecond units.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `StreamIndex`

Contains the zero-based index of the stream.

### `RangeIndex`

Contains the zero-based index into the range list. The value at this location specifies the range in which frame rate information is being requested.

### `Dimensions`

Specifies the width and height of the image.

## Remarks

The minidriver should return a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) structure containing a list of the frame rates supported. These values should be expressed using type VT_I4.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[PROPSETID_VIDCAP_VIDEOCONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videocontrol)