# WS_WRITE_CALLBACK callback function

## Description

Used by the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) function
to write a specified buffer to a user-determined destination.

## Parameters

### `callbackState` [in]

A **void** pointer to the user-defined state value that was passed to the function that accepted this callback.

### `buffers`

A pointer to the buffers containing the data to be written.

### `count` [in]

The number of buffers to write.

### `asyncContext` [in, optional]

A pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) structure containing information on how to invoke the function asynchronously. Assigned **NULL** if invoking synchronously.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) data structure where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.