# TSPI_lineSetCallParams function

## Description

The
**TSPI_lineSetCallParams** function sets certain parameters for an existing call.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call whose parameters are to be changed. The call state can be any state except *idle* and *disconnected*.

### `dwBearerMode`

The new bearer mode for the call. The *dwBearerMode* parameter can have only one of the
[LINEBEARERMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linebearermode--constants).

### `dwMinRate`

A lower bound for the call's new data rate. TAPI can accept a new rate as low as this one. TAPI does not validate this parameter when this function is called.

### `dwMaxRate`

An upper bound for the call's new data rate. This is the maximum data rate TAPI would like. Equal values for *dwMinRate* and *dwMaxRate* indicate that an exact data rate is required. TAPI does not validate this parameter when this function is called.

### `lpDialParams`

A pointer to the new dial parameters for the call, of type
[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams). If this parameter is **NULL**, it indicates that the call's current dialing parameters are to be used.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_RATEUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_NOMEM, LINEERR_INVALBEARERMODE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALPOINTER, LINEERR_OPERATIONFAILED, LINEERR_INVALRATE, LINEERR_RESOURCEUNAVAIL, LINEERR_BEARERMODEUNAVAIL.

## Remarks

This operation is used to change the parameters of an existing call. Examples of its usage include changing the bearer mode and/or the data rate of an existing call.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams)

[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall)