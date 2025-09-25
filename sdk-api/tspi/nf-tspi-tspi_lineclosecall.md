# TSPI_lineCloseCall function

## Description

The
**TSPI_lineCloseCall** function deallocates the call after completing or aborting all outstanding asynchronous operations on the call.

## Parameters

### `hdCall`

The service provider's handle to the call to be closed. After the call is successfully closed, this handle is no longer valid. The call state can be any state.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provider must report completion for asynchronous operations. If
**TSPI_lineCloseCall** is called for a call on which there are outstanding asynchronous operations, the operations should be reported complete with an appropriate result or error code before this procedure returns. After this procedure returns, the service provider must report no further events on the call. The service provider's handles for the line and calls on the line become "invalid."

TAPI does not call
**TSPI_lineCloseCall** if a service provider synchronously returns an error from a call to the
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) function. But TAPI does call
**TSPI_lineCloseCall** if the service provider returns an error from the asynchronous operation initiated by
**TSPI_lineMakeCall**.

If there is an active call on the line at the time of
**TSPI_lineCloseCall**, the call must be dropped if this behavior is indicated by the LINEDEVCAPFLAGS_CLOSEDROP bit in the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

If the service provider can determine that there is another agent sharing control of the call, such as in a party line situation with a separate handset, the service provider simply lets control of the call pass to the other agent rather than forcibly dropping it.

This function should always succeed except in extraordinary circumstances. Most callers will probably ignore the return code because they will be unable to compensate for any error that occurs. The specified return values are more advisory for development diagnostic purposes than anything else.

This function is called when the last application with a handle to this call executes
[lineDeallocateCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedeallocatecall).

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall)