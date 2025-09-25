# TSPI_lineClose function

## Description

The
**TSPI_lineClose** function closes the specified open line device after completing or aborting all outstanding calls and asynchronous operations on the device.

## Parameters

### `hdLine`

The service provider's handle to the line to be closed. After the line is successfully closed, this handle is no longer valid.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provider must report completion for every asynchronous operation. If
**TSPI_lineClose** is called for a line on which there are outstanding asynchronous operations, the operations are reported complete with an appropriate result or error code before this procedure returns.

A similar requirement exists for active calls on the line. Outstanding operations must be reported complete with appropriate result or error codes. Active calls must also be dropped, if required, and if this behavior was indicated by the LINEDEVCAPFLAGS_CLOSEDROP bit in the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.

After this procedure returns, the service provider must report no further *htCall* on the line or calls that were on the line. The service provider's handles for the line and calls on the line become "invalid."

The service provider must relinquish nonsharable resources it reserves while the line is open. For example, closing a line accessed through a comm port and modem should result in closing the comm port, making it once again available for use by other applications.

The service provider does not issue the
[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85)) message in response to this function invocation because the line closes and there is no longer any interest in its state changes.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_CLOSE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725220(v=vs.85))

[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85))