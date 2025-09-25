# WsRemoveNode function

## Description

Removes the node at the specified position from the xml buffer. If positioned
on an element it will remove the element including all of its children and its
corresponding end element, otherwise it will remove a single node.

The use of any API with a [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) or [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) that
currently depends on this position or a child of this position will fail. The
WS_XML_READER or WS_XML_WRITER must be repositioned
before using further.

It will return **WS_E_INVALID_OPERATION** if the node is positioned on an end
element or the root of the document.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

Calling [WsSetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetreaderposition) or [WsSetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetwriterposition) after calling **WsRemoveNode** will fail.

## Parameters

### `nodePosition` [in]

The position of the node that should be removed.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |