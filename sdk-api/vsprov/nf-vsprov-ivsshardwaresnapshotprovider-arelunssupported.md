# IVssHardwareSnapshotProvider::AreLunsSupported

## Description

The **AreLunsSupported** method determines whether the hardware provider supports shadow copy creation for all LUNs that contribute to the volume. VSS calls the **AreLunsSupported**
method for each volume that is added to the shadow copy set. Before
calling this method, VSS determines the LUNs that contribute to the volume.

For a specific volume, each LUN can contribute only once. A specific LUN may contribute to multiple volumes.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `lLunCount` [in]

Count of LUNs contributing to this shadow copy volume.

### `lContext` [in]

Shadow copy context for the current shadow copy set as enumerated by
a bitmask of flags from the [_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) enumeration. If the **VSS_VOLSNAP_ATTR_TRANSPORTABLE** flag is set, the shadow copy set is transportable.

### `rgwszDevices` [in]

List of devices corresponding to the LUNs to be shadow copied.

### `pLunInformation` [in, out]

Array of *lLunCount*[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN
contributing to this shadow copy volume.

### `pbIsSupported` [out]

Pointer to a **BOOL** value. If all devices are supported for shadow copy, the
provider should store a **TRUE** value at the location pointed to by
*pbIsSupported*.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error occurred. The provider must report an event in the application event log providing the user with information on how to resolve the problem. |

## Remarks

If the hardware subsystem supports the SCSI Inquiry Data and Vital Product Data
page 80 (device serial number) and page 83 (device identity) guidelines, the provider should not need to modify the structures in the *pLunInformation* array.

In any case, the **AreLunsSupported** method should not modify the value of the **m_rgInterconnects** member of any [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure in the *pLunInformation* array.

If the provider supports hardware shadow copy creation for all of the LUNs in the *pLunInformation* array, it should return **TRUE** in the **BOOL** value that the *pbIsSupported* parameter points to. If the provider does not support hardware shadow copies for one or more LUNs, it must set this **BOOL** value to **FALSE**.

The provider must never agree to create shadow copies if it cannot, even if the problem is only temporary. If a transient condition, such as low resources, makes it impossible for the provider to create a shadow copy using one or more LUNs when **AreLunsSupported** is called, the provider must set the **BOOL** value to **FALSE**.

## See also

[IVssHardwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotprovider)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)