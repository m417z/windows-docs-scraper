# INET_FIREWALL_AC_CHANGE structure

## Description

The [INET_FIREWALL_AC_CHANGE](https://learn.microsoft.com/windows/desktop/api/netfw/ne-netfw-inet_firewall_ac_change_type) structure contains information about a change made to an app container.

## Members

### `changeType`

Type: **[INET_FIREWALL_AC_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/netfw/ne-netfw-inet_firewall_ac_change_type)**

The type of change made.

### `createType`

Type: **[INET_FIREWALL_AC_CREATION_TYPE](https://learn.microsoft.com/windows/desktop/api/networkisolation/ne-networkisolation-inet_firewall_ac_creation_type)**

The method by which the app container was created.

### `appContainerSid`

Type: **SID***

The package identifier of the app container

### `userSid`

Type: **SID***

The security identifier (SID) of the user to whom the app container belongs.

### `displayName`

Type: **LPWSTR**

Friendly name of the app container.

### `capabilities`

Type: **[INET_FIREWALL_AC_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/networkisolation/ns-networkisolation-inet_firewall_ac_capabilities)**

Information about the capabilities of the changed app container.

### `binaries`

Type: **[INET_FIREWALL_AC_BINARIES](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_ac_binaries)**

Binary paths to the applications running in the changed app container.

## See also

[INET_FIREWALL_AC_BINARIES](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_ac_binaries)

[INET_FIREWALL_AC_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/networkisolation/ns-networkisolation-inet_firewall_ac_capabilities)

[INET_FIREWALL_AC_CHANGE_TYPE](https://learn.microsoft.com/windows/desktop/api/netfw/ne-netfw-inet_firewall_ac_change_type)

[INET_FIREWALL_AC_CREATION_TYPE](https://learn.microsoft.com/windows/desktop/api/networkisolation/ne-networkisolation-inet_firewall_ac_creation_type)