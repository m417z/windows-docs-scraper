# IVssHardwareSnapshotProvider::OnLunEmpty

## Description

The **OnLunEmpty** method is
called whenever VSS determines that a shadow copy LUN contains no interesting data. All
shadow copies have been deleted (which also causes deletion of the LUN.) The LUN resources may be reclaimed by the
provider and reused for another purpose. VSS will dismount any affected volumes. A provider should not issue a
rescan during **OnLunEmpty**. VSS
will handle this cleanup.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `wszDeviceName` [in]

Device corresponding to the LUN that contains the shadow copy to be deleted.

### `pInformation` [in]

Pointer to a [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure
containing information about the LUN containing the shadow copy to be deleted.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. The provider must report an event in the application event log providing the user with information on how to resolve the problem. |

## Remarks

Hardware providers should delete a shadow copy and reclaim the LUN if and only if
**OnLunEmpty** is being called. A
hardware shadow copy may be used as the backup media itself, therefore the LUNs should be treated with the same
care the storage array treats LUNs used for regular disks. Reclaiming LUNs outside of processing for
**OnLunEmpty** should be limited to
emergency or an administrator performing explicit action manually.

In the case of persistent shadow copies, the requester deletes the shadow copy when it is no longer needed. In the case of
nonpersistent auto-release shadow copies, the VSS service deletes the shadow copy when the requester calls [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the [IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) object. In the case of nonpersistent non-auto-release shadow copies, the VSS service deletes the shadow copy when the computer is restarted. In all cases, the VSS service calls the provider's **OnLunEmpty** method as needed for each shadow copy
LUN.

Note that **OnLunEmpty** is
called on a best effort basis. VSS invokes the method only when the LUN is guaranteed to be empty. There may be
many cases where the LUN is empty but VSS is unable to detect this due to errors or external circumstances. In
this case, the user should use storage management software to clear this state.

Some examples:

* When a shadow copy LUN is moved to a different host but not actually transported or imported through VSS,
  then that LUN appears as any other LUN, and volumes can be simply deleted without any notification of VSS.
* A crash or unexpected reboot in the middle of a shadow copy creation.
* A canceled import.

## See also

[IVssHardwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotprovider)