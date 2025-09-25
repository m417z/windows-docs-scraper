# TSPI_lineSetupConference function

## Description

The
**TSPI_lineSetupConference** function sets up a conference call for the addition of the third party.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the initial call that identifies the first party of a conference call. In some environments, a call must exist in order to start a conference call. In other telephony environments, no call initially exists and *hdCall* is left **NULL**. The call state of *hdCall* can be *connected*.

### `hdLine`

The handle to the line device on which to originate the conference call if *hdCall* is **NULL**. The *hdLine* parameter is ignored if *hdCall* is non-**NULL**. The service provider reports which model it supports through the **setupConfNull** flag of the
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) data structure.

### `htConfCall`

The TAPI handle to the new conference call. The service provider must save this and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the new call.

### `lphdConfCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for the newly created conference call. The service provider must fill this location with its handle for the new call before this procedure returns. This handle is ignored by TAPI if the function results in an error. The call state of *hdConfCall* is not applicable.

### `htConsultCall`

The TAPI handle to the consultation call. When setting up a call for the addition of a new party, a new temporary call (consultation call) is automatically allocated. The service provider must save the *htConsultCall* and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the new consultation call.

### `lphdConsultCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for a call. When setting up a call for the addition of a new party, a new temporary call (consultation call) is automatically allocated. The service provider must fill this location with its handle for the new consultation call before this procedure returns. This handle is ignored by TAPI if the function results in an error. The call state of *hdConsultCall* is not applicable.

### `dwNumParties`

The expected number of parties in the conference call. The service provider is free to do with this number as it pleases. For example, the service provider can ignore it, or use it as a hint to allocate the right size conference bridge inside the switch. TAPI does not validate this parameter when this function is called.

### `lpCallParams`

A pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure containing call parameters to use when establishing the consultation call. This parameter is set to **NULL** if no special call setup parameters are desired and the service provider uses default parameters.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_INVALADDRESSMODE, LINEERR_INVALLINEHANDLE, LINEERR_INVALBEARERMODE, LINEERR_INVALCALLSTATE, LINEERR_INVALCALLPARAMS, LINEERR_CALLUNAVAIL, LINEERR_INVALLINESTATE, LINEERR_CONFERENCEFULL, LINEERR_INVALMEDIAMODE, LINEERR_NOMEM, LINEERR_INVALRATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INUSE, LINEERR_OPERATIONFAILED, LINEERR_RATEUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_USERUSERINFOTOOBIG, LINEERR_BEARERMODEUNAVAIL.

## Remarks

The service provider returns LINEERR_INVALLINEHANDLE if the specified line handle for the line containing the conference call is invalid. This error can also indicate that the telephony environment requires an initial line to set up a conference but a non-**NULL** call handle was supplied instead.

The service provider returns LINEERR_INVALCALLHANDLE if the telephony environment requires an initial call to set up a conference but a **NULL** call handle was supplied instead.

**TSPI_lineSetupConference** provides two ways to establish a new conference call, depending on whether a normal two-party call is required to pre-exist or not. When setting up a conference call from an existing two-party call, the *hdCall* parameter is a valid call handle that is initially added to the conference call by the
**TSPI_lineSetupConference** request and *hdLine* is ignored. On switches where conference call setup does not start with an existing call, *hdCall* must be **NULL** and *hdLine* must be specified to identify the line device on which to initiate the conference call. In either case, a consultation call is allocated for connecting to the party that is to be added to the call. TAPI can use
[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial) to dial the address of the other party.

The conference call typically transitions into the *onHoldPendingConference* state, the consultation call *dialtone* state and the initial call (if one) into the *conferenced* state.

A conference call can also be set up using a
[TSPI_lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecompletetransfer) function that is resolved into a three-way conference.

TAPI may be able to toggle between the consultation call and the conference call using
[TSPI_lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineswaphold).

The
[TSPI_lineUnhold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunhold) function can recover calls that have the call state *onHoldPendingConference*. If this is done, any consultation call typically goes to the *idle* state.

A consultation call can be canceled by invoking
[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop) on it. When dropping a consultation call, the existing conference call typically transitions back to the *connected* state. TAPI and its client applications should observe the
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) messages to determine exactly what happens to the calls. For example, if the conference call reverts back to a regular two-party call, the conference call becomes *idle* and the original participant call may revert to *connected*.

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) message reports success. In other words, it must not issue any
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) messages for the new call or include it in call counts in messages or status data structures for the line.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEADDRCAPFLAGS_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrcapflags--constants)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineaddtoconference)

[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial)

[TSPI_linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineprepareaddtoconference)

[TSPI_lineRemoveFromConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineremovefromconference)

[TSPI_lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineswaphold)