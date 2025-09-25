# TSPI_lineSetCallTreatment function

## Description

The
**TSPI_lineSetCallTreatment** function service provider stores the indicated *dwCallTreatment* in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo), and sends a
[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85)) message to indicate the updated information. If the call is currently in a state where the call treatment is relevant, the new treatment goes into effect at once; otherwise, it goes into effect the next time the call enters a relevant state.

## Parameters

### `dwRequestID`

Identifier for reporting asynchronous function results.

### `hdCall`

The service provider's handle to the call.

### `dwTreatment`

One of the call treatment identifiers supported on the address on which the call appears.

## Return value

Returns **dwRequestID** if the asynchronous operation starts; otherwise, one of these negative error values:

LINEERR_INVALCALLSTATE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_RESOURCEUNAVAIL.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85))