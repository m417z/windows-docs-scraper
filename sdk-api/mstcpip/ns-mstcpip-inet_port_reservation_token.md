# INET_PORT_RESERVATION_TOKEN structure

## Description

The **INET_PORT_RESERVATION_TOKEN** structure contains a port reservation token for a block of TCP or UDP ports.

## Members

### `Token`

A port reservation token for a block of TCP or UDP ports.

## Remarks

The **INET_PORT_RESERVATION_TOKEN** structure is supported on Windows Vista and later.

The **INET_PORT_RESERVATION_TOKEN** structure is used by the [SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation) , [SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation), and [SIO_RELEASE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-release-port-reservation) Ioctl for TCP or UDP port reservations. The **INET_PORT_RESERVATION_TOKEN** structure is also equivalent to the ULONG64 Token parameter used by the [CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation), [CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation), [DeletePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistenttcpportreservation), [DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation), [LookupPersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistenttcpportreservation), and [LookupPersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistentudpportreservation) functions in IP Helper.

## See also

[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation)

[CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation)

[DeletePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistenttcpportreservation)

[DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation)

[INET_PORT_RANGE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_range)

[INET_PORT_RESERVATION_INSTANCE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_reservation_instance)

[LookupPersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistenttcpportreservation)

[LookupPersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistentudpportreservation)

[SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation)

[SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation)

[SIO_RELEASE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-release-port-reservation)