# VDS_INTERCONNECT_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of interconnect types that subsystems can support.

## Constants

### `VDS_ITF_PCI_RAID:0x1`

The subsystem supports a PCI RAID interconnect.

### `VDS_ITF_FIBRE_CHANNEL:0x2`

The subsystem supports a Fibre Channel interconnect.

### `VDS_ITF_ISCSI:0x4`

The subsystem supports an iSCSI interconnect.

### `VDS_ITF_SAS:0x8`

The subsystem supports a serial attached iSCSI (SAS) interconnect.

## Remarks

**Note** Additional constants might be added to the **VDS_INTERCONNECT_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_INTERCONNECT_FLAG** enumeration constant.

## See also

[IVdsSubSystemInterconnect::GetSupportedInterconnects](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsysteminterconnect-getsupportedinterconnects)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_HWPROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hwprovider_type)