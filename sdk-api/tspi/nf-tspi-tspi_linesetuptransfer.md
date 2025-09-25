# TSPI_lineSetupTransfer function

## Description

The
**TSPI_lineSetupTransfer** function initiates a transfer of the call specified by *hdCall*. It establishes a consultation call, *lphdConsultCall*, on which the party can be dialed that can become the destination of the transfer.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call to be transferred. The call state of *hdCall* can be *connected*.

### `htConsultCall`

The TAPI handle to the new, temporary consultation call. The service provider must save this and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the new consultation call.

### `lphdConsultCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for the new consultation call. The service provider must fill this location with its handle for the new consultation call before this procedure returns. This handle is ignored by TAPI if the function results in an error. The call state of *hdConsultCall* is not applicable.

When setting a call up for transfer, another call (a consultation call) is automatically allocated to enable the application (through TAPI) to dial the address (using
[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial)) of the party to where the call is to be transferred. The originating party can carry on a conversation over this consultation call prior to completing the transfer.

This transfer procedure may not be valid for some line devices. Instead of calling this procedure, TAPI may need to unhold an existing held call (using
[TSPI_lineUnhold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunhold)) to identify the destination of the transfer. On switches that support cross-address call transfer, the consultation call can exist on a different address than the call to be transferred. It may also be necessary to set up the consultation call as an entirely new call using
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall), to the destination of the transfer.

The **transferHeld** and **transferMake** flags in the
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) data structure report what model the service provider uses.

### `lpCallParams`

A pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure containing call parameters to use when establishing the consultation call. This parameter can be set to **NULL** if no special call setup parameters are desired (the service provider uses defaults).

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_INVALBEARERMODE, LINEERR_INVALCALLSTATE, LINEERR_INVALRATE, LINEERR_CALLUNAVAIL, LINEERR_INVALCALLPARAMS, LINEERR_NOMEM, LINEERR_INVALLINESTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALMEDIAMODE, LINEERR_OPERATIONFAILED, LINEERR_INUSE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_BEARERMODEUNAVAIL, LINEERR_RATEUNAVAIL, LINEERR_INVALADDRESSMODE, LINEERR_USERUSERINFOTOOBIG.

## Remarks

The service provider returns LINEERR_INVALCALLSTATE if the call to be transferred is not in a valid state.

This operation sets up the transfer of the call specified by *hdCall*. The setup phase of a transfer establishes a consultation call to send the address of the destination (the party to be transferred to) to the switch, while the call to be transferred is kept on hold. This new call is referred to as a *consultation call* (*hdConsultCall*) and can be manipulated (for example, dropped) independently of the original call.

When the consultation call has reached the *dialtone* call state, TAPI can continue transferring the call either by dialing the destination address and tracking its progress, or by unholding an existing call. The transfer of the original call to the selected destination is completed using
[TSPI_lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecompletetransfer).

While the consultation call exists, the original call typically transitions to the *onholdPendingTransfer* state.

The
[TSPI_lineUnhold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunhold) function can recover calls that have the call state *onHoldPendingTransfer*. If this is done, any consultation call typically goes to the *idle* state.

In telephony environments that follow the **transferHeld** or **transferMake** transfer models, this procedure returns LINEERR_OPERATIONFAILED and does not allocate a consultation call handle.

A consultation call can be canceled by invoking
[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop) on it. After dropping a consultation call, the original call typically transitions back to the *connected* state.

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) message reports success. In other words, it must not issue any
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) messages for the new call or include it in call counts in messages or status data structures for the line.

## See also

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineblindtransfer)

[TSPI_lineCompleteTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecompletetransfer)

[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial)

[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop)

[TSPI_lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineswaphold)

[TSPI_lineUnhold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunhold)