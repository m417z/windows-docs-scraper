# TAPI_DETECTTONE structure

## Description

The
**TAPI_DETECTTONE** structure describes a tone to be monitored. This is used as an entry in an array.

## Members

### `dwAppSpecific`

Used by the application for tagging the tone. When this tone is detected, the value of the **dwAppSpecific** member is passed back to the application.

### `dwDuration`

The duration, in milliseconds, during which the tone should be present before a detection is made.

### `dwFrequency1`

The frequency, in hertz, of a component of the tone.

### `dwFrequency2`

The frequency, in hertz, of a component of the tone.

### `dwFrequency3`

The frequency, in hertz, of a component of the tone. If fewer than three frequencies are needed in the tone, a value of zero should be used for the unused frequencies. A tone with all three frequencies set to zero is interpreted as silence and can be used for silence detection.

## See also

[ITLegacyCallMediaControl2::DetectTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttones)

[ITLegacyCallMediaControl2::DetectTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttonesbycollection)

[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone)