# ICallInterceptor::GetRegisteredSink

## Description

Retrieves the registered event sink.

## Parameters

### `ppsink` [out]

A pointer to a pointer to the event sink. See [ICallFrameEvents](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallframeevents).

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CO_E_OBJNOTREG** | No event sink is registered with this interceptor. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## See also

[ICallInterceptor](https://learn.microsoft.com/windows/desktop/api/callobj/nn-callobj-icallinterceptor)