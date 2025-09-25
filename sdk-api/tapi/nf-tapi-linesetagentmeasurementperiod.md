# lineSetAgentMeasurementPeriod function

## Description

The
**lineSetAgentMeasurementPeriod** function sets the measurement period associated with a particular agent. It generates a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message to be sent to a registered proxy function handler, referencing a
[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest) structure of type LINEPROXYREQUEST_SETAGENTMEASUREMENTPERIOD.

## Parameters

### `hLine`

Handle to the line device.

### `hAgent`

Identifier of the agent whose information is to be changed.

### `dwMeasurementPeriod`

New measurement period (seconds). Must be greater than zero.

## Return value

Returns a request identifier if the asynchronous operation starts; otherwise, the function returns one of the following error values:

LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)