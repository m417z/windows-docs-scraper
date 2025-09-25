# ICallInterceptor::RegisterSink

## Description

Registers an event sink for receiving notifications of method calls.

Only a single event sink may be registered with an interceptor at a time. Registering a sink of **NULL** is legal, and causes the interceptor to release any previously registered sink that it might be holding on to.

## Parameters

### `psink` [in]

A pointer to the event sink. See [ICallFrameEvents](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframeevents).

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallinterceptor)