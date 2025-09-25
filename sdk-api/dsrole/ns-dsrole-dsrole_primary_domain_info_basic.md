# DSROLE_PRIMARY_DOMAIN_INFO_BASIC structure

## Description

The **DSROLE_PRIMARY_DOMAIN_INFO_BASIC** structure is used with the [DsRoleGetPrimaryDomainInformation](https://learn.microsoft.com/windows/desktop/api/dsrole/nf-dsrole-dsrolegetprimarydomaininformation) function to contain domain data.

## Members

### `MachineRole`

Contains one of the [DSROLE_MACHINE_ROLE](https://learn.microsoft.com/windows/desktop/api/dsrole/ne-dsrole-dsrole_machine_role) values that specifies the role of the computer.

### `Flags`

Contains a set of flags that provide additional domain data. This can be a combination of one or more of the following values.

#### DSROLE_PRIMARY_DOMAIN_GUID_PRESENT

The **DomainGuid** member contains a valid domain **GUID**.

#### DSROLE_PRIMARY_DS_MIXED_MODE

The directory service is running in mixed mode. This flag is valid only if the **DSROLE_PRIMARY_DS_RUNNING** flag is set.

#### DSROLE_PRIMARY_DS_RUNNING

The directory service is running on this computer.

#### DSROLE_PRIMARY_DS_READONLY

The directory service is running as read-only on this computer.

#### DSROLE_UPGRADE_IN_PROGRESS

The computer is being upgraded from a previous version of Windows NT/Windows 2000.

### `DomainNameFlat`

Pointer to a null-terminated Unicode string that contains the NetBIOS domain name.

### `DomainNameDns`

Pointer to a null-terminated Unicode string that contains the DNS domain name. This member is optional and may be **NULL**.

### `DomainForestName`

Pointer to a null-terminated Unicode string that contains the forest name. This member is optional and may be **NULL**.

### `DomainGuid`

Contains the domain identifier. This member is valid only if the **Flags** member contains the **DSROLE_PRIMARY_DOMAIN_GUID_PRESENT** flag.

## See also

[DSROLE_MACHINE_ROLE](https://learn.microsoft.com/windows/desktop/api/dsrole/ne-dsrole-dsrole_machine_role)

[Directory Service Structures](https://learn.microsoft.com/windows/desktop/AD/directory-service-structures)

[DsRoleGetPrimaryDomainInformation](https://learn.microsoft.com/windows/desktop/api/dsrole/nf-dsrole-dsrolegetprimarydomaininformation)