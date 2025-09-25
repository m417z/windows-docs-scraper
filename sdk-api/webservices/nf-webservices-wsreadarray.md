# WsReadArray function

## Description

Reads a series of elements from the reader and interprets their
content according to the specified value type.

## Parameters

### `reader` [in]

The reader from which the array should be read.

### `localName` [in]

The localName of the repeating element.

### `ns` [in]

The namespace of the repeating element.

### `valueType` [in]

The value type to use to parse the content of each element.

### `array`

The array to populate with parsed values. The size of the array items is determined by the value type.
See [WS_VALUE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_value_type) for more information.

### `arraySize` [in]

The size in bytes (not items) of the array.

### `itemOffset` [in]

The item (not byte) offset within the array at which to read.

### `itemCount` [in]

The number of items (not bytes) to read into the array.

### `actualItemCount` [out]

The actual number of items that were read. This may be less than itemCount even when there
are more items remaining. There are no more elements when this returns zero.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

This function is semantically equivalent to using [WsReadStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadstartelement),
[WsReadValue](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadvalue) and [WsReadEndElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadendelement) in a loop, but is more efficient.

This function can fail for any of the reasons listed in [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).