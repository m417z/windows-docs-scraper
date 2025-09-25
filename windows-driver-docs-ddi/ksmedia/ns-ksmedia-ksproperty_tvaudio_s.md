## Description

The **KSPROPERTY_TVAUDIO_S** structure describes the current TV audio mode, such as stereo or mono audio and language settings.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Mode`

Specifies the mode of the TV audio device. For Get requests, the minidriver returns the current mode of the TV audio device. For Set requests, the minidriver sets the current mode of the TV audio device to the specified value. This member can be one or more (logically ORed) of the following values:

| Mode | Meaning |
|---|---|
| KS_TVAUDIO_MODE_MONO | Indicates that the audio is in mono. |
| KS_TVAUDIO_MODE_STEREO | Indicates that the audio is in stereo. |
| KS_TVAUDIO_MODE_LANG_A | Indicates that the audio is in the primary language. |
| KS_TVAUDIO_MODE_LANG_B | Indicates that the audio is in the second language supported by the device. |
| KS_TVAUDIO_MODE_LANG_C | Indicates that the audio is in the third language supported by the device. |

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TVAUDIO_MODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tvaudio-mode)

[PROPSETID_VIDCAP_TVAUDIO](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-tvaudio)