# LINEGENERATETONE structure

## Description

The
**LINEGENERATETONE** structure contains information about a tone to be generated. This structure is used by the
[lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratetone) and
[TSPI_lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegeneratetone) functions.

## Members

### `dwFrequency`

Frequency of this tone component, in hertz. A service provider may adjust (round up or down) the frequency specified by the application to fit its resolution.

### `dwCadenceOn`

Length of the "on" duration of the cadence of the custom tone to be generated, in milliseconds. Zero means no tone is generated.

### `dwCadenceOff`

Length of the "off" duration of the cadence of the custom tone to be generated, in milliseconds. Zero means no off time, that is, a constant tone.

### `dwVolume`

Volume level at which the tone is to be generated. A value of 0x0000FFFF represents full volume, and a value of 0x00000000 is silence.

## Remarks

This structure may not be extended.

This structure is used only for the generation of tones. It is not used for tone monitoring.

## See also

[TSPI_lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegeneratetone)

[lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratetone)