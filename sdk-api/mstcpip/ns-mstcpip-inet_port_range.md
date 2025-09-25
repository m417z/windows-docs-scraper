# INET_PORT_RANGE structure

## Description

The **INET_PORT_RANGE** structure provides input data used by the [SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation) IOCTL to acquire a runtime reservation for a block of TCP or UDP ports.

## Members

### `StartPort`

The starting TCP or UDP port number. If this parameter is set to zero, the system will choose a starting TCP or UDP port number.

### `NumberOfPorts`

The number of TCP or UDP port numbers to reserve.

## Remarks

The **INET_PORT_RANGE** structure is supported on Windows Vista and later.

The
**INET_PORT_RANGE** structure is the datatype passed in the input buffer to the [SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation) IOCTL. This IOCTL is used to acquire a runtime reservation for a block of TCP or UDP ports.

The
**INET_PORT_RANGE** structure is typedefed to the **INET_PORT_RESERVATION** structure.

## See also

[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation)

[CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation)

[DeletePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistenttcpportreservation)

[DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation)

[INET_PORT_RESERVATION_INSTANCE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_reservation_instance)

[INET_PORT_RESERVATION_TOKEN](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_reservation_token)

[LookupPersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistenttcpportreservation)

[LookupPersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistentudpportreservation)

[SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation)

[SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation)

[SIO_RELEASE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-release-port-reservation)