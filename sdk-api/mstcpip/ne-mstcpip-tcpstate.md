# TCPSTATE enumeration

## Description

The Windows Sockets
**TCPSTATE** enumeration indicates the possible states of a Transmission Control Protocol (TCP) connection.

## Constants

### `TCPSTATE_CLOSED`

The TCP connection has no connection state at all. This state represents the state when there is no Transmission Control Block (TCB), and therefore,
no connection.

### `TCPSTATE_LISTEN`

The TCP connection is waiting for a connection request from any remote
TCP and port.

### `TCPSTATE_SYN_SENT`

-The TCP connection is waiting for a matching connection request
after sending a connection request.

### `TCPSTATE_SYN_RCVD`

The TCP connection is waiting for an acknowledgment that confirms the connection
request after both receiving and sending a
connection request.

### `TCPSTATE_ESTABLISHED`

The TCP connection is an open connection, so the data received can be
delivered to the user. This state is normal state for the data transfer phase
of the connection.

### `TCPSTATE_FIN_WAIT_1`

The TCP connection is waiting for a request to end the connection
from the remote TCP, or an acknowledgment of the previously sent request to end the connection.

### `TCPSTATE_FIN_WAIT_2`

The TCP connection is waiting for a request to end the connection
from the remote TCP.

### `TCPSTATE_CLOSE_WAIT`

The TCP connection is waiting for a request to end the connection
from the local user.

### `TCPSTATE_CLOSING`

The TCP connection is waiting for an acknowledgment of the request to end the connection from the remote TCP.

### `TCPSTATE_LAST_ACK`

The TCP connection is waiting for an acknowledgment of the request to end the connection that was previously sent to the remote TCP, which includes an acknowledgment of its request to end the connection.

### `TCPSTATE_TIME_WAIT`

The TCP connection is waiting for enough time to pass to be sure
the remote TCP received the acknowledgment of its request to end the connection.

### `TCPSTATE_MAX`

The maximum value of the [TCPSTATE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-tcpstate) enumeration.

## Remarks

A TCP connection progresses from one state to another in response to
events. The events are the user calls OPEN, SEND, RECEIVE, CLOSE,
ABORT, and STATUS; the incoming segments, particularly those
containing the SYN, ACK, RST and FIN flags; and timeouts.

For more information about TCP connection states, see [RFC 793](https://tools.ietf.org/html/rfc793).

## See also

[SIO_TCP_INFO](https://learn.microsoft.com/windows/win32/winsock/sio-tcp-info)

[TCP_INFO_v0](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-tcp_info_v0)