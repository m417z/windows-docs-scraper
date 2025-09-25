# INET_FIREWALL_AC_CREATION_TYPE enumeration

## Description

The **INET_FIREWALL_AC_CREATION_TYPE** enumeration specifies the type of app container creation events for which notifications will be delivered.

## Constants

### `INET_FIREWALL_AC_NONE:0x00`

This value is reserved for system use.

### `INET_FIREWALL_AC_PACKAGE_ID_ONLY:0x01`

Notifications will be delivered when an app container is created with a package identifier.

### `INET_FIREWALL_AC_BINARY:0x02`

Notifications will be delivered when an app container is created with a binary path.

### `INET_FIREWALL_AC_MAX:0x04`

Maximum value for testing purposes.

## See also

[INET_FIREWALL_AC_CHANGE](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_ac_change)