# KSPROPERTY_TUNER_FREQUENCY_S structure

## Description

The KSPROPERTY_TUNER_FREQUENCY_S structure describes the frequency of a TV or radio tuner device.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `Frequency`

Specifies the frequency of the tuner. If the request is a Get request, the minidriver returns the current frequency of the tuner. If the request is a Set request, the minidriver should set the frequency of the tuner to the specified value. This value is specified in hertz (Hz).

### `LastFrequency`

Specifies the last frequency tuned.

### `TuningFlags`

Specifies tuning flags that describe the granularity of a tuning operation. If the request is a Get request, the minidriver returns the current tuning flags. If the request is a Set request, the minidriver should use the specified tuning method. This member must be set to one of the values from the [KS_TUNER_TUNING_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_tuner_tuning_flags) enumeration.

### `VideoSubChannel`

Specifies the video subchannel of a digital television source. If the request is a Get request, the minidriver should return the video subchannel for the digital television source to the specified value. If the request is a Set request, the minidriver should set the video subchannel for the digital television source. This member is only used by devices that support the DSS tuner mode (KSPROPERTY_TUNER_MODE_DSS).

### `AudioSubChannel`

Specifies the audio subchannel of a digital television source. If the request is a Get request, the minidriver should return the audio subchannel for the digital television source. If the request is a Set request, the minidriver should set the audio subchannel for the digital television source. This member is only used by devices that support the DSS tuner mode (KSPROPERTY_TUNER_MODE_DSS).

### `Channel`

Specifies the video subchannel of a digital television source. If the request is a Get request, the minidriver should return the video subchannel for the digital television source to the specified value. If the request is a Set request, the minidriver should set the video subchannel for the digital television source. This member is only used by devices that support the DSS tuner mode (KSPROPERTY_TUNER_MODE_DSS).

### `Country`

Specifies the current country code for the tuning operation. Country codes follow the Telephony API (TAPI) region code values that correspond to the international long distance dialing codes.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-frequency)

[KS_TUNER_TUNING_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_tuner_tuning_flags)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)