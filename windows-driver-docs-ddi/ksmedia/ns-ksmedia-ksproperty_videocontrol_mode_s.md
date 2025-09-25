# KSPROPERTY_VIDEOCONTROL_MODE_S structure

## Description

The KSPROPERTY_VIDEOCONTROL_MODE_S structure describes video-control modes for a stream, such as image flipping or event triggering abilities.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `StreamIndex`

Contains the zero-based index of the stream.

### `Mode`

Specifies the video control mode. For a Set request, this member contains the requested video control mode. For a Get request, the minidriver should return the current video control mode of the device. This member can be one of the [KS_VideoControlFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_videocontrolflags) enumeration values.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEOCONTROL_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videocontrol_caps_s)

[KSPROPERTY_VIDEOCONTROL_MODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videocontrol-mode)

[KS_VideoControlFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_videocontrolflags)

[PROPSETID_VIDCAP_VIDEOCONTROL](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videocontrol)