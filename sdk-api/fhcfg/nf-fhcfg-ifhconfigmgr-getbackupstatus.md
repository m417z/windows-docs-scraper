# IFhConfigMgr::GetBackupStatus

## Description

Retrieves the backup status value for an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `BackupStatus` [out]

Receives the backup status value. See the [FH_BACKUP_STATUS](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_backup_status) enumeration for the list of possible backup status values.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## See also

[FH_BACKUP_STATUS](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_backup_status)

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::SetBackupStatus](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setbackupstatus)