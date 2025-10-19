# IVssProviderCreateSnapshotSet::PostFinalCommitSnapshots

## Description

The
**PostFinalCommitSnapshots**
method supports
[auto-recover](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-a) shadow
copies. VSS calls this method to notify the provider that the volume will now be read-only until a requester calls [IVssBackupComponents::BreakSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-breaksnapshotset).

## Parameters

### `SnapshotSetId` [in]

The **VSS_ID** that identifies the shadow copy set.

## Return value

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. If this is returned, the error must be described in an entry in the application event log, giving the user information on how to resolve the problem. |

If any other value is returned, VSS will write an event to the event log and convert the error to
**VSS_E_UNEXPECTED_PROVIDER_ERROR**.

## Remarks

This method was added in Windows Server 2003 to enable binary compatibility when the
[auto-recover](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-a) feature was
introduced in Windows Server 2003 with Service Pack 1 (SP1).

**Note** For Windows Server 2003, it is recommended that hardware providers implement this method using
the following example:

```cpp
HRESULT PostFinalCommitSnapshots(
    VSS_ID     /* SnapshotSetId */
)
{
    return S_OK;
}

```

## See also

[IVssProviderCreateSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssprovidercreatesnapshotset)