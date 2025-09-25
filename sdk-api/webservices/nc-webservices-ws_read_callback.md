# WS_READ_CALLBACK callback function

## Description

Used by the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) to read from some source into a buffer.

## Parameters

### `callbackState` [in]

A **void** pointer to the user-defined state value that was passed to the function that accepted this callback.

### `bytes`

A **void** pointer to the location where the data should be placed.

### `maxSize` [in]

The maximum number of bytes that may be read.

### `actualSize` [out]

A pointer to a **ULONG** value that indicates the number of bytes actually read. This may be less than maxSize. Returning 0
indicates that there is no more data.

### `asyncContext` [in, optional]

A pointer to a [WS_ASYNC_CONTEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_async_context) structure containing information on how to invoke the function asynchronously. Assigned **NULL** if invoking synchronously.

### `error` [in, optional]

A pointer to [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) data structure where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.

## Remarks

Returning size of 0 in the *actualSize* output parameter indicates the end of the file.