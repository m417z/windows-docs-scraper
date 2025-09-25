# WsWriteEndStartElement function

## Description

Forces the writer to commit the current element and prevent further attributes
from being written to the element.

## Parameters

### `writer` [in]

The writer for which the current element should be committed.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

Occasionally, it is useful to explicitly force the completion of an element. This can be used to force the writer
to write a full element and pair. It also may be useful when obtaining positions when writing to a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

Calling this API when there is no element to commit will cause it to return **WS_E_INVALID_OPERATION**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)