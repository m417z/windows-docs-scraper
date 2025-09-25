# NETCON_TYPE enumeration

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**NETCON_TYPE** type enumerates the various kinds of network connections.

## Constants

### `NCT_DIRECT_CONNECT:0`

Direct serial connection through a serial port.

### `NCT_INBOUND:1`

Another computer dials in to the local computer through this connection.

### `NCT_INTERNET`

The connection is to the public Internet.

### `NCT_LAN`

The connection is to a local area network (LAN).

### `NCT_PHONE`

The connection is a dial-up connection over a phone line.

### `NCT_TUNNEL`

The connection is a virtual private network (VPN) connection.

### `NCT_BRIDGE`

The connection is a bridged connection.

## See also

[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection)

[Internet Connection Sharing and Internet Connection Firewall Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-enumeration-types)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)

[NETCON_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/netcon/ns-netcon-netcon_properties)