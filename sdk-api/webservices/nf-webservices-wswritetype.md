# WsWriteType function

## Description

Write a value of a given [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) to XML according to the [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping).

## Parameters

### `writer` [in]

The writer to write the value to.

### `typeMapping` [in]

Describes how the type maps to the XML that is being written.

### `type` [in]

The type of the value to serialize.

### `typeDescription` [in, optional]

Additional information about the type. Each type has a different description
structure. This may be **NULL**, depending on the [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

### `writeOption` [in]

Whether the value is required, and how the value is allocated.
See [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) for more information.

This parameter must have one of the following values:

* [WS_WRITE_REQUIRED_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option).
* [WS_WRITE_REQUIRED_POINTER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option).

### `value`

A pointer to the value to serialize.

### `valueSize` [in]

The size of the value being serialized.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

See [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) for how to use this function to write values in elements and attributes.

If the API fails, the state of input writer becomes undefined. The only APIs that may be used on the writer
if this occurs are [WsSetOutput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutput) and [WsSetOutputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutputtobuffer) to return the writer to a usable state,
or [WsFreeWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreewriter) to free the writer.