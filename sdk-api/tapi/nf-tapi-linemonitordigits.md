# lineMonitorDigits function

## Description

The
**lineMonitorDigits** function enables and disables the unbuffered detection of digits received on the call. Each time a digit of the specified digit mode is detected, a message is sent to the application indicating which digit has been detected.

## Parameters

### `hCall`

Handle to the call on which digits are to be detected. The call state of *hCall* can be any state except *idle* or *disconnected*.

### `dwDigitModes`

Digit mode or modes that are to be monitored. If *dwDigitModes* is zero, digit monitoring is canceled. This parameter uses one or more of the
[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALDIGITMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

This function is considered successful if digit monitoring has been correctly initiated, not when digit monitoring has terminated. Digit monitoring remains in effect until it is explicitly disabled by calling
**lineMonitorDigits** with *dwDigitModes* set to zero, until the call transitions to idle, or when the application deallocates its call handle for the call. Although this function can be invoked in any call state, digits are usually detected only while the call is in the *connected* state.

Each time a digit is detected, a LINE_MONITORDIGITS message is sent to the application passing the detected digit as a parameter.

An application can use
**lineMonitorDigits** to enable or disable unbuffered digit detection. It can use
[lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegatherdigits) for buffered digit detection. After buffered digit gathering is complete, a
[LINE_GATHERDIGITS](https://learn.microsoft.com/windows/desktop/Tapi/line-gatherdigits) message is sent to the application. Both buffered and unbuffered digit detection can be enabled on the same call simultaneously.

Monitoring of digits on a conference call applies only to the *hConfCall*, not to the individual participating calls.

## See also

[LINE_GATHERDIGITS](https://learn.microsoft.com/windows/desktop/Tapi/line-gatherdigits)

[LINE_MONITORDIGITS](https://learn.microsoft.com/windows/desktop/Tapi/line-monitordigits)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegatherdigits)