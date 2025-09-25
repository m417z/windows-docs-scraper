# WsPushBytes function

## Description

Establishes a callback to be invoked to write bytes within an element. In some encodings this can
be more efficient by eliminating a copy of the data.

## Parameters

### `writer` [in]

A pointer to the XML Writer object to which the bytes are written. The pointer must reference a valid [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) and the referenced value may not be **NULL**.

### `callback` [in]

This parameter is the callback to invoke to write the data.

### `callbackState` [in, optional]

A pointer to a user-defined state that is passed to the callback function.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

When writing with the [WS_XML_WRITER_MTOM_ENCODING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_writer_mtom_encoding), **WsPushBytes** provides a way
to write bytes directly into its own MIME part and avoid a copy. However, the writer at its discretion,
may choose to invoke the callback immediately, so the caller should be prepared for this.

If the encoding cannot take advantage of this behavior, then **WsPushBytes** will invoke the
callback immediately and operate as if [WsWriteBytes](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritebytes) was called.