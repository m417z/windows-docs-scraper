# LINEMEDIACONTROLCALLSTATE structure

## Description

The
**LINEMEDIACONTROLCALLSTATE** structure describes a media action to be executed when detecting transitions into one or more call states. The
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) and
[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol) functions use this structure.

## Members

### `dwCallStates`

One or more call states. This member uses one of the
[LINECALLSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallstate--constants).

### `dwMediaControl`

Media control action. This member uses one of the
[LINEMEDIACONTROL_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediacontrol--constants).

## Remarks

This structure may not be extended.

The
**LINEMEDIACONTROLCALLSTATE** structure defines a triple \<call state(s), media-control action>. An array of these triples is passed to the
[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol) function to set the media control actions triggered by the transition to the call state of the given call. When a transition to a listed call state is detected, the corresponding action on the media stream is invoked.

## See also

[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol)

[lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits)

[lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetmediacontrol)