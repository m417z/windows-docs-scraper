# NETCON_CHARACTERISTIC_FLAGS enumeration

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**NETCON_CHARACTERISTIC_FLAGS** enumeration type specifies possible characteristics for a network connection.

## Constants

### `NCCF_NONE:0`

No special characteristics.

### `NCCF_ALL_USERS:0x1`

Connection is available to all users.

### `NCCF_ALLOW_DUPLICATION:0x2`

Connection is duplicable.

### `NCCF_ALLOW_REMOVAL:0x4`

Connection is removable.

### `NCCF_ALLOW_RENAME:0x8`

Connection can be renamed.

### `NCCF_INCOMING_ONLY:0x20`

Direction is "incoming" only.

### `NCCF_OUTGOING_ONLY:0x40`

Direction is "outgoing" only.

### `NCCF_BRANDED:0x80`

Icons are branded.

### `NCCF_SHARED:0x100`

Connection is shared.

### `NCCF_BRIDGED:0x200`

Connection is bridged.

### `NCCF_FIREWALLED:0x400`

Connection is firewalled.

### `NCCF_DEFAULT:0x800`

Connection is the default connection.

### `NCCF_HOMENET_CAPABLE:0x1000`

Device supports home networking.

### `NCCF_SHARED_PRIVATE:0x2000`

Connection is private (part of ICS).

### `NCCF_QUARANTINED:0x4000`

Connection is quarantined.

### `NCCF_RESERVED:0x8000`

Unused.

### `NCCF_HOSTED_NETWORK:0x10000`

### `NCCF_VIRTUAL_STATION:0x20000`

### `NCCF_WIFI_DIRECT:0x40000`

### `NCCF_BLUETOOTH_MASK:0xf0000`

Bluetooth characteristics.

### `NCCF_LAN_MASK:0xf00000`

LAN characteristics.

## See also

[INetConnection](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnection)

[Internet Connection Sharing and Internet Connection Firewall Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-enumeration-types)

[Internet Connection Sharing and Internet Connection Firewall Reference](https://learn.microsoft.com/previous-versions/windows/desktop/ics/internet-connection-sharing-and-internet-connection-firewall-reference)

[NETCON_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/netcon/ns-netcon-netcon_properties)