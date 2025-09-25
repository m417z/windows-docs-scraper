# INET_FIREWALL_APP_CONTAINER structure

## Description

The **INET_FIREWALL_APP_CONTAINER** structure contains information about a specific app container.

## Members

### `appContainerSid`

Type: **SID***

The package identifier of the app container

### `userSid`

Type: **SID***

The security identifier (SID) of the user to whom the app container belongs.

### `appContainerName`

Type: **LPWSTR**

The app container's globally unique name.

 Also referred to as the Package Family Name, for the app container of a Windows Store app.

### `displayName`

Type: **LPWSTR**

Friendly name of the app container

### `description`

Type: **LPWSTR**

A description of the app container (its use, the objective of the application that uses it, etc.)

### `capabilities`

Type: **[INET_FIREWALL_AC_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/networkisolation/ns-networkisolation-inet_firewall_ac_capabilities)**

The capabilities of the app container.

### `binaries`

Type: **[INET_FIREWALL_AC_BINARIES](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_ac_binaries)**

Binary paths to the applications running in the app container.

### `workingDirectory`

### `packageFullName`

## See also

[INET_FIREWALL_AC_BINARIES](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_ac_binaries)

[INET_FIREWALL_AC_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/networkisolation/ns-networkisolation-inet_firewall_ac_capabilities)