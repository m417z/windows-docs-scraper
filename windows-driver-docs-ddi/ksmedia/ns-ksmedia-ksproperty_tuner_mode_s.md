## Description

The **KSPROPERTY_TUNER_MODE_S** structure describes the mode of a TV or radio tuner device.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Mode`

Specifies the current tuner mode. If the request is a Get request, the minidriver should return the current tuner mode. If the request is a Set request, the minidriver should switch the current tuner mode to the specified value. This member can be one of the following tuner modes from the KSPROPERTY_TUNER_MODES enumeration that is defined in *Ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_TUNER_MODE_TV | Indicates that the tuner is currently tuning (get) or should switch to tuning broadcast or cable television channels (set). |
| KSPROPERTY_TUNER_MODE_FM_RADIO | Indicates that the tuner is currently tuning (get) or should switch to tuning (set) FM radio channels. |
| KSPROPERTY_TUNER_MODE_AM_RADIO | Indicates that the tuner is currently tuning (get) or should switch to tuning (set) AM radio channels. |
| KSPROPERTY_TUNER_MODE_DSS | Indicates that the tuner is currently tuning (get) or should switch to tuning (set) tuning DSS channels. |
| KSPROPERTY_TUNER_MODE_ATSC | Indicates that the tuner is capable of tuning (get) or should switch to tuning (set) Advanced Television Systems Committee broadcasts (Digital TV for the United States). This setting can also be used by DVB-T and DVB-C systems. |

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_MODE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-mode)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)