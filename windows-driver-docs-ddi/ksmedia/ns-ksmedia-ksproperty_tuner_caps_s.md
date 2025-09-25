## Description

The **KSPROPERTY_TUNER_CAPS_S** structure describes the hardware capabilities of TV and radio tuning devices.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `ModesSupported`

Specifies a bitwise OR of the supported tuner modes. This member may be set to one or more of the following values from the KSPROPERTY_TUNER_MODES enumeration that is defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_TUNER_MODE_TV | Indicates that the tuner is capable of tuning analog broadcast or cable television channels. |
| KSPROPERTY_TUNER_MODE_FM_RADIO | Indicates that the tuner is capable of tuning FM radio channels. |
| KSPROPERTY_TUNER_MODE_AM_RADIO | Indicates that the tuner is capable of tuning AM radio channels. |
| KSPROPERTY_TUNER_MODE_DSS | Indicates that the tuner is capable of tuning DSS channels. |
| KSPROPERTY_TUNER_MODE_ATSC | Indicates that the tuner is capable of tuning digital television channels. This setting can be used for ATSC, DVB-C, or DVB-T television reception. |

### `VideoMedium`

Specifies a unique GUID representing the hardware connection of the analog video signal. This value enforces connections between filters. Possible values are **NULL**, indicating that no pin is created; GUID_NULL, indicating that Medium is not used to enforce connections; or a GUID. If a GUID value is used, only crossbar pins with a matching Medium GUID are allowed to connect.

### `TVAudioMedium`

Specifies a unique GUID representing the hardware connection of the TV audio signal. This value enforces connections between filters. Possible values are **NULL**, indicating that no pin is created; GUID_NULL, indicating that Medium is not used to enforce connections; or a GUID. If a GUID value is used, only crossbar pins with a matching Medium GUID are allowed to connect.

### `RadioAudioMedium`

Specifies a unique GUID representing the hardware connection of the analog radio audio signal. This value enforces connections between filters. Possible values are **NULL**, indicating that no pin is created; GUID_NULL, indicating that Medium is not used to enforce connections; or a GUID. If a GUID value is used, only crossbar pins with a matching Medium GUID are allowed to connect.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-caps)

[KSPROPERTY_TUNER_IF_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-if-medium)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)