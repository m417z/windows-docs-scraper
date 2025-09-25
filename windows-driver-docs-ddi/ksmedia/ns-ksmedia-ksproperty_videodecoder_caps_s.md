# KSPROPERTY_VIDEODECODER_CAPS_S structure

## Description

The KSPROPERTY_VIDEODECODER_CAPS_S structure describes the hardware capabilities of the video decoder device.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `StandardsSupported`

Specifies the video standards supported by the device. This member may be set to one or more (logically ORed) values from the [KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard) enumeration.

### `Capabilities`

Specifies video decoder capabilities. This member must be set to zero or one of the values from the [KS_VIDEODECODER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_videodecoder_flags) enumeration.

### `SettlingTime`

Specifies the settling time when changing input video sources. This value is expressed in milliseconds.

### `HSyncPerVSync`

Specifies the number of horizontal sync pulses the video decoder produces during the vertical sync period. Decoders that follow the ITU_656 should set this value to six.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_VIDEODECODER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-videodecoder-caps)

[KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard)

[KS_VIDEODECODER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_videodecoder_flags)

[PROPSETID_VIDCAP_VIDEODECODER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videodecoder)