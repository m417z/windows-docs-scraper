# KSPROPERTY_VIDEOPROCAMP_S structure

## Description

The **KSPROPERTY_VIDEOPROCAMP_S** structure describes filter-based property settings in the PROPSETID_VIDCAP_VIDEOPROCAMP property set.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Value`

Specifies the value of a request. For Set requests, the minidriver should set the property specified in **Property** to this value. For Get requests, the minidriver should return the value of the property specified in **Property**.

### `Flags`

Specifies the flags of a request. For Set requests, this value indicates the desired setting. For Get requests, this value contains the current setting. This member can be set to one of the values that are defined in *ksmedia.h*:

| Flag | Meaning |
|--|--|
| KSPROPERTY_VIDEOPROCAMP_FLAGS_MANUAL | Indicates that the property is to be adjusted manually. |
| KSPROPERTY_VIDEOPROCAMP_FLAGS_AUTO | Indicates that the property is to be adjusted automatically. |

### `Capabilities`

Specifies the capabilities of a property. This member has meaning only for Get requests. The minidriver should return the capabilities of the VideoProcAmp with respect to the property specified in **Property**. This member should be set to one of the following values:

| Value | Meaning |
|--|--|
| KSPROPERTY_VIDEOPROCAMP_FLAGS_MANUAL | The device supports manual setting of the specified property. |
| KSPROPERTY_VIDEOPROCAMP_FLAGS_AUTO | The device supports automatic setting of the specified property. |

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEOPROCAMP_BACKLIGHT_COMPENSATION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-backlight-compensation)

[KSPROPERTY_VIDEOPROCAMP_BRIGHTNESS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-brightness)

[KSPROPERTY_VIDEOPROCAMP_COLORENABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-colorenable)

[KSPROPERTY_VIDEOPROCAMP_CONTRAST](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-contrast)

[KSPROPERTY_VIDEOPROCAMP_GAMMA](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-gamma)

[KSPROPERTY_VIDEOPROCAMP_HUE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-hue)

[KSPROPERTY_VIDEOPROCAMP_SATURATION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-saturation)

[KSPROPERTY_VIDEOPROCAMP_SHARPNESS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-sharpness)

[KSPROPERTY_VIDEOPROCAMP_WHITEBALANCE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videoprocamp-whitebalance)

[PROPSETID_VIDCAP_VIDEOPROCAMP](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp)