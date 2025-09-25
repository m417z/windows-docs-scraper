# WsWriteStartCData function

## Description

This operation starts a CDATA section in the writer.
CDATA sections cannot be nested and cannot appear at the root of the document.

**Note** Some encodings do not support CDATA
and will generate text instead.

The CDATA section is completed by calling [WsWriteEndCData](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendcdata).

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the CDATA section is written. The pointer must reference a valid **XML Writer** object.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |