# FH_BACKUP_STATUS enumeration

## Description

Specifies whether File History backups are enabled.

## Constants

### `FH_STATUS_DISABLED:0`

File History backups are not enabled by the user.

### `FH_STATUS_DISABLED_BY_GP`

File History backups are disabled by Group Policy.

### `FH_STATUS_ENABLED`

File History backups are enabled.

### `FH_STATUS_REHYDRATING`

### `MAX_BACKUP_STATUS`

The maximum enumeration value for this enumeration. This value and all values greater than it are reserved for system use.

## Remarks

The protection scope is the set of files and folders that are backed up by the File History feature. The default protection scope includes all folders from all user libraries and the Contacts, Desktop, and Favorites folders.

The **FH_STATUS_DISABLED_BY_GP** status can be queried by calling the [IFhConfigMgr::GetBackupStatus](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getbackupstatus) method, but it cannot be set by calling the [IFhConfigMgr::SetBackupStatus](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setbackupstatus) method. This is because it can only be set by Group Policy.

## See also

[IFhConfigMgr::GetBackupStatus](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getbackupstatus)

[IFhConfigMgr::SetBackupStatus](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setbackupstatus)