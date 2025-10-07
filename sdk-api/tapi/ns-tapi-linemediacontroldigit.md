# LINEMEDIACONTROLDIGIT structure

## Description

The
**LINEMEDIACONTROLDIGIT** structure describes a media action to be executed when detecting a digit. It is used as an entry in an array. The
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) and
[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol) functions use this structure.

## Members

### `dwDigit`

Low-order byte is the digit in whose detection is to trigger a media action. Valid digits depend on the media type.

### `dwDigitModes`

Digit mode(s) to monitor. This member uses one or more of the
[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants).

### `dwMediaControl`

Media control action. This member uses one of the
[LINEMEDIACONTROL_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediacontrol--constants).

## Remarks

This structure may not be extended.

The
[LINEMEDIACONTROLMEDIA](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolmedia) structure defines a triple \<digit, digit mode(s), media-control action>. An array of these triples is passed to the
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) function to set the media control actions triggered by digits detected on a given call. When a listed digit is detected, then the corresponding action on the media stream is invoked.

## See also

[LINEMEDIACONTROLMEDIA](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolmedia)

[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol)

[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol)