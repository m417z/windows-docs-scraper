# RAS_CONNECTION_1 structure

## Description

The
**RAS_CONNECTION_1** structure contains detailed information regarding a specific connection, such as error counts and bytes received. For more general information about a specific connection, such as user name or domain, see
[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0).

## Members

### `hConnection`

A handle to the connection.

### `hInterface`

A handle to the interface.

### `PppInfo`

A [PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info) structure that contains Point-to-Point (PPP) projection operation information for a connection.

### `dwBytesXmited`

A value that specifies the number of bytes transmitted on the connection.

### `dwBytesRcved`

A value that specifies the number of bytes received on the connection.

### `dwFramesXmited`

A value that specifies the number of frames transmitted on the connection.

### `dwFramesRcved`

A value that specifies the number of frames received on the connection.

### `dwCrcErr`

A value that specifies the number of Cyclic Redundancy Check (CRC) errors on the connection.

### `dwTimeoutErr`

A value that specifies the number of time-out errors on the connection.

### `dwAlignmentErr`

A value that specifies the number of alignment errors on the connection.

### `dwHardwareOverrunErr`

A value that specifies the number of hardware overrun errors on the connection.

### `dwFramingErr`

A value that specifies the number of framing errors on the connection.

### `dwBufferOverrunErr`

A value that specifies the number of buffer overrun errors on the connection.

### `dwCompressionRatioIn`

A value that specifies the percentage by which data received on this connection is compressed. **dwCompressionRatioIn** is the size of the compressed data divided by the size of the same data in an uncompressed state.

### `dwCompressionRatioOut`

A value that specifies the percentage by which data transmitted on this connection is compressed. The ratio is the size of the compressed data divided by the size of the same data in an uncompressed state.

## See also

[MprAdminAcceptReauthentication](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminacceptreauthentication)

[MprAdminConnectionEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionenum)

[MprAdminConnectionHangupNotification3](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionhangupnotification3)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_CONNECTION_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_0)

[RAS_CONNECTION_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_2)

[RAS_CONNECTION_3](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_connection_3)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)