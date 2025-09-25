# WsWriteArray function

## Description

This operation sends a series of elements to an XML Writer.

## Parameters

### `writer` [in]

A pointer to the Writer where the elements are written.

### `localName` [in]

A pointer to the localName of the repeating element.

### `ns` [in]

A pointer to the namespace of the repeating element.

### `valueType` [in]

The value type for the elements

### `array`

A void pointer to the values written to *writer*. The size of the items is determined by value type.

**Note** See [WS_VALUE_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_value_type) for more information.

### `arraySize` [in]

The total byte length of the array.

### `itemOffset` [in]

The item offset within the array to write.

### `itemCount` [in]

The total number of items to write from the array.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is semantically equivalent to using [WsWriteStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartelement),
[WsWriteValue](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritevalue) and [WsWriteEndElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendelement) in a loop, but is more efficient.