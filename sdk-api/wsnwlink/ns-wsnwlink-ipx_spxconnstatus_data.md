# IPX_SPXCONNSTATUS_DATA structure

## Description

The
**IPX_SPXCONNSTATUS_DATA** structure provides information about a connected SPX socket. Used in conjunction with
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function calls that specify IPX_SPXGETCONNECTIONSTATUS in the *optname* parameter. All numbers in
**IPX_SPXCONNSTATUS_DATA** are in Novell (high-low) order.

## Members

### `ConnectionState`

Specifies the connection state.

### `WatchDogActive`

Specifies whether watchdog capabilities are active.

### `LocalConnectionId`

Specifies the local connection ID.

### `RemoteConnectionId`

Specifies the remote connection ID.

### `LocalSequenceNumber`

Specifies the local sequence number.

### `LocalAckNumber`

Specifies the local acknowledgment (ACK) number.

### `LocalAllocNumber`

Specifies the local allocation number.

### `RemoteAckNumber`

Specifies the remote acknowledgment (ACK) number.

### `RemoteAllocNumber`

Specifies the remote allocation number.

### `LocalSocket`

Specifies the local socket.

### `ImmediateAddress`

Specifies the IPX address to which the local computer is attached.

### `RemoteNetwork`

Specifies the network to which the remote host is attached.

### `RemoteNode`

Specifies the remote node.

### `RemoteSocket`

Specifies the remote socket.

### `RetransmissionCount`

Specifies the number of retransmissions.

### `EstimatedRoundTripDelay`

Specifies the estimated round trip–time, in milliseconds, delay for a given packet.

### `RetransmittedPackets`

Specifies the number of retransmitted packets on the socket.

### `SuppressedPacket`

Specifies the number of suppressed packets on the socket.

## See also

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)