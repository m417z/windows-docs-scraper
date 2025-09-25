# WS_PULL_BYTES_CALLBACK callback function

## Description

Used by the [WsPullBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wspullbytes) function to request
the data that should be written.

## Parameters

### `callbackState` [in]

The user-defined state that was passed to [WsPullBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wspullbytes).

### `bytes`

Where the data that is read should be placed.

### `maxSize` [in]

The maximum number of bytes that may be read.

### `actualSize` [out]

The actual number of bytes that were read. This may be less than maxSize. Returning 0
indicates that there is no more data.

### `asyncContext` [in, optional]

Information on how to invoke the function asynchronously, or **NULL** if invoking synchronously.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

| Return code | Description |
| --- | --- |
| **WS_S_ASYNC** | The asynchronous operation is still pending. |

## Remarks

Returning size of 0 indicates EOF.