# IVssBackupComponents::RevertToSnapshot

## Description

The **RevertToSnapshot** method
reverts a volume to a previous shadow copy. Only shadow copies created with persistent contexts
(**VSS_CTX_APP_ROLLBACK**, **VSS_CTX_CLIENT_ACCESSIBLE**,
**VSS_CTX_CLIENT_ACCESSIBLE_WRITERS**, or
**VSS_CTX_NAS_ROLLBACK**) are supported.

**Note** This method is only supported on Windows Server operating systems.

## Parameters

### `SnapshotId` [in]

VSS_ID of the shadow copy to revert.

### `bForceDismount` [in]

If this parameter is
**TRUE**, the volume will be dismounted and reverted even if the volume is in use.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_ACCESSDENIED** | The calling process has insufficient privileges. |
| **E_FAIL** | There is an internal error. |
| **E_INVALIDARG** | One of the parameters passed is not valid. |
| **E_NOTIMPL** | The provider for the volume does not support revert operations. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The *SnapshotId* parameter is not a valid shadow copy. |
| **VSS_E_PROVIDER_NOT_REGISTERED** | The provider was not found. |
| **VSS_E_REVERT_IN_PROGRESS** | The volume already has a revert in process. |
| **VSS_E_UNSUPPORTED_CONTEXT** | Revert is only supported for persistent shadow copies. |
| **VSS_E_VOLUME_IN_USE** | The *bForceDismount* parameter was **FALSE**, and the volume could not be locked. |
| **VSS_E_VOLUME_NOT_SUPPORTED** | Revert is not supported on this volume. |

## Remarks

This operation cannot be canceled, or undone once completed. If the computer is rebooted during the revert
operation, the revert process will continue when the system is restarted.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::QueryRevertStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-queryrevertstatus)