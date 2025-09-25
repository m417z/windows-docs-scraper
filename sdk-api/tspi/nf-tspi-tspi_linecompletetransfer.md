# TSPI_lineCompleteTransfer function

## Description

The
**TSPI_lineCompleteTransfer** function completes the transfer of the specified call to the party connected in the consultation call. If *dwTransferMode* is LINETRANSFERMODE_CONFERENCE, the original call handle is changed to a conference call. Otherwise, the service provider should send call state messages changing the calls to *idle*.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call to be transferred. The call state of *hdCall* can be *onHoldPendingTransfer*.

### `hdConsultCall`

A handle to the call that represents a connection to the destination of the transfer. The call state of *hdConsultCall* can be *connected*, *ringback*, *busy*, or *proceeding*.

### `htConfCall`

This parameter is only valid if *dwTransferMode* is specified as LINETRANSFERMODE_CONFERENCE. The service provider must save this parameter value and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the call. Otherwise this parameter is ignored.

### `lphdConfCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for the call. This parameter is only valid if *dwTransferMode* is specified as LINETRANSFERMODE_CONFERENCE. The service provider must fill this location with its handle for the new conference call before returning from this function.

### `dwTransferMode`

Specifies how the initiated transfer request is to be resolved. This parameter uses one of the
[LINETRANSFERMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linetransfermode--constants).

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

This function completes the transfer of the original call, *hdCall*, to the party currently connected through *hdConsultCall*. The consultation call is typically dialed on the consultation call allocated as part of
[TSPI_lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetuptransfer), but it can be any call to which the switch is capable of transferring *hdCall*.

The transfer request can be resolved either as a transfer or as a three-way conference call. When resolved as a transfer, the parties connected through *hdCall* and *hdConsultCall* are connected to each other, and both *hdCall* and *hdConsultCall* transition to the idle state.

When resolved as a conference, all three parties enter into a conference call. Both existing call handles remain valid, but transition to the *conferenced* state. A conference call handle is created and returned, and it transitions to the *connected* state.

It may also be possible to perform a blind transfer of a call using
[TSPI_lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineblindtransfer).

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) message reports success. In other words, it must not issue any
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) message for the new call or include it in call counts in messages or status data structures for the line.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINETRANSFERMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetransfermode--constants)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineblindtransfer)

[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall)

[TSPI_lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetuptransfer)