# LINEMEDIACONTROLMEDIA structure

## Description

The
**LINEMEDIACONTROLMEDIA** structure describes a media action to be executed when detecting a media type change. It is used as an entry in an array. The
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) and
[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol) functions use this structure.

## Members

### `dwMediaModes`

One or more media types. This member uses one of the
[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

### `dwDuration`

Duration of time during which the media type should be present before the application should be notified or media control action should be taken, in milliseconds.

### `dwMediaControl`

Media control action. This member uses one of the
[LINEMEDIACONTROL_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediacontrol--constants).

## Remarks

This structure may not be extended.

The
**LINEMEDIACONTROLMEDIA** structure defines a triple \<media type(s), duration, media-control action>. An array of these triples is passed to the
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) function to set the media control actions triggered by media type changes for a given call. When a change to a listed media type is detected, then the corresponding action on the media stream is invoked.

## See also

[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol)

[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol)