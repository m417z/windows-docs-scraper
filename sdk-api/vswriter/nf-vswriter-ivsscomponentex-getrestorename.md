# IVssComponentEx::GetRestoreName

## Description

Obtains the logical name assigned to a component that is being restored.

## Parameters

### `pbstrName` [out]

The address of a caller-allocated variable that receives a null-terminated wide character string containing the restore name for the component.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## Remarks

The [GetRestoreName](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrestorename) method can only be called during a restore operation.

If the call to [GetRestoreName](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrestorename) is successful, the caller is responsible for freeing the string that is returned in the *pbstrName* parameter by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

A writer indicates that it supports this method by setting the **VSS_BS_RESTORE_RENAME** flag in its backup schema mask.

For more
information, see [Setting VSS Restore
Options](https://learn.microsoft.com/windows/desktop/VSS/setting-vss-restore-options).

## See also

[IVssBackupComponentsEx2::SetRestoreName](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrestorename)

[IVssComponentEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponentex)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)