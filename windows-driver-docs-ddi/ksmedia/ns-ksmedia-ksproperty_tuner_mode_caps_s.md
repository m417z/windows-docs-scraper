## Description

The **KS_PROPERTY_TUNER_MODE_CAPS_S** structure describes the capabilities of TV and radio tuner devices.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Mode`

Specifies the tuner mode that the caller is requesting capability information about. It can be one of the following tuner modes from the KSPROPERTY_TUNER_MODES enumeration that is defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_TUNER_MODE_TV | Indicates that the tuner is capable of tuning analog broadcast or cable television channels. |
| KSPROPERTY_TUNER_MODE_FM_RADIO | Indicates that the tuner is capable of tuning FM radio channels. |
| KSPROPERTY_TUNER_MODE_AM_RADIO | Indicates that the tuner is capable of tuning AM radio channels. |
| KSPROPERTY_TUNER_MODE_DSS | Indicates that the tuner is capable of tuning DSS channels. |
| KSPROPERTY_TUNER_MODE_ATSC | Indicates that the tuner is capable of tuning Advanced Television Systems Committee broadcasts (Digital TV for the United States) or other digital television standard. |

### `StandardsSupported`

Describes the analog video standards supported. If **Mode** is set to KSPROPERTY_TUNER_MODE_TV, this member may be set to one or more (logically ORed) values from the [KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard) enumeration.

### `MinFrequency`

Specifies the lowest frequency supported by the tuner. This value is in hertz (Hz).

### `MaxFrequency`

Specifies the highest frequency supported by the tuner. This value is in hertz (Hz).

### `TuningGranularity`

Specifies the smallest possible step size between two settings of the tuning frequency. This value is in hertz (Hz).

### `NumberOfInputs`

Specifies the number of inputs on the tuner.

### `SettlingTime`

Specifies the time, in milliseconds, for a new frequency setting to become stable.

### `Strategy`

Specifies the tuning method. This member must be set to only one of the values from the [**KS_TUNER_STRATEGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_tuner_strategy) enumeration.

## Remarks

The minidriver fills in the mode capabilities for the requested tuner mode.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_MODE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-mode-caps)

[**KS_AnalogVideoStandard**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard)

[**KS_TUNER_STRATEGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_tuner_strategy)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)