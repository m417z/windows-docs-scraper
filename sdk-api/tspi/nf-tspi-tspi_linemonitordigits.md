# TSPI_lineMonitorDigits function

## Description

The
**TSPI_lineMonitorDigits** function enables and disables the unbuffered detection of digits received on the call. Each time a digit of the specified digit mode(s) is detected, a
[LINE_MONITORDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725232(v=vs.85)) message is sent to the application by TAPI, indicating which digit is detected.

## Parameters

### `hdCall`

The handle to the call on which digits are to be detected. The call state of *hdCall* can be any state except *idle* or *disconnected*.

### `dwDigitModes`

The digit mode(s) that are to be monitored. A *dwDigitModes* parameter with a value of 0 cancels digit monitoring. The *dwDigitModes* parameter can have one of the
[LINEDIGITMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants).

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALDIGITMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM.

## Remarks

This function returns zero (success) when digit monitoring is correctly initiated, not when digit monitoring is terminated. Digit monitoring remains in effect until it is explicitly disabled by a call to
**TSPI_lineMonitorDigits** with *dwDigitModes* set to zero, or until the call transitions to *idle*. The function must return zero when digit monitoring is canceled (that is, when the *dwDigitModes* parameter is zero). The service provider must terminate digit monitoring when the call goes idle. TAPI does not spontaneously call
**TSPI_lineMonitorDigits** to terminate monitoring.

Although this function can be invoked in any call state, digits typically are detected only while the call is in the *connected* state.

Each time a digit is detected, the service provider sends a
[LINE_MONITORDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725232(v=vs.85)) message to TAPI, passing the detected digit as a parameter. If both LINEDIGITMODE_DTMF and LINEDIGITMODE_DTMFEND are set in *dwDigitModes*, the two LINE_MONITORDIGITS messages are sent for each digit.

TAPI can use
**TSPI_lineMonitorDigits** to enable or disable unbuffered digit detection. It can use
[TSPI_lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegatherdigits) for buffered digit detection. After buffered digit gathering is complete, a
[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85)) message is sent. Both buffered and unbuffered digit detection can be enabled on the same call simultaneously.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants)

[LINE_GATHERDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725229(v=vs.85))

[LINE_MONITORDIGITS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725232(v=vs.85))

[TSPI_lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegatherdigits)

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)

[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol)