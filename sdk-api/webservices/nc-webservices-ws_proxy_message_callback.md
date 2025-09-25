# WS_PROXY_MESSAGE_CALLBACK callback function

## Description

Invoked when the headers of the input message are
about to be sent, or when output message headers are just received.

## Parameters

### `message` [in]

The input or output message.

### `heap` [in]

The heap associated with the call. This is the heap which is passed to call for which this
callback is being called.

### `state` [in]

The 'state' as specified as part of [WS_PROXY_MESSAGE_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_proxy_message_callback_context) 'state' field.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

See also, [WS_PROXY_MESSAGE_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_proxy_message_callback_context).