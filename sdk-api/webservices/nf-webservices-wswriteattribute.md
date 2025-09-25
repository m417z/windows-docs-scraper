# WsWriteAttribute function

## Description

Write a typed value as an XML attribute.

## Parameters

### `writer` [in]

The writer to write the attribute to.

### `attributeDescription` [in]

A pointer to a description of how to serialize the attribute.

### `writeOption` [in]

Information about how the value is allocated.
See [WS_WRITE_OPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_write_option) for more information.

### `value`

A pointer to the value to serialize.

### `valueSize` [in]

The size of the value being serialized, in bytes.

If the value is **NULL**, then the size should be 0.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |

## Remarks

This API writes the start attribute, attribute value, and end attribute.

If the API fails, the state of input writer becomes undefined. The only APIs that may be used on the writer
if this occurs are [WsSetOutput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutput) and [WsSetOutputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutputtobuffer) to return the writer to a usable state,
or [WsFreeWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreewriter) to free the writer.