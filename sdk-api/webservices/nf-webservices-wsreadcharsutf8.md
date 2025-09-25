# WsReadCharsUtf8 function

## Description

Reads a specified number of text characters from the reader and returns them encoded in UTF-8.

## Parameters

### `reader` [in]

A pointer to the **XML Reader** from which the character data should be read. The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object.

### `bytes`

A pointer to the buffer to place the encoded bytes that have been read.

### `maxByteCount` [in]

The maximum number of bytes that should be read.

### `actualByteCount` [out]

A pointer to a ULONG value of
the actual number of bytes that were read. This may be less than maxByteCount even when there
are more bytes remaining. There are no more bytes when this returns zero.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

XML text is read up to either a start element or end element. Comments are skipped, and CDATA content is treated
identically to element content. Character entities are converted to their unescaped form.

This function can fail for any of the reasons listed in [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).