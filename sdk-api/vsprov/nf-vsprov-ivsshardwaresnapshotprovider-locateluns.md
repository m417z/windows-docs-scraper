# IVssHardwareSnapshotProvider::LocateLuns

## Description

The **LocateLuns** method prompts the hardware provider to make the shadow copy LUNs visible to the computer. The **LocateLuns** method is called by VSS when a hardware shadow copy set is imported to a computer.
The provider is
responsible for any unmasking (or "surfacing") at the hardware level.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `lLunCount` [in]

Number of LUNs that contribute to this shadow copy set.

### `rgSourceLuns` [in]

Pointer to an array of *iLunCount*[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN
that is part of the shadow copy set to be imported.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| ****S_OK****<br><br>0x00000000L | The operation was successfully completed. |
| ****E_OUTOFMEMORY****<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| ****VSS_E_PROVIDER_VETO****<br><br>0x80042306L | An unexpected provider error occurred. The provider must report an event in the application event log providing the user with information on how to resolve the problem. |

## Remarks

In the *rgSourceLuns* parameter, VSS supplies the same array of [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)
structures that the provider previously initialized in its [IVssHardwareSnapshotProvider::GetTargetLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-gettargetluns) method. For each **VDS_LUN_INFORMATION**
structure in the array, the provider should unmask (or "surface") the corresponding shadow copy LUN to the computer.

Immediately after this method returns, VSS will perform a rescan and enumeration to detect any arrived
devices. This causes any exposed LUNs to be discovered by the PnP manager. In parallel with listening for disk arrivals, VSS
will also listen for hidden volume arrivals. VSS will stop listening after all volumes that contribute to a shadow copy set
appear in the system or a time-out occurs. If some disk or volume devices fail to appear in this window, the
requester will be told that only some of the shadow copies were imported by VSS returning
**VSS_S_SOME_SNAPSHOTS_NOT_IMPORTED** to the requester. The requester will also receive the
same error from VSS if the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)
structures received from the
[GetTargetLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-gettargetluns) and
[IVssHardwareSnapshotProvider::FillInLunInfo](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-fillinluninfo) methods do not match.

This method cannot be used to map shadow copy LUNs as read-only.

## See also

[AreLunsSupported](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-arelunssupported)

[FillInLunInfo](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-fillinluninfo)

[GetTargetLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-gettargetluns)

[IVssHardwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotprovider)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)