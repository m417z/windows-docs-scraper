# FH_RETENTION_TYPES enumeration

## Description

Specifies under what conditions previous versions of files and folders can be deleted from a backup target.

## Constants

### `FH_RETENTION_DISABLED:0`

Previous versions are never deleted from the backup target.

### `FH_RETENTION_UNLIMITED`

The operating system can delete any previous version on an as-needed basis, unless it is the most recent version of a file that currently exists and is within the protection scope.

### `FH_RETENTION_AGE_BASED`

The operating system can delete any previous version older than the specified minimum age on as-needed basis, unless it is the most recent version of a file that currently exists and is within the protection scope. The minimum age is specified by the **FH_RETENTION_AGE** local policy.

### `MAX_RETENTION_TYPE`

The maximum enumeration value for this enumeration. This value and all values greater than it are reserved for system use.

## Remarks

The operating system deletes previous versions from a backup target only when the target is full or when the user has initiated data retention manually by using the File History item in Control Panel.

If **FH_RETENTION_AGE_BASED** is specified and the target is large enough, it is possible for the target to contain versions that are much older than the minimum age that is specified by the **FH_RETENTION_AGE** local policy.

## See also

[IFhConfigMgr::GetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getlocalpolicy)

[IFhConfigMgr::SetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setlocalpolicy)