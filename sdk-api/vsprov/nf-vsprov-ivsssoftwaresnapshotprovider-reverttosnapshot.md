# IVssSoftwareSnapshotProvider::RevertToSnapshot

## Description

Reverts a volume to a previous shadow copy. Only shadow copies created with persistent contexts (VSS_CTX_APP_ROLLBACK, VSS_CTX_CLIENT_ACCESSIBLE, VSS_CTX_CLIENT_ACCESSIBLE_WRITERS, or VSS_CTX_NAS_ROLLBACK) are supported.

## Parameters

### `SnapshotId` [in]

Shadow copy identifier of the shadow copy to revert.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The revert operation was successful. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| ****VSS_E_REVERT_IN_PROGRESS**** | The volume already has a revert operation in process. |

## Remarks

This operation cannot be canceled, or undone once completed. If the computer is rebooted during the revert operation, the revert process will continue when the system is restarted.

## See also

[IVssSoftwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsssoftwaresnapshotprovider)