# DSROLE_MACHINE_ROLE enumeration

## Description

The **DSROLE_MACHINE_ROLE** enumeration is used with the **MachineRole** member of the [DSROLE_PRIMARY_DOMAIN_INFO_BASIC](https://learn.microsoft.com/windows/desktop/api/dsrole/ns-dsrole-dsrole_primary_domain_info_basic) structure to specify the computer role.

## Constants

### `DsRole_RoleStandaloneWorkstation`

The computer is a workstation that is not a member of a domain.

### `DsRole_RoleMemberWorkstation`

The computer is a workstation that is a member of a domain.

### `DsRole_RoleStandaloneServer`

The computer is a server that is not a member of a domain.

### `DsRole_RoleMemberServer`

The computer is a server that is a member of a domain.

### `DsRole_RoleBackupDomainController`

The computer is a backup domain controller.

### `DsRole_RolePrimaryDomainController`

The computer is a primary domain controller.

## See also

[DSROLE_PRIMARY_DOMAIN_INFO_BASIC](https://learn.microsoft.com/windows/desktop/api/dsrole/ns-dsrole-dsrole_primary_domain_info_basic)

[Enumerations in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/enumerations-in-active-directory-domain-services)