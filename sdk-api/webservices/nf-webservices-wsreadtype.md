# WsReadType function

## Description

Read a value of a given [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) from XML according to the [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping).

## Parameters

### `reader` [in]

The reader that is positioned on the XML to deserialize.

### `typeMapping` [in]

Describes how the type maps to the XML that is being read.

### `type` [in]

The type of the value to deserialize.

### `typeDescription` [in, optional]

Additional information about the type. Each type has a different description
structure. This may be **NULL**, depending on the [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

### `readOption` [in]

Whether the value is required, and how to allocate the value.
See [WS_READ_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option) for more information.

This parameter must have one of the following values:

* [WS_READ_REQUIRED_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).
* [WS_READ_REQUIRED_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_read_option).

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

See [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) for how to use this function to read values from elements and attributes.

If the API fails, the state of input reader becomes undefined. The only APIs that may be used on the reader
if this occurs are [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput) and [WsSetInputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinputtobuffer) to return the reader to a usable state,
or [WsFreeReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreereader) to free the reader.