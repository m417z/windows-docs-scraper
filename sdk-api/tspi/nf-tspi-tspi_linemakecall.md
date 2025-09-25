# TSPI_lineMakeCall function

## Description

The
**TSPI_lineMakeCall** function places a call on the specified line to the specified destination address. Optionally, call parameters can be specified if anything but default call setup parameters are requested.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The handle to the line on which the new call is to be originated.

### `htCall`

The TAPI handle to the new call. The service provider must save this and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the call.

### `lphdCall`

A pointer to a call handle. The service provider must fill this location with its handle for the call before this procedure returns. This handle is ignored by TAPI if the function results in an error.

### `lpszDestAddress`

Pointer to a null-terminated Unicode string that specifies the destination address. This follows the standard dialable number format. This pointer can be specified as NULL for non-dialed addresses (as with a hot phone, which always automatically connects to a predefined number) or when all dialing is performed using
[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial). In the latter case,
**TSPI_lineMakeCall** allocates an available call appearance that would typically remain in the *dialtone* state until dialing begins. Service providers that have inverse multiplexing capabilities can allow an application to specify multiple addresses at once.

### `dwCountryCode`

The country or region code of the called party. If a value of 0 is specified, a default is used by the implementation.

### `lpCallParams`

A pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure. This structure allows TAPI to specify how it wants the call to be set up. If NULL is specified, a default 3.1kHz voice call is established, and an arbitrary origination address on the line is selected. This structure selects elements such as the call's bearer mode, data rate, expected media type, origination address, blocking of caller ID information, and dialing parameters.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_ADDRESSBLOCKED, LINEERR_INVALLINESTATE, LINEERR_BEARERMODEUNAVAIL, LINEERR_INVALRATE, LINEERR_CALLUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_DIALBILLING, LINEERR_INVALADDRESS, LINEERR_DIALQUIET, LINEERR_INVALADDRESSID, LINEERR_DIALDIALTONE, LINEERR_INVALCALLPARAMS, LINEERR_DIALPROMPT, LINEERR_NOMEM, LINEERR_INUSE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALBEARERMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCOUNTRYCODE, LINEERR_RATEUNAVAIL, LINEERR_INVALMEDIAMODE, LINEERR_USERUSERINFOTOOBIG.

## Remarks

The service provider returns LINEERR_INVALLINESTATE if the line is currently not in a state in which this operation can be performed. A list of currently valid operations can be found in the **dwLineFeatures** member (of the type **LINEFEATURE**) in the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure. (Calling
[TSPI_lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetlinedevstatus) updates the information in
**LINEDEVSTATUS**.)

If the service provider returns LINEERR_DIALBILLING, LINEERR_DIALQUIET, LINEERR_DIALDIALTONE, or LINEERR_DIALPROMPT, it should perform none of the actions otherwise performed by
**TSPI_lineMakeCall**. For example, no partial dialing, and no going offhook. This is because the service provider should pre-scan the number for unsupported characters first.

After
**TSPI_lineMakeCall** returns a SUCCESS reply callback message to the application, the service provider must send
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) messages to the *lpfnEventProc* passed in
[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen) to notify TAPI about the progress of the call. A typical reported sequence may be dial tone, dialing, proceeding, ringback, and *connected*; The first state reported is not necessarily LINECALLSTATE_DIALTONE. The service provider chooses how many of these states are reported. It is recommended that as many as possible are sent, so that applications can take appropriate actions.

The service provider initially does media monitoring on the new call for at least the set of media types that were monitored for on the line.

If the dial string is NULL, the service provider takes the line to the *dialtone* state (for a Comm-based service provider, this would involve ATD) and send a call-state message indicating LINECALLSTATE_DIALTONE.

If the dial string ends in ';' (a semicolon), the service provider dials the partial number and sends the LINECALLSTATE_DIALING message. This call is completed by calls to
[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial).

If the dial string contains characters (W, @, $, ?) that are not supported by the service provider, the service provider must scan the dial string and return (synchronously) an error corresponding to the first invalid character.

If the LINECALLPARAMFLAGS_IDLE flag is set, the service provider must check the current line status (the equivalent of going off-hook and sensing dial tone). If this IDLE flag is set and there is no dial tone, the function fails with the error LINEERR_CALLUNAVAIL. If the IDLE flag is not set, or there is a dial tone, the dialing can continue.

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) message reports success. It must not issue any
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) messages for the new call or include it in call counts in messages or status data structures for the line.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial)

[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop)