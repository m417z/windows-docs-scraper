# EXTCONN enumeration

## Description

Specifies the type of external connection existing on an embedded object.

## Constants

### `EXTCONN_STRONG:0x1`

The external connection is a link. If this value is specified, the external connection must keep the object alive until all strong external connections are cleared through [IExternalConnection::ReleaseConnection](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iexternalconnection-releaseconnection).

### `EXTCONN_WEAK:0x2`

This value is not used.

### `EXTCONN_CALLABLE:0x4`

This value is not used.

## See also

[IExternalConnection::AddConnection](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iexternalconnection-addconnection)

[IExternalConnection::ReleaseConnection](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iexternalconnection-releaseconnection)