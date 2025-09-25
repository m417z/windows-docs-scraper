# KSPROPERTY_VIDEOCONTROL_CAPS_S structure

## Description

The KSPROPERTY_VIDEOCONTROL_CAPS_S structure describes the video-control capabilities of a minidriver, such as image flipping or event triggering abilities.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `StreamIndex`

Contains the zero-based index of the stream.

### `VideoControlCaps`

Indicates the video control capabilities for the specified stream. This member must be set to one or more (logically ORed) values from the [KS_VideoControlFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_videocontrolflags) enumeration.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEOCONTROL_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocontrol-caps)

[KSPROPERTY_VIDEOCONTROL_MODE_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videocontrol_mode_s)

[KS_VideoControlFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_videocontrolflags)

[PROPSETID_VIDCAP_VIDEOCONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videocontrol)