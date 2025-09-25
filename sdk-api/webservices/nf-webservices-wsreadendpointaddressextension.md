# WsReadEndpointAddressExtension function

## Description

Reads an extension of the [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address).

## Parameters

### `reader` [in]

The XML reader to use to read the extension.

The function will automatically set the input of
the reader as necessary to read the extensions.

### `endpointAddress` [in]

The endpoint address containing the extensions.

### `extensionType` [in]

The type of extension to read.

### `readOption` [in]

Whether the value is required, and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

This parameter must have one of the following values:

* [WS_READ_REQUIRED_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).
* [WS_READ_REQUIRED_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).
* [WS_READ_OPTIONAL_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

### `heap` [in]

The heap to use to store the value that is read.

### `value`

The address of a buffer to place the value read.

If using [WS_READ_REQUIRED_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for the readOption
parameter, the buffer must be the size of the type of extension
being read (which varies by [WS_ENDPOINT_ADDRESS_EXTENSION_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_endpoint_address_extension_type)).

If using [WS_READ_REQUIRED_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) or **WS_READ_OPTIONAL_POINTER**,
the buffer should be the size of a pointer.

### `valueSize` [in]

The size of the buffer that the caller has allocated for the value read.

This size should correspond to the size of the buffer passed
using the value parameter.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The extension type was not valid.<br><br>The size of the supplied buffer was not correct.<br><br>A required parameter was **NULL**. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The returned value is valid until the heap is freed or reset.

If the requested extension type appears more than once in the
extensions buffer, then the first instance is returned.