# TAPI_CUSTOMTONE structure

## Description

The
**TAPI_CUSTOMTONE** structure contains the parameters that define a custom tone.

## Members

### `dwFrequency`

The frequency, in hertz, of the tone.

### `dwCadenceOn`

The "on" duration, in milliseconds, of the cadence of a custom tone.

### `dwCadenceOff`

The "off" duration, in milliseconds, of the cadence of a custom tone.

### `dwVolume`

The volume level at which to generate the tone.

## See also

[ITLegacyCallMediaControl2::GenerateCustomTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtones)

[ITLegacyCallMediaControl2::GenerateCustomTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtonesbycollection)

[LINEGENERATETONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linegeneratetone)