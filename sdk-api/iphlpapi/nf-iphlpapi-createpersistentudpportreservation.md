# CreatePersistentUdpPortReservation function

## Description

The
**CreatePersistentUdpPortReservation** function creates a persistent UDP port reservation for a consecutive block of UDP ports on the local computer.

## Parameters

### `StartPort` [in]

The starting UDP port number in network byte order.

### `NumberOfPorts` [in]

The number of UDP port numbers to reserve.

### `Token` [out]

A pointer to a port reservation token that is returned if the function succeeds.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. <br><br>This error is returned if zero is passed in the *StartPort* or *NumberOfPorts* parameters. This error is also returned if the *NumberOfPorts* parameter is too large a block of ports depending on the *StartPort* parameter that the allocable block of ports would exceed the maximum port that can be allocated. |
| **ERROR_SHARING_VIOLATION** | The process cannot access the file because it is being used by another process. This error is returned if a UDP port in the block of UDP ports specified by the *StartPort* and *NumberOfPorts* parameters is already being used. This error is also returned if a persistent reservation for a block of UDP ports specified by the *StartPort* and *NumberOfPorts* parameters matches or overlaps a persistent reservation for a block of UDP ports that was already created. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **CreatePersistentUdpPortReservation** function is defined on Windows Vista and later.

The **CreatePersistentUdpPortReservation** function is used to add a persistent reservation for a block of UDP ports.

Applications and services which need to reserve ports fall into two categories. The first category includes components which need a particular port as part of their operation. Such components will generally prefer to specify their required port at installation time (in an application manifest, for example). The second category includes components which need any available port or block of ports at runtime.

These two categories correspond to specific and wildcard port reservation requests. Specific reservation requests may be persistent or runtime, while wildcard port reservation requests are only supported at runtime.

The **CreatePersistentUdpPortReservation** function provides the ability for an application or service to reserve persistently a block of UDP ports. Persistent TCP reservations are recorded in a persistent store for the UDP module in Windows.

A caller obtains a persistent port reservation by specifying how many ports are required and whether a specific range is needed. If the request can be satisfied, the **CreatePersistentUdpPortReservation** function returns a unique opaque ULONG64 token, which subsequently identifies the reservation. A persistent UDP port reservation may be released by calling the [DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation) function. Note that the token for a given persistent UDP port reservation may change each time the system is restarted.

Windows does not implement inter-component security for persistent reservations obtained using these functions. This means that if a component is granted the ability to obtain any persistent port reservations, that component automatically gains the ability to consume any persistent port reservations granted to any other component on the system. Process-level security is enforced for runtime reservations, but such control cannot be extended to persistent reservations created using the created using the [CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation) or **CreatePersistentUdpPortReservation** function.

Once a persistent UDP port reservation has been obtained, an application can request port assignments from the UDP port reservation by opening a UDP socket, then calling the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function specifying the [SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation) IOCTL and passing the reservation token before issuing a call to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function on the socket.

The [SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation) IOCTL can be used to request a runtime reservation for a block of TCP or UDP ports. For runtime port reservations, the port pool requires that reservations be consumed from the process on whose socket the reservation was granted. Runtime port reservations last only as long as the lifetime of the socket on which the **SIO_ACQUIRE_PORT_RESERVATION** IOCTL was called. In contrast, persistent port reservations created using the **CreatePersistentUdpPortReservation** function may be consumed by any process with the ability to obtain persistent reservations.

The **CreatePersistentUdpPortReservation** function can only be called by a user logged on as a member of the Administrators group. If **CreatePersistentUdpPortReservation** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned. This function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation)

[DeletePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistenttcpportreservation)

[DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation)

[LookupPersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistenttcpportreservation)

[LookupPersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistentudpportreservation)

[SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation)

[SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation)

[SIO_RELEASE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-release-port-reservation)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)