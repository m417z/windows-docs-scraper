# IVssProviderCreateSnapshotSet::AbortSnapshots

## Description

The **AbortSnapshots**
method aborts prepared shadow copies in this provider. This includes all non-committed shadow
copies and pre-committed ones.

## Parameters

### `SnapshotSetId` [in]

The **VSS_ID** that identifies the shadow copy set.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The *SnapshotSetId* parameter refers to an object that was not found. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. The provider must log a message in the application event log providing the user with information on how to resolve the problem. |

## Remarks

VSS will only call
**AbortSnapshots** after the
requester has called
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset),
even if the shadow copy fails or is aborted before this point. This means that a provider will not receive an
**AbortSnapshots** call until
after [EndPrepareSnapshots](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivssprovidercreatesnapshotset-endpreparesnapshots)
has been called. If a shadow copy is aborted or fails before this point, the provider is not given any indication
until a new shadow copy is started. For this reason, the provider must be prepared to handle an out-of-sequence
[IVssHardwareSnapshotProvider::BeginPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-beginpreparesnapshot)
call at any point. This out-of-sequence call represents the start of a new shadow copy creation sequence and will
have a new shadow copy set ID.

## See also

[IVssProviderCreateSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssprovidercreatesnapshotset)