# WS_PUSH_BYTES_CALLBACK callback function

## Description

Used by the [WsPushBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wspushbytes) function to request that data be written.

## Parameters

### `callbackState` [in]

A
void pointer to the user-defined state that was passed to [WsPushBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wspushbytes).

### `writeCallback` [in]

The
callback function for writing bytes to the document.

### `writeCallbackState` [in]

A void pointer to the caller-defined state that should be passed when invoking the [WS_WRITE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_callback) function.

### `asyncContext` [in, optional]

A pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) structure containing information on how to invoke the function asynchronously. Assign **NULL** if invoking synchronously.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) data structure where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.