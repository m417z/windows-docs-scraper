# ASYNC_COMPLETION callback function

## Description

*Completion_Proc* is a callback function implemented by TAPI and supplied to the service provider as a parameter to
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit). The service provider calls this function to report the completion of a line or phone procedure that it executes asynchronously.

The **ASYNC_COMPLETION** type defines a pointer to this callback function. *Completion_Proc* is a placeholder for the application-defined function name.

## Parameters

### `dwRequestID`

The identifier passed in the original request that the service provider executed asynchronously.

### `lResult`

The outcome of the operation. This can be zero to indicate success or a negative number to indicate an error. The possible specific error values that can result from a function are the same for asynchronous or synchronous execution.

## Remarks

The call state when calling this function can be any state.

This procedure is supplied by TAPI at the time a service provider is initialized with the
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit) function. Some of the TSPI procedures that operate on line, call, and phone devices specify asynchronous operation. These procedures include a *dwRequestID* parameter to identify the request. When such a procedure is called, the service provider can return a negative number for an error if one is detected immediately, or the positive *dwRequestID* if the operation continues asynchronously. The service provider must report completion exactly once for each request it executes asynchronously. It does so by calling this procedure. The service provider is not permitted to call this procedure or the
[Line_Event](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) or
[Phone_Event](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-phoneevent) procedure again until this procedure returns.

The service provider is permitted to call the
*Completion_Proc* function before it returns from the first request. TAPI guarantees not to call the service provider from within the
*Completion_Proc* context except where noted.

This does not have any direct correspondence at the TAPI level because at that level asynchronous function completions are reported as a message passed through the same callback interface that is used for spontaneous event messages. At the TSPI level, spontaneous events are reported through the
[Line_Event](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) and
[Phone_Event](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-phoneevent) callback procedures.

## See also

[Line_Event](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[Phone_Event](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-phoneevent)

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)