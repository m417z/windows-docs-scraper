# TSPI_lineRemoveFromConference function

## Description

The
**TSPI_lineRemoveFromConference** function removes the specified call from the conference call to which it currently belongs. The remaining calls in the conference call are unaffected.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call to be removed from the conference. The call state of *hdCall* can be *conferenced*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

This operation removes a party that currently belongs to a conference call. After the call has been successfully removed, it may be possible to further manipulate it using its handle. The availability of this operation and its result are likely to be limited in many implementations. For example, in many implementations, only the most recently added party can be removed from a conference, and the removed call may be automatically dropped (becomes *idle*). The service provider indicates its capabilities in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) with regard to the available effects of removing a call from a conference.

If the removal of a participant from a conference is supported, the service provider must indicate in the **dwRemoveFromConfState** member in
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) the call state to which the call transitions after it is removed from the conference.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineaddtoconference)

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)

[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference)