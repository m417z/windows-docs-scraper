## Description

The KSPROPERTY_TVAUDIO_CAPS_S structure describes the capability of a TV audio device, such as stereo versus mono audio support and language capabilities.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Capabilities`

Specifies the capabilities of the TV audio device. The minidriver returns the capabilities of the TV audio device by setting this member to one or more (logically ORed) values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KS_TVAUDIO_MODE_MONO | Indicates the device supports mono audio. |
| KS_TVAUDIO_MODE_STEREO | Indicates the device supports stereo audio. |
| KS_TVAUDIO_MODE_LANG_A | Indicates the device supports a primary (default) language. |
| KS_TVAUDIO_MODE_LANG_B | Indicates the device supports a second language. |
| KS_TVAUDIO_MODE_LANG_C | Indicates the device supports a third language. |

### `InputMedium`

Reserved for system use.

### `OutputMedium`

Reserved for system use.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TVAUDIO_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tvaudio-caps)

[PROPSETID_VIDCAP_TVAUDIO](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-tvaudio)