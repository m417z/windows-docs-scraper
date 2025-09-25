# VDS_ISCSI_PORTAL_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of an iSCSI portal.

## Members

### `id`

The **VDS_OBJECT_ID** of the portal.

### `address`

The IP address and port of the portal.

### `status`

The status of the portal, enumerated by
[VDS_ISCSI_PORTAL_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_portal_status).

## See also

[IVdsIscsiPortal::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportal-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_IPADDRESS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_ipaddress)

[VDS_ISCSI_PORTAL_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_portal_status)