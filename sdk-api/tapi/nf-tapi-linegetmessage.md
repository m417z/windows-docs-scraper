# lineGetMessage function

## Description

The
**lineGetMessage** function returns the next TAPI message that is queued for delivery to an application that is using the Event Handle notification mechanism (see
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) for further details).

## Parameters

### `hLineApp`

Handle returned by
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa). The application must have set the LINEINITIALIZEEXOPTION_USEEVENT option in the **dwOptions** member of the
[LINEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineinitializeexparams) structure.

### `lpMessage`

Pointer to a
[LINEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemessage) structure. Upon successful return from this function, the structure contains the next message that had been queued for delivery to the application.

### `dwTimeout`

Time-out interval, in milliseconds. The function returns if the interval elapses, even if no message can be returned. If *dwTimeout* is zero, the function checks for a queued message and returns immediately. If *dwTimeout* is INFINITE, the function's time-out interval never elapses.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALAPPHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_NOMEM.

## Remarks

If the
**lineGetMessage** function has been called with a non-zero timeout and the application calls
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown) on another thread, this function returns immediately with LINEERR_INVALAPPHANDLE.

If the timeout expires (or was zero) and no message could be fetched from the queue, the function returns with the error LINEERR_OPERATIONFAILED.

## See also

[LINEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineinitializeexparams)

[LINEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemessage)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)