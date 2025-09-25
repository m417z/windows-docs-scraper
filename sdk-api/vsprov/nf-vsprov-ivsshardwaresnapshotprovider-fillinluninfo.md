# IVssHardwareSnapshotProvider::FillInLunInfo

## Description

The
**FillInLunInfo**
method prompts the hardware provider to indicate whether it supports the corresponding disk device and correct any omissions in the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure. VSS calls the
**FillInLunInfo**
method after the
[IVssHardwareSnapshotProvider::LocateLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-locateluns) method or before
the [IVssHardwareSnapshotProvider::OnLunEmpty](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-onlunempty) method to obtain the
[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure associated with a
shadow copy LUN. VSS will compare the
**VDS_LUN_INFORMATION** structure received in
the [IVssHardwareSnapshotProvider::GetTargetLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-gettargetluns) method to identify
shadow copy LUNs. If the structures do not match, the requester will receive
**VSS_S_SOME_SNAPSHOTS_NOT_IMPORTED**, which indicates a mismatch.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `wszDeviceName` [in]

Device corresponding to the shadow copy LUN.

### `pLunInfo` [in, out]

The [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure for the
shadow copy LUN.

### `pbIsSupported` [out]

The provider must return **TRUE** in the location pointed to by the
*pbIsSupported* parameter if the device is supported.

## Return value

VSS ignores this method's return value.

**Windows Server 2003:** VSS does not ignore the return value, which can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successfully completed. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **VSS_E_PROVIDER_VETO**<br><br>0x80042306L | An unexpected provider error has occurred. The provider must report an event in the application event log providing the user with information on how to resolve the problem. |

## Remarks

VSS calls the **FillInLunInfo** method for each [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure that the provider previously initialized in its [GetTargetLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-gettargetluns) method. VSS also calls the **FillInLunInfo** method for each new disk device that arrives in the system during the import process.

The provider can correct any omissions in the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure received in the *pLunInfo* parameter. However, the provider should not modify the value of the **m_rgInterconnects** member of this structure.

The members of the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure correspond to the SCSI Inquiry Data and Vital Product Data page 80 (device serial number) information, with the following exceptions:

* The **m_version** member must be set to **VER_VDS_LUN_INFORMATION**.
* The **m_BusType** member is ignored in comparisons during import. This value depends on the PnP storage stack on the corresponding disk device. Usually this is **VDSBusTypeScsi**.
* The **m_diskSignature** member is ignored in comparisons during import. The provider must set this member to GUID_NULL.

The members of the [VDS_STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_device_id_descriptor)
structure (in the **m_deviceIdDescriptor** member of the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)
structure) correspond to the page 83 information. In this structure, each [VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)
structure corresponds to the STORAGE_IDENTIFIER structure for a device identifier (that is, a storage identifier with an association type of zero). For more information about the STORAGE_IDENTIFIER structure, see the Windows Driver Kit (WDK) documentation.

If the **FillInLunInfo** method is
called for a LUN that is unknown to the provider, the provider should not return an error. Instead, it
should return **FALSE** in the **BOOL** value that the *pbIsSupported* parameter points to and
return success. If the provider recognizes the LUN, it should set the **BOOL** value to
**TRUE**.

## See also

[AreLunsSupported](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-arelunssupported)

[GetTargetLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-gettargetluns)

[IVssHardwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotprovider)

[LocateLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-locateluns)

[OnLunEmpty](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-onlunempty)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)

[VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)