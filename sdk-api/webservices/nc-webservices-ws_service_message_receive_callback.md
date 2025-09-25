# WS_SERVICE_MESSAGE_RECEIVE_CALLBACK callback function

## Description

Invoked when a [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) is received on an endpoint configured with a [WS_SERVICE_CONTRACT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_contract) which has defaultMessageHandlerCallback set.

The incoming [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message), the serviceProxy along with other parameters is made available to the callback through [WS_OPERATION_CONTEXT](https://learn.microsoft.com/windows/desktop/wsw/ws-operation-context).

## Parameters

### `context` [in]

The [context](https://learn.microsoft.com/windows/desktop/wsw/ws-operation-context) within which this callback is being invoked.

### `asyncContext` [in, optional]

Specifies whether the callback can run asynchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.

## Remarks

When defined, callback would disallow all concurrency on a session based channel. If concurrency on a session based channel is desirable an application should not define *WS_SERVICE_MESSAGE_RECEIVE_CALLBACK* on the [WS_SERVICE_CONTRACT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_service_contract).

At the time of the invocation of the callback, service model has performed [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) on the receiving [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message). It is the responsibility of the application implementing *WS_SERVICE_MESSAGE_RECEIVE_CALLBACK* to process the body and perform [WsReadMessageEnd](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessageend) operation.
If the callback fails, the underlying channel is aborted.
See also, [UnTypedServiceExample](https://learn.microsoft.com/windows/desktop/wsw/untypedserviceexample)

#### Examples

Defining a WS_SERVICE_MESSAGE_RECEIVE_CALLBACK

``` syntax

// Method contract for the service
static WS_SERVICE_CONTRACT calculatorContract =
{
    NULL,
    NULL,
    DefaultMessageHandlerCallback, // WS_SERVICE_MESSAGE_RECEIVE_CALLBACK
    NULL
};
```

Accessing the incoming [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) property

``` syntax
HRESULT CALLBACK MessageRecieved(const WS_OPERATION_CONTEXT* context, const WS_ASYNC_CONTEXT* asyncContext, WS_ERROR* error)
{
    :
    hr = WsGetOperationContextProperty(context, WS_OPERATION_CONTEXT_PROPERTY_INPUT_MESSAGE, &requestMessage, sizeof(requestMessage), NULL, error);
    :
}
```