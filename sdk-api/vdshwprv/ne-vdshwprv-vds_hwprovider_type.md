# VDS_HWPROVIDER_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for a hardware provider. These values are used in the
**type** member of the [VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info)
structure and are returned in the *pType* parameter of the [IVdsHwProviderType::GetProviderType](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovidertype-getprovidertype) method.

## Constants

### `VDS_HWT_UNKNOWN:0`

The type is unknown.

### `VDS_HWT_PCI_RAID:1`

The type indicates a hardware provider for PCI RAID cards.

### `VDS_HWT_FIBRE_CHANNEL:2`

The type indicates a hardware provider for Fibre Channel storage array networks.

### `VDS_HWT_ISCSI:3`

The type indicates a hardware provider for iSCSI storage array networks.

### `VDS_HWT_SAS:4`

The type indicates a hardware provider for serial attached SCSI (SAS) storage array networks.

**Windows Server 2008, Windows Vista and Windows Server 2003 R2:** This value is not supported until Windows Server 2008 R2 and Windows 7.

### `VDS_HWT_HYBRID:5`

The type indicates a hybrid hardware provider. A hybrid provider is a provider that manages subsystems that support multiple interconnect types. This is not a valid value for the
**type** member of the [VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info)
structure.

**Windows Server 2008, Windows Vista and Windows Server 2003 R2:** This value is not supported until Windows Server 2008 R2 and Windows 7.

## Remarks

If your application encounters a **VDS_HWPROVIDER_TYPE** value that it does not recognize, it should display the provider type as unknown. It should not attempt to map the unrecognized provider type to another provider type.

**Note** Additional constants might be added to the **VDS_HWPROVIDER_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_HWPROVIDER_TYPE** enumeration constant.

## See also

[IVdsHwProviderType::GetProviderType](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovidertype-getprovidertype)

[IVdsService::QueryProviders](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-queryproviders)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info)