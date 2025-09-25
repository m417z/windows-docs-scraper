# NETCON_PROPERTIES structure

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**NETCON_PROPERTIES** structure stores values that describe the properties of a network connection.

## Members

### `guidId`

Globally-unique identifier (GUID) for this connection.

### `pszwName`

Name of the connection itself.

### `pszwDeviceName`

Name of the device associated with the connection.

### `Status`

[Current status](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_status) of the connection.

### `MediaType`

[Media type](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_mediatype) associated with this connection.

### `dwCharacter`

[Characteristics](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_characteristic_flags) for this connection.

### `clsidThisObject`

Class identifier for the connection object.

### `clsidUiObject`

Class identifier for the user-interface object.

## See also

[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection)

[Internet Connection Sharing and Internet Connection Firewall
Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)

[Internet Connection Sharing and Internet Connection Firewall
Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-structures)

[NETCON_CHARACTERISTIC_FLAGS](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_characteristic_flags)

[NETCON_MEDIATYPE](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_mediatype)

[NETCON_STATUS](https://learn.microsoft.com/windows/desktop/api/netcon/ne-netcon-netcon_status)