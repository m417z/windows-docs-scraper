# WsPullBytes function

## Description

Sets up a callback to be invoked to obtain the bytes to be written within an element.
In some encodings this can be more efficient by eliminating a copy of the data.

## Parameters

### `writer` [in]

The writer to which the bytes will be written.

### `callback` [in]

The callback to invoke when its time to write the binary data.

### `callbackState` [in, optional]

User-defined state to be passed to the callback.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

[WsWriteBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebytes) and [WsPushBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wspushbytes) require the buffer of data to be provided to the writer.
In some usage patterns, this may require an extra copy of the data. For those scenarios, **WsPullBytes** offers a way to request the writer to provide the buffer that must be filled with data.

If the encoding cannot take advantage of this behavior, then **WsPullBytes** will invoke the
callback immediately and operate as if [WsWriteBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebytes) was called on the resulting data.