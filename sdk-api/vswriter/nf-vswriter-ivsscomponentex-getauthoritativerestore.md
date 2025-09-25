# IVssComponentEx::GetAuthoritativeRestore

## Description

Determines whether a requester has marked the restore of a component as authoritative for a replicated data store.

## Parameters

### `pbAuth` [out]

The address of a caller-allocated variable that receives **true** if the restore is authoritative, or **false** otherwise.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## Remarks

A writer indicates that it supports authoritative restore by setting the **VSS_BS_AUTHORITATIVE_RESTORE** flag in its backup schema mask.

For more
information, see [Setting VSS Restore
Options](https://learn.microsoft.com/windows/desktop/VSS/setting-vss-restore-options).

## See also

[IVssBackupComponentsEx2::SetAuthoritativeRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setauthoritativerestore)

[IVssComponentEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponentex)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)