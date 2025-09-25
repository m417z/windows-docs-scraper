# NETCON_MEDIATYPE enumeration

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The values of the **NETCON_MEDIATYPE** enumerate the possible ways the computer connects to the network.

## Constants

### `NCM_NONE:0`

No media is present.

### `NCM_DIRECT`

Direct serial connection through a serial port.

### `NCM_ISDN:2`

Connection is through an integrated services digital network (ISDN) line.

### `NCM_LAN`

Connection is to a local area network (LAN).

### `NCM_PHONE`

Dial-up connection over a conventional phone line.

### `NCM_TUNNEL`

Virtual private network (VPN) connection.

### `NCM_PPPOE`

Point-to-Point protocol (PPP) over Ethernet.

### `NCM_BRIDGE`

Bridged connection.

### `NCM_SHAREDACCESSHOST_LAN`

Shared connection to a LAN.

### `NCM_SHAREDACCESSHOST_RAS`

Shared connection to a remote or wide area network (WAN).

## See also

[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection)

[Internet Connection Sharing and Internet Connection Firewall Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-enumeration-types)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)

[NETCON_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/netcon/ns-netcon-netcon_properties)