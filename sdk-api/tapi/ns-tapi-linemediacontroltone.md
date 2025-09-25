# LINEMEDIACONTROLTONE structure

## Description

The
**LINEMEDIACONTROLTONE** structure describes a media action to be executed when a tone has been detected. It is used as an entry in an array. The
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) and
[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol) functions use this structure.

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

### `dwMediaControl`

Media control action. This member uses one of the
[LINEMEDIACONTROL_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediacontrol--constants).

## Remarks

This structure may not be extended.

The
**LINEMEDIACONTROLTONE** structure defines a tuple <tone, media-control action>. An array of these tuples is passed to the
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) function to set media control actions triggered by media type changes for a given call. When a change to a listed media type is detected, the corresponding action on the media stream is invoked.

A tone with all frequencies set to zero corresponds to silence. An application can thus monitor the call's information stream for silence.

## See also

[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol)

[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol)