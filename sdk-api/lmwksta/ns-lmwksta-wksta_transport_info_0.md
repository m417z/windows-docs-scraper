# WKSTA_TRANSPORT_INFO_0 structure

## Description

The
**WKSTA_TRANSPORT_INFO_0** structure contains information about the workstation transport protocol, such as Wide Area Network (WAN) or NetBIOS.

## Members

### `wkti0_quality_of_service`

Specifies a value that determines the search order of the transport protocol with respect to other transport protocols. The highest value is searched first.

### `wkti0_number_of_vcs`

Specifies the number of clients communicating with the server using this transport protocol.

### `wkti0_transport_name`

Specifies the device name of the transport protocol.

### `wkti0_transport_address`

Specifies the address of the server on this transport protocol.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

### `wkti0_wan_ish`

This member is ignored by the
[NetWkstaTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstatransportadd) function. For the
[NetWkstaTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstatransportenum) function, this member indicates whether the transport protocol is a WAN transport protocol. This member is set to **TRUE** for NetBIOS/TCIP; it is set to **FALSE** for NetBEUI and NetBIOS/IPX.

Certain legacy networking protocols, including NetBEUI, will no longer be supported. For more information, see
[Network Protocol Support in Windows](https://learn.microsoft.com/windows/desktop/WinSock/network-protocol-support-in-windows).

## See also

[NetWkstaTransportAdd](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstatransportadd)

[NetWkstaTransportEnum](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstatransportenum)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server and Workstation Transport Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-and-workstation-transport-functions)