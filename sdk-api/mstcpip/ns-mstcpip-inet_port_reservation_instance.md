# INET_PORT_RESERVATION_INSTANCE structure

## Description

The **INET_PORT_RESERVATION_INSTANCE** structure contains a port reservation and a token for a block of TCP or UDP ports.

## Members

### `Reservation`

A runtime port reservation for a block of TCP or UDP ports.

The [INET_PORT_RESERVATION](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_range) structure is typedefed to the [INET_PORT_RANGE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_range) structure.

### `Token`

A port reservation token for a block of TCP or UDP ports.

## Remarks

The **INET_PORT_RESERVATION_INSTANCE** structure is supported on Windows Vista and later.

The **INET_PORT_RESERVATION_INSTANCE** structure is returned by the [SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation) IOCTL when acquiring a runtime reservation for a block of TCP or UDP ports.

## See also

[CreatePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistenttcpportreservation)

[CreatePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createpersistentudpportreservation)

[DeletePersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistenttcpportreservation)

[DeletePersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deletepersistentudpportreservation)

[INET_PORT_RANGE](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_range)

[INET_PORT_RESERVATION_TOKEN](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-inet_port_reservation_token)

[LookupPersistentTcpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistenttcpportreservation)

[LookupPersistentUdpPortReservation](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-lookuppersistentudpportreservation)

[SIO_ACQUIRE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-acquire-port-reservation)

[SIO_ASSOCIATE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-associate-port-reservation)

[SIO_RELEASE_PORT_RESERVATION](https://learn.microsoft.com/windows/win32/winsock/sio-release-port-reservation)