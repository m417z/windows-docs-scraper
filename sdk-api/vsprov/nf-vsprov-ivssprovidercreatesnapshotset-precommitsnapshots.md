# IVssProviderCreateSnapshotSet::PreCommitSnapshots

## Description

The **PreCommitSnapshots**
method ensures the provider is ready to quickly commit the prepared LUNs. This happens
immediately before the flush-and-hold writes, but while applications are in a frozen state. During this call the
provider should prepare all shadow copies in the shadow copy set indicated by *SnapshotSetId*
for committing by the
[CommitSnapshots](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivssprovidercreatesnapshotset-commitsnapshots) method call
that will follow. While the provider is processing this method, the applications have been frozen, so the time
spent in this method should be minimized.

## Parameters

### `SnapshotSetId` [in]

The **VSS_ID** that identifies the shadow copy set.

## Return value

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The *SnapshotSetId* parameter refers to an object that was not found. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. If this is returned, the error must be described in an entry in the application event log, giving the user information on how to resolve the problem. |

If any other value is returned, VSS will write an event to the event log and convert the error to
**VSS_E_UNEXPECTED_PROVIDER_ERROR**.

## See also

[IVssProviderCreateSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssprovidercreatesnapshotset)