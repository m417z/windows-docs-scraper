# lineHold function

## Description

The
**lineHold** function places the specified call on hold.

## Parameters

### `hCall`

Handle to the call to be placed on hold. The application must be an owner of the call. The call state of *hCall* must be *connected*.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_NOTOWNER, LINEERR_UNINITIALIZED.

## Remarks

The call on hold is temporarily disconnected allowing the application to use the line device for making or answering other calls. The
**lineHold** function performs a so-called "hard hold" of the specified call (as opposed to a "consultation call"). A call on hard hold typically cannot be transferred or included in a conference call, but a consultation call can. Consultation calls are initiated using
[lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetuptransfer),
[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference), or
[linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineprepareaddtoconference).

After a call has been successfully placed on hold, the call state typically transitions to *onHold*. A held call is retrieved by
[lineUnhold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunhold). While a call is on hold, the application can receive
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) messages about state changes of the held call. For example, if the held party hangs up, the call state can transition to *disconnected*.

In a bridged situation, a
**lineHold** operation may possibly not actually place the call on hold, because the status of other stations on the call can govern (for example, attempting to "hold" a call when other stations are participating is not be possible); instead, the call can simply be changed to the LINECONNECTEDMODE_INACTIVE mode if it remains *connected* at other stations.

## See also

[Hold Overview](https://learn.microsoft.com/windows/desktop/Tapi/hold-ovr)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineprepareaddtoconference)

[lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetupconference)

[lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetuptransfer)

[lineUnhold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineunhold)