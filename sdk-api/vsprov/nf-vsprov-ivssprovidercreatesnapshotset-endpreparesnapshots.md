# IVssProviderCreateSnapshotSet::EndPrepareSnapshots

## Description

The **EndPrepareSnapshots**
method is called once for the complete shadow copy set, after the last
[IVssHardwareSnapshotProvider::BeginPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-beginpreparesnapshot)
call. This method is intended as a point where the provider can wait for any shadow copy preparation
work to complete. Because
**EndPrepareSnapshots** may
take a long time to complete, a provider should be prepared to accept an
[AbortSnapshots](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivssprovidercreatesnapshotset-abortsnapshots) method call
at any time and immediately end the preparation work.

## Parameters

### `SnapshotSetId` [in]

The **VSS_ID** of the shadow copy set.

## Return value

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_INSUFFICIENT_STORAGE**<br><br>0x8004231FL | There is not enough disk storage to create a shadow copy. Insufficient disk space can also generate **VSS_E_PROVIDER_VETO** or **VSS_E_OBJECT_NOT_FOUND** error return values. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The *SnapshotSetId* parameter refers to an object that was not found. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. If this is returned, the error must be described in an entry in the application event log, giving the user information on how to resolve the problem. |

If any other value is returned, VSS will write an event to the event log and convert the error to
**VSS_E_UNEXPECTED_PROVIDER_ERROR**.

## See also

[AbortSnapshots](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivssprovidercreatesnapshotset-abortsnapshots)

[IVssHardwareSnapshotProvider::BeginPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-beginpreparesnapshot)

[IVssProviderCreateSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssprovidercreatesnapshotset)