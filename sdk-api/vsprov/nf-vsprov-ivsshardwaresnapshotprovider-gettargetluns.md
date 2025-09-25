# IVssHardwareSnapshotProvider::GetTargetLuns

## Description

The **GetTargetLuns** method prompts the hardware provider to initialize the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures for the newly created shadow copy LUNs. The **GetTargetLuns** method
is called after
the [IVssProviderCreateSnapshotSet::PostCommitSnapshots](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivssprovidercreatesnapshotset-postcommitsnapshots) method.
Identifying information for each newly created LUN is returned to VSS through
[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures.

**Note** Hardware providers are only supported on Windows Server operating systems.

## Parameters

### `lLunCount` [in]

Count of LUNs that contribute to the original volume.

### `rgDeviceNames` [in]

Pointer to an array of *lLunCount* pointers to strings. Each string contains
the name of an original LUN to be shadow copied.

### `rgSourceLuns` [in]

Pointer to an array of *lLunCount*[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each LUN
that contributes to the original volume.

### `rgDestinationLuns` [in, out]

Pointer to an array of *lLunCount*[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures, one for each new
shadow copy LUN created during shadow copy processing. There should be a one-to-one correspondence between the elements of
the *rgSourceLuns* and *rgDestinationLuns* arrays.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| ****S_OK****<br><br>0x00000000L | The operation was successfully completed. |
| ****E_OUTOFMEMORY****<br><br>0x8007000EL | Out of memory or other system resources. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| ****VSS_E_PROVIDER_VETO****<br><br>0x80042306L | An unexpected provider error occurred. The provider must report an event in the application event log providing the user with information on how to resolve the problem. |

## Remarks

In the *rgDestinationLuns* parameter, VSS supplies an empty [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)
structure for each newly created shadow copy LUN. The shadow copy LUNs are not surfaced or visible to the system.
The provider should initialize the members of the
**VDS_LUN_INFORMATION** structure with the appropriate SCSI
Inquiry Data and Vital Product Data page 80 (device serial number) and page 83 (device identity) information. The
structure should contain correct member values such that the shadow copy LUNs can be located by Windows from the
original computer or any other computer connected to the SAN.

The members of the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure correspond to the page 80 information, with the following exceptions:

* The **m_version** member must be set to **VER_VDS_LUN_INFORMATION**.
* The **m_BusType** member is ignored in comparisons during import. This value depends on the PnP storage stack on the corresponding disk device. Usually this is **VDSBusTypeScsi**.
* The **m_diskSignature** member is ignored in comparisons during import. The provider must set this member to GUID_NULL.

The members of the [VDS_STORAGE_DEVICE_ID_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_device_id_descriptor)
structure (in the **m_deviceIdDescriptor** member of the [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)
structure) correspond to the page 83 information. In this structure, each [VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)
structure corresponds to the STORAGE_IDENTIFIER structure for a device identifier (that is, a storage identifier with an association type of zero). For more information about the STORAGE_IDENTIFIER structure, see the Windows Driver Kit (WDK) documentation.

The [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structures returned here
must be the same as the structures provided in
the [IVssHardwareSnapshotProvider::FillInLunInfo](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-fillinluninfo) method during import so
that VSS can use this information to identify the newly arriving shadow copy LUNs at import. These same structures
will be passed to the provider in the
[IVssHardwareSnapshotProvider::LocateLuns](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsshardwaresnapshotprovider-locateluns) method.

## See also

[IVssHardwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsshardwaresnapshotprovider)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)