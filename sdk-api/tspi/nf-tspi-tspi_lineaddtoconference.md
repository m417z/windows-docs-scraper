# TSPI_lineAddToConference function

## Description

The
**TSPI_lineAddToConference** function adds the call specified by *hdConsultCall* to the conference call specified by *hdConfCall*.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdConfCall`

The handle to the conference call. The call state of *hdConfCall* can be *onHoldPendingConference* or *onHold*.

### `hdConsultCall`

The handle to the call to be added to the conference call. This call cannot be either a parent of another conference or a participant in any conference. Depending on the device capabilities indicated in
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps), the *hdConsultCall* parameter may not necessarily have been established using
[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference) or
[TSPI_linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineprepareaddtoconference). The call state of *hdConsultCall* can be *connected*, *onHold*, *proceeding*, or *ringback*.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_CONFERENCEFULL, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM.

## Remarks

The service provider returns LINEERR_INVALCALLHANDLE if *hdConsultCall* is a parent of another conference or already a participant in a conference, or *hdConsultCall* cannot be added for other reasons, such as it must have been established using
[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference) or
[TSPI_linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineprepareaddtoconference).

**Note** The call handle of the added party remains valid after adding the call to a conference; typically, its state changes to *conferenced* while the state of the conference call becomes *connected*. The handle to an individual participating call can be used later to remove that party from the conference call using
[TSPI_lineRemoveFromConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineremovefromconference).

The call states of the calls participating in a conference are not independent. For example, when dropping a conference call, all participating calls can automatically become *idle*. TAPI can consult the line's device capabilities to determine what form of conference removal is available. TAPI or its client applications should track the
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) messages to determine what happened to the calls involved.

The conference call is established either through
[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference) or
[TSPI_lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecompletetransfer). Typically, the call added to a conference is established using
**TSPI_lineSetupConference** or
[TSPI_linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineprepareaddtoconference). Some switches may allow adding of an arbitrary call to conference, and such a call may have been set up using
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) and be on (hard) hold. All calls that are part of a conference must exist on the same open line.

Any monitoring (media, tones, digits) on a conference call applies only to the *hdConfCall* parameter, not to the individual participating calls.

This function has no restrictions based on privilege as in the corresponding function at the TAPI level. There is no explicit requirement for the service provider to track the relationships between the "parent" conference call and its participants, because there is no TSPI correspondence to the TAPI function. Many service providers may find it necessary to track these relationships internally to implement the other conference call management functions.

## See also

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecompletetransfer)

[TSPI_linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineprepareaddtoconference)

[TSPI_lineRemoveFromConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineremovefromconference)

[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference)