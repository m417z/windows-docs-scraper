# DSROLE_SERVER_STATE enumeration

## Description

The **DSROLE_SERVER_STATE** enumeration is used with the [DSROLE_UPGRADE_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/dsrole/ns-dsrole-dsrole_upgrade_status_info) structure to indicate the role of a server.

## Constants

### `DsRoleServerUnknown:0`

The server role is unknown.

### `DsRoleServerPrimary`

The server was, or is, a primary domain controller.

### `DsRoleServerBackup`

The server was, or is, a backup domain controller.

## See also

[DSROLE_UPGRADE_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/dsrole/ns-dsrole-dsrole_upgrade_status_info)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)