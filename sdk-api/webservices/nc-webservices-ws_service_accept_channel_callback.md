# WS_SERVICE_ACCEPT_CHANNEL_CALLBACK callback function

## Description

Invoked when a channel is accepted on an endpoint
listener by service host.

For session-based service contract, this notification signifies session initiation.
Thus an application state scoped for the session can be created within this callback.

## Parameters

### `context` [in]

The operation context.

#### - **channelState

The callback may provide channel state through this parameter. This channel state is
made available to the service operation as part of [WS_OPERATION_CONTEXT](https://learn.microsoft.com/windows/desktop/wsw/ws-operation-context) through
the [WS_OPERATION_CONTEXT_PROPERTY_CHANNEL_USER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_operation_context_property_id).

### `asyncContext` [in, optional]

Information on whether the function is getting invoked asynchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

### `channelState`

The callback may provide channel state through this parameter. This channel state is
made available to the service operation as part of [WS_OPERATION_CONTEXT](https://learn.microsoft.com/windows/desktop/wsw/ws-operation-context) through
the [WS_OPERATION_CONTEXT_PROPERTY_CHANNEL_USER_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_operation_context_property_id).

## Return value

This callback function does not return a value.

## Remarks

See also [WS_SERVICE_CLOSE_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_close_channel_callback) which can be used by the application to disassociate state,
and gets called on channel closure.

This callback is cancellable.

#### Examples

For an example implementation on how to use this callback for associating session state, see the session based calculator [sample](https://learn.microsoft.com/windows/desktop/wsw/sessionfullcalculatorserviceexample).

``` syntax
HRESULT CALLBACK CreateSessionCalculator (const WS_OPERATION_CONTEXT* context, void** userChannelState,
                                          const WS_ASYNC_CONTEXT* asyncContext, WS_ERROR* error)
{
    SessionfullCalculator* calculator = new SessionfullCalculator ();
    if (calculator != NULL)
        *userChannelState = (void*) calculator;
    else
        return E_OUTOFMEMORY;
    return NOERROR;
}
```