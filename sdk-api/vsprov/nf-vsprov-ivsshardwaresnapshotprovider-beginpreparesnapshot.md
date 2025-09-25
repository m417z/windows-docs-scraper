# IVssHardwareSnapshotProvider::BeginPrepareSnapshot

## Description

The **BeginPrepareSnapshot**
method is called for each shadow copy that is added to the shadow copy set.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `SnapshotSetId` [in]

Shadow copy set identifier.

### `SnapshotId` [in]

Identifier of the shadow copy to be created.

### `lContext` [in]

Shadow copy context for current shadow copy set as enumerated by
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes).

### `lLunCount` [in]

Count of LUNs contributing to this shadow copy volume.

### `rgDeviceNames` [in]

Pointer to array of *lLunCount* pointers to strings, each string containing
the name of a LUN to be shadow copied.

### `rgLunInformation` [in, out]

Pointer to array of *lLunCount*[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN
contributing to this shadow copy volume.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| ****S_OK****<br><br>0x00000000L | The operation was successfully completed. |
| ****E_OUTOFMEMORY****<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| ****VSS_E_MAXIMUM_NUMBER_OF_VOLUMES_REACHED****<br><br>0x80042312L | The provider has reached the maximum number of volumes it can support. |
| **VSS_E_NESTED_VOLUME_LIMIT** | The specified volume is nested too deeply to participate in the VSS operation.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This return code is not supported. |
| ****VSS_E_PROVIDER_VETO****<br><br>0x80042306L | An unexpected provider error occurred. The provider must report an event in the application event log providing the user with information on how to resolve the problem. |
| ****VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER****<br><br>0x8004230EL | The provider does not support this volume. |
| ****VSS_E_UNSUPPORTED_CONTEXT****<br><br>0x8004231BL | The context specified by *lContext* is not supported. |

## Remarks

This method cannot be called for a virtual hard disk (VHD) that is nested inside another VHD.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** VHDs are not supported.

## See also

[IVssHardwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotprovider)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)