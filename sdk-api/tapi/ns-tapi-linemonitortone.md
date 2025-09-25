# LINEMONITORTONE structure

## Description

The
**LINEMONITORTONE** structure describes a tone to be monitored. This is used as an entry in an array. The
[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones) and
[TSPI_lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemonitortones) functions use this structure.

## Members

### `dwAppSpecific`

Used by the application for tagging the tone. When this tone is detected, the value of the **dwAppSpecific** member is passed back to the application.

### `dwDuration`

Duration of time during which the tone should be present before a detection is made, in milliseconds.

### `dwFrequency1`

First frequency of the tone, in hertz.

### `dwFrequency2`

Second frequency of the tone, in hertz.

### `dwFrequency3`

Third frequency of the tone, in hertz. If fewer than three frequencies are needed in the tone, a value of 0 should be used for the unused frequencies. A tone with all three frequencies set to zero is interpreted as silence and can be use for silence detection.

## Remarks

This structure may not be extended.

The
**LINEMONITORTONE** structure defines a tone for the purpose of detection. An array of tones is passed to the
[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones) function which monitors these tones and sends a LINE_MONITORTONE message to the application when a detection is made.

A tone with all frequencies set to zero corresponds to silence. An application can thus monitor the call's information stream for silence.

## See also

[LINE_MONITORTONE](https://learn.microsoft.com/windows/desktop/Tapi/line-monitortone)

[TSPI_lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemonitortones)

[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones)