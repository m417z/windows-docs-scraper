# WS_XML_NODE_POSITION structure

## Description

Represents a position within an XML buffer. The current position within
a reader or writer may be obtained by calling [WsGetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetreaderposition) or
[WsGetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetwriterposition). The current position within a reader or writer
may be set by calling [WsSetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetreaderposition) or [WsSetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetwriterposition).

Using [WsRemoveNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsremovenode) to remove a node that corresponds to or contains a
position will cause subsequent use of the position to fail. The position itself
remains valid, but operations that depend on that position will fail.

Positions may be used as long as the containing XML buffer is valid. Using a position
after its corresponding buffer has been deleted will exhibit undefined behavior.

## Members

### `buffer`

The xml buffer to which the position refers.

### `node`

An internal handle to the node.