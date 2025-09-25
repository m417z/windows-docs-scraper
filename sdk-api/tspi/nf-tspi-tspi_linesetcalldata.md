# TSPI_lineSetCallData function

## Description

The
**TSPI_lineSetCallData** function service provider stores the indicated call data with its information related to the call, and subsequently delivers it whenever
[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo) is called. The service provider sends a
[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85)) message indicating LINECALLINFOSTATE_CALLDATA to show that the call data has changed. Depending on the service provider implementation, the call data can be propagated to all entities having handles to the call, including those on other machines (through the server), and can travel with the call when it is transferred.

## Parameters

### `dwRequestID`

Identifier for reporting asynchronous completion information.

### `hdCall`

The service provider's handle to the call.

### `lpCallData`

Address of the data to be copied to the **CallData** field in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo), replacing any existing data.

### `dwSize`

Number of bytes of data to be copied. A value of zero causes any existing data to be removed. If the *lpCallData* parameter is a pointer to a string, the size must include the **null** terminator.

## Return value

Returns **dwRequestID** if the asynchronous operation starts; otherwise, one of these negative error values:

LINEERR_INVALCALLSTATE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_RESOURCEUNAVAIL.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85))

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)