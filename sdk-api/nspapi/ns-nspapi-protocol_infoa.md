# PROTOCOL_INFOA structure

## Description

The
**PROTOCOL_INFO** structure contains information about a protocol.

## Members

### `dwServiceFlags`

Type: **DWORD**

A set of bit flags that specifies the services provided by the protocol. One or more of the following bit flags may be set.

| Value | Meaning |
| --- | --- |
| **XP_CONNECTIONLESS** | If this flag is set, the protocol provides connectionless (datagram) service. If this flag is clear, the protocol provides connection-oriented data transfer. |
| **XP_GUARANTEED_DELIVERY** | If this flag is set, the protocol guarantees that all data sent will reach the intended destination. If this flag is clear, there is no such guarantee. |
| **XP_GUARANTEED_ORDER** | If this flag is set, the protocol guarantees that data will arrive in the order in which it was sent. Note that this characteristic does not guarantee delivery of the data, only its order. If this flag is clear, the order of data sent is not guaranteed. |
| **XP_MESSAGE_ORIENTED** | If this flag is set, the protocol is message-oriented. A message-oriented protocol honors message boundaries. If this flag is clear, the protocol is stream oriented, and the concept of message boundaries is irrelevant. |
| **XP_PSEUDO_STREAM** | If this flag is set, the protocol is a message-oriented protocol that ignores message boundaries for all receive operations. <br><br>This optional capability is useful when you do not want the protocol to frame messages. An application that requires stream-oriented characteristics can open a socket with type SOCK_STREAM for transport protocols that support this functionality, regardless of the value of **iSocketType**. |
| **XP_GRACEFUL_CLOSE** | If this flag is set, the protocol supports two-phase close operations, also known as graceful close operations. If this flag is clear, the protocol supports only abortive close operations. |
| **XP_EXPEDITED_DATA** | If this flag is set, the protocol supports expedited data, also known as urgent data. |
| **XP_CONNECT_DATA** | If this flag is set, the protocol supports connect data. |
| **XP_DISCONNECT_DATA** | If this flag is set, the protocol supports disconnect data. |
| **XP_SUPPORTS_BROADCAST** | If this flag is set, the protocol supports a broadcast mechanism. |
| **XP_SUPPORTS_MULTICAST** | If this flag is set, the protocol supports a multicast mechanism. |
| **XP_BANDWIDTH_ALLOCATION** | If this flag is set, the protocol supports a mechanism for allocating a guaranteed bandwidth to an application. |
| **XP_FRAGMENTATION** | If this flag is set, the protocol supports message fragmentation; physical network MTU is hidden from applications. |
| **XP_ENCRYPTS** | If this flag is set, the protocol supports data encryption. |

### `iAddressFamily`

Type: **INT**

Value to pass as the *af* parameter when the
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function is called to open a socket for the protocol. This address family value uniquely defines the structure of protocol addresses, also known as
**sockaddr** structures, used by the protocol.

### `iMaxSockAddr`

Type: **INT**

Maximum length of a socket address supported by the protocol, in bytes.

### `iMinSockAddr`

Type: **INT**

Minimum length of a socket address supported by the protocol, in bytes.

### `iSocketType`

Type: **INT**

Value to pass as the *type* parameter when the
**socket** function is called to open a socket for the protocol.

Note that if XP_PSEUDO_STREAM is set in **dwServiceFlags**, the application can specify SOCK_STREAM as the *type* parameter to
**socket**, regardless of the value of **iSocketType**.

### `iProtocol`

Type: **INT**

Value to pass as the *protocol* parameter when the
**socket** function is called to open a socket for the protocol.

### `dwMessageSize`

Type: **DWORD**

Maximum message size supported by the protocol, in bytes. This is the maximum size of a message that can be sent from or received by the host. For protocols that do not support message framing, the actual maximum size of a message that can be sent to a given address may be less than this value.

The following special message size values are defined.

| Value | Meaning |
| --- | --- |
| **0** | The protocol is stream-oriented; the concept of message size is not relevant. |
| **0xFFFFFFFF** | The protocol is message-oriented, but there is no maximum message size. |

### `lpProtocol`

Type: **LPTSTR**

Pointer to a zero-terminated string that supplies a name for the protocol; for example, "SPX2."

## See also

[EnumProtocols](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-enumprotocolsa)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)

## Remarks

> [!NOTE]
> The nspapi.h header defines PROTOCOL_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).