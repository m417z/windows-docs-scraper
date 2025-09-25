# WsReadChars function

## Description

Reads a specified number of text characters from the Reader.

## Parameters

### `reader` [in]

A pointer to the **XML Reader** from which the character data should be read. The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object.

### `chars`

A pointer to a location for the characters that have been read.

### `maxCharCount` [in]

The maximum number of characters that should be read.

### `actualCharCount` [out]

A pointer to a ULONG value of
the actual number of characters that were read. This may be less than maxCharCount even when there
are more characters remaining. There are no more characters when this returns zero.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

Text is read up to either a start element or end element. Comments are skipped, and CDATA content is treated
identically to element content. Character entities are converted to their unescaped form.

This function can fail for any of the reasons listed in [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).