# TSPI_lineBlindTransfer function

## Description

The
**TSPI_lineBlindTransfer** function performs a blind or single-step transfer of the specified call to the specified destination address.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call to be transferred. The call state of *hdCall* can be *connected*.

### `lpszDestAddress`

A pointer to a null-terminated Unicode string identifying where the call is to be transferred to. The destination address uses the standard dialable number format.

### `dwCountryCode`

The country or region code of the destination. The implementation should use this to select the call progress protocols for the destination address. If a value of 0 is specified, the service provider should use a default. TAPI does not validate *dwCountryCode* when this function is called.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESS, LINEERR_OPERATIONFAILED, LINEERR_ADDRESSBLOCKED, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCOUNTRYCODE.

## Remarks

The service provider carries out no dialing if it returns LINEERR_INVALADDRESS.

Blind transfer differs from a consultation transfer in that no consultation call is made visible to TAPI. Typically, after the blind transfer successfully completes, the specified call is cleared from the line it was on and transitions to the *idle* state. The service provider's call handle must remain valid after the transfer has completed. TAPI causes this handle to be invalidated when it is no longer interested in the transferred call using
[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall).

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall)