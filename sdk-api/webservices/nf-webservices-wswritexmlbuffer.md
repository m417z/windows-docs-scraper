# WsWriteXmlBuffer function

## Description

Writes a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) to a writer.

## Parameters

### `writer` [in]

The writer to which the XML buffer will be written.

### `xmlBuffer` [in]

The XML buffer to write.

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

The function will copy the entire contents of the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) to the writer at the current position.