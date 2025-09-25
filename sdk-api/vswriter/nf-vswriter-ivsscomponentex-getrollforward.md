# IVssComponentEx::GetRollForward

## Description

Obtains the roll-forward operation type for a component and obtains the restore point for a partial roll-forward operation.

## Parameters

### `pRollType` [out]

A [VSS_ROLLFORWARD_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_rollforward_type) enumeration value indicating the type of roll-forward operation to be performed.

### `pbstrPoint` [out]

The address of a caller-allocated variable that receives a null-terminated wide character string specifying the roll-forward restore point.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## Remarks

The **GetRollForward** method can be called only during a restore operation.

If the call to **GetRollForward** is successful, the caller is responsible for freeing the string that is returned in the *pRollType* parameter by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

A writer indicates that it supports this method by setting the **VSS_BS_ROLLFORWARD_RESTORE** flag in its backup schema mask.

For more
information, see [Setting VSS Restore
Options](https://learn.microsoft.com/windows/desktop/VSS/setting-vss-restore-options).

## See also

[IVssBackupComponentsEx2::SetRollForward](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrollforward)

[IVssComponentEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponentex)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)

[VSS_ROLLFORWARD_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_rollforward_type)