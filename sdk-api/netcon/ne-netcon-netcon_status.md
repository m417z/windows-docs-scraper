# NETCON_STATUS enumeration

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**NETCON_STATUS** type enumerates possible status conditions for a network connection.

## Constants

### `NCS_DISCONNECTED:0`

The connection is disconnected.

### `NCS_CONNECTING`

The connection is in the process of connecting.

### `NCS_CONNECTED`

The connection is in a connected state.

### `NCS_DISCONNECTING`

The connection is in the process of disconnecting.

### `NCS_HARDWARE_NOT_PRESENT`

The hardware for the connection, for example network interface card (NIC), is not present.

### `NCS_HARDWARE_DISABLED`

The hardware for the connection is present, but is not enabled.

### `NCS_HARDWARE_MALFUNCTION`

A malfunction has occurred in the hardware for the connection.

### `NCS_MEDIA_DISCONNECTED`

The media, for example the network cable, is disconnected.

### `NCS_AUTHENTICATING`

The connection is waiting for authentication to occur.

### `NCS_AUTHENTICATION_SUCCEEDED`

Authentication has succeeded on this connection.

### `NCS_AUTHENTICATION_FAILED`

Authentication has failed on this connection.

### `NCS_INVALID_ADDRESS`

The address is invalid.

### `NCS_CREDENTIALS_REQUIRED`

Security credentials are required.

### `NCS_ACTION_REQUIRED`

### `NCS_ACTION_REQUIRED_RETRY`

### `NCS_CONNECT_FAILED`

## See also

[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection)

[Internet Connection Sharing and Internet Connection Firewall Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-enumeration-types)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)

[NETCON_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/netcon/ns-netcon-netcon_properties)