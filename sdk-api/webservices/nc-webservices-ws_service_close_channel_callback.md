# WS_SERVICE_CLOSE_CHANNEL_CALLBACK callback function

## Description

Invoked when a channel is closed or aborted on an endpoint.
This callback is called right before we are about to close the channel.

For normal operation when service host is running and the client cleanly
closed the channel, this implies that we have received a session closure
from the client and we are about to close the channel.

The other scenario is when service host is going through an Abort Shutdown
or during the processing of the message an unrecoverable error condition is
met, as a result of this we attempt to abort and then close the channel.
In this case as well right before the abort we will call upon this callback.

For session-based service contract, this notification
signifies session tear down. Thus an application state scoped for the session
can be destroyed within this callback.

## Parameters

### `context` [in]

The operation context.

### `asyncContext` [in, optional]

Information on whether the function is getting invoked asynchronously.

## Return value

This callback function does not return a value.

## Remarks

The returned HRESULT is only used to see if the function is completing asynchronously. Failure or
reporting failure through HRESULT does not in any way affects the service host infrastructure.

Irrespective of whether [WS_SERVICE_ACCEPT_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_accept_channel_callback) competed successfully or not. This function
will always be fired.

See also [WS_SERVICE_ACCEPT_CHANNEL_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_service_accept_channel_callback) which can be used by the application to associate state,
and gets called when a channel gets accepted.

For an example implementation on how to use this callback for disassociating session state, see the session based calculator [sample](https://learn.microsoft.com/windows/desktop/wsw/sessionfullcalculatorserviceexample).

This callback is cancellable.

#### Examples

``` syntax
HRESULT CALLBACK FreeSessionCalculator (const WS_OPERATION_CONTEXT* context,
                                        const WS_ASYNC_CONTEXT* asyncContext)
{
     HRESULT hr = NOERROR;
     SessionfulCalculator* calculator = NULL;
     hr = WsGetOperationContextProperty (context,
                                         WS_OPERATION_CONTEXT_PROPERTY_CHANNEL_USER_STATE,
                                         &calculator, sizeof (SessionfulCalculator*), NULL);
     if (SUCCEEDED(hr) && (calculator != NULL))
     {
         delete calculator;
     }
     return NOERROR;
}

```