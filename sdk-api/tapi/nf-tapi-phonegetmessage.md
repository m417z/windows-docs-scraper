# phoneGetMessage function

## Description

The
**phoneGetMessage** function returns the next TAPI message that is queued for delivery to an application that is using the Event Handle notification mechanism (see
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa) for further details).

## Parameters

### `hPhoneApp`

Handle returned by
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa). The application must have set the PHONEINITIALIZEEXOPTION_USEEVENT option in the **dwOptions** member of the
[PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams) structure.

### `lpMessage`

Pointer to a
[PHONEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonemessage) structure. Upon successful return from this function, the structure contains the next message that had been queued for delivery to the application.

### `dwTimeout`

Time-out interval, in milliseconds. The function returns if the interval elapses, even if no message can be returned. If *dwTimeout* is zero, the function checks for a queued message and returns immediately. If *dwTimeout* is INFINITE, the function's time-out interval never elapses.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALAPPHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPOINTER, PHONEERR_NOMEM.

## Remarks

If this function has been called with a nonzero timeout and the application calls
[phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown) on another thread, this function returns immediately with PHONEERR_INVALAPPHANDLE.

If the timeout expires (or was zero) and no message could be fetched from the queue, the function returns with the error PHONEERR_OPERATIONFAILED.

## See also

[PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams)

[PHONEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonemessage)

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)

[phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown)