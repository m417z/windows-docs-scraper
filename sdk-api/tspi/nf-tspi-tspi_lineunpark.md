# TSPI_lineUnpark function

## Description

The
**TSPI_lineUnpark** function retrieves the call parked at the specified address and returns a call handle for it.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The handle to the line on which a call is to be unparked.

### `dwAddressID`

The address on *hdLine* at which to originate the unpark. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades. TAPI does not validate this parameter when this function is called.

### `htCall`

The TAPI handle to the new unparked call. The service provider must save this and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the call.

### `lphdCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for the new unparked call. The service provider must fill this location with its handle for the call before this procedure returns. This handle is invalid if the function results in an error.

### `lpszDestAddress`

A pointer to a null-terminated Unicode string that contains the address where the call is parked. The address is in dialable address format.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_NOMEM, LINEERR_INVALPOINTER, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_INVALADDRESS, LINEERR_RESOURCEUNAVAIL.

## Remarks

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) message reports success. In other words, it must not issue any
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) messages for the new call or include it in call counts in messages or status data structures for the line.

The call handle created by this function is a new, distinct, call handle even if an original call handle for the call is still in existence (it has not been destroyed by
[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall)).

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall)

[TSPI_linePark](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linepark)