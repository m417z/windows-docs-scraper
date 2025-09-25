# TSPI_lineMonitorMedia function

## Description

The
**TSPI_lineMonitorMedia** function enables and disables the detection of media types on the specified call. When a media type is detected, a
[LINE_MONITORMEDIA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725233(v=vs.85)) message is sent to TAPI.

## Parameters

### `hdCall`

The handle to the call for which media monitoring is to be set. The call state of *hdCall* can be any state except *idle*.

### `dwMediaModes`

The media types to be monitored. The *dwMediaModes* parameter can have one of the
[LINEMEDIAMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants).

A value of 0 cancels all media type monitoring.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALMEDIAMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM.

## Remarks

The service provider returns LINEERR_INVALMEDIAMODE if the list of media types to be monitored contains invalid information.

This function returns zero (success) when media type monitoring has been correctly initiated, not when media type monitoring has terminated. Media monitoring for a given media type remains in effect until it is explicitly disabled by calling
**TSPI_lineMonitorMedia** with a *dwMediaModes* parameter with the media type set to zero, or until the call transitions to *idle*.

**TSPI_lineMonitorMedia** is primarily an event reporting mechanism. The media type of a call, as indicated in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo), is not affected by the service provider's detection of the media type. Only TAPI or a client application can change a call's indicated media type using
[TSPI_lineSetMediaMode](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediamode). The actual use of a particular media type occurs through separate media stream APIs (such as Comm or WAVE).

Default media monitoring performed by the service provider for a new call appearance corresponds to the union of all media types specified by
[TSPI_lineSetDefaultMediaDetection](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdefaultmediadetection). Shortly after a new call is established, TAPI typically calls
**TSPI_lineMonitorMedia** to reduce the set of media types detected and reported for this call to the union of all media types desired by the call's client applications.

The service provider must cancel media monitoring when a call goes idle. TAPI must compute the union of media types desired by all clients, and pass the result to this function. The service provider uses the set passed to this function by TAPI.

Although this function can be invoked in any call state, a call's media type can typically only be detected while the call is in certain call states. These states can be device specific. For example, in ISDN a message can indicate the media type of the media stream before the media stream exists. Similarly, distinctive ringing or the called ID information about the call can be used to identify the media type of a call. Otherwise, the call may have to be answered (call in the *connected* state) to allow a service provider to determine the call's media type by filtering of the media stream. Because filtering of a call's media stream implies a computational overhead, TAPI typically uses this procedure to disable media monitoring when it is not required.

Because media-mode detection enabled by
**TSPI_lineMonitorMedia** is implemented as a read-only operation of the call's media stream, it is not disruptive. No signals are sent on the line as a result of setting
**TSPI_lineMonitorMedia**.

Regarding the passed media type, TAPI guarantees that there are no reserved bits set. The service provider must perform any further validity checks on the media types, such as checking whether any media types are indeed supported by the service provider.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants)

[LINE_MONITORMEDIA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725233(v=vs.85))

[TSPI_lineConditionalMediaDetection](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconditionalmediadetection)

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)

[TSPI_lineSetDefaultMediaDetection](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdefaultmediadetection)

[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol)

[TSPI_lineSetMediaMode](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediamode)