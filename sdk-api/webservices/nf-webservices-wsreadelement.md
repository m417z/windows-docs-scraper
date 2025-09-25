# WsReadElement function

## Description

Read an element producing a value of the specified [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

## Parameters

### `reader` [in]

The reader that is positioned on the XML to deserialize.

### `elementDescription` [in]

A pointer to a description of how to deserialize the element.

### `readOption` [in]

Whether the element is required, and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

### `heap` [in, optional]

The heap to store the deserialized values in.

### `value`

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `valueSize` [in]

The interpretation of this parameter depends on the [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **WS_E_QUOTA_EXCEEDED** | The size quota of the heap was exceeded. |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

This API will move to the next element, verify its name and namespace, and then
and deserialize the content as a typed value.

If the API fails, the state of input reader becomes undefined. The only APIs that may be used on the reader
if this occurs are [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput) and [WsSetInputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinputtobuffer) to return the reader to a usable state,
or [WsFreeReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreereader) to free the reader.