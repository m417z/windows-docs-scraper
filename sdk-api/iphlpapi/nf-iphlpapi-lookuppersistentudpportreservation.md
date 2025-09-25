# LookupPersistentUdpPortReservation function

## Description

The
**LookupPersistentUdpPortReservation** function looks up the token for a persistent UDP port reservation for a consecutive block of TCP ports on the local computer.

## Parameters

### `StartPort` [in]

The starting UDP port number in network byte order.

### `NumberOfPorts` [in]

The number of UDP port numbers that were reserved.

### `Token` [out]

A pointer to a port reservation token that is returned if the function succeeds.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if zero is passed in the *StartPort* or *NumberOfPorts* parameters. |
| **ERROR_NOT_FOUND** | The element was not found. This error is returned if persistent port block specified by the *StartPort* and *NumberOfPorts* parameters could not be found. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **LookupPersistentUdpPortReservation** function is defined on Windows Vista and later.

The **LookupPersistentUdpPortReservation** function is used to lookup the token for a persistent reservation for a block of UDP ports.

A persistent reservation for a block of UDP ports is created by a call to the [CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation) function. The *StartPort* or *NumberOfPorts* parameters passed to the **LookupPersistentUdpPortReservation** function must match the values used when the persistent reservation for a block of TCP ports was created by the **CreatePersistentUdpPortReservation** function.

If the **LookupPersistentUdpPortReservation** function succeeds, the *Token* parameter returned will point to the token for the persistent port reservation for the block of UDP ports. Note that the token for a given persistent reservation for a block of TCP ports may change each time the system is restarted.

An application can request port assignments from the UDP port reservation by opening a UDP socket, then calling the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function specifying the [SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation) IOCTL and passing the reservation token before issuing a call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function on the socket.

## See also

[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation)

[CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation)

[DeletePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistenttcpportreservation)

[DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation)

[LookupPersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistenttcpportreservation)

[SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation)