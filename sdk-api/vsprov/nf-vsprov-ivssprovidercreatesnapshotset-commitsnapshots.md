# IVssProviderCreateSnapshotSet::CommitSnapshots

## Description

The **CommitSnapshots**
method quickly commits all LUNs in this provider.

## Parameters

### `SnapshotSetId` [in]

The **VSS_ID** that identifies the shadow copy set.

## Return value

| Return code/value | Description |
| --- | --- |
| ****S_OK****<br><br>0x00000000L | The operation was successfully completed. |
| ****E_OUTOFMEMORY****<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| ****VSS_E_OBJECT_NOT_FOUND****<br><br>0x80042308L | The *SnapshotSetId* parameter refers to an object that was not found. |
| ****VSS_E_PROVIDER_VETO****<br><br>0x80042306L | An unexpected provider error occurred. The provider must log the details of this error in the application event log. |

If any other value is returned, VSS will write an event to the event log and convert the error to
**VSS_E_UNEXPECTED_PROVIDER_ERROR**.

## Remarks

This method is called at the defined time at which the shadow copies should be taken. For each prepared LUN
in this shadow copy set, the provider will perform the work required to persist the point-in-time LUN contents.
While this method is executing, both applications and the I/O subsystem are largely quiescent. The provider must
minimize the amount of time spent in this method. As a general rule, this method should take less than one second
to complete. This method is called during the Flush and Hold window, and VSS Kernel Support will
cancel the Flush and Hold if the release is not received within 10 seconds, which would cause VSS to fail the
shadow copy creation process. If each provider takes more than a second or two to complete this call, there is a
high probability that the entire shadow copy creation will fail.

Because the I/O system is quiescent, the provider must take care to not initiate any I/O as it could deadlock
the system - for example debug or tracing I/O by this method or any calls made from this method. Memory mapped
files and paging I/O will not be frozen at this time.

Note that the I/O system is quiescent only while this method is executing. Immediately after the last provider's **CommitSnapshots** method returns, the VSS service releases all pending writes on the source LUNs. If the provider performs any synchronization of the source and shadow copy LUNs, this synchronization must be completed before the provider's **CommitSnapshots** method returns; it cannot be performed asynchronously.

## See also

[IVssProviderCreateSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssprovidercreatesnapshotset)