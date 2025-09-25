# VDS_ISCSI_INITIATOR_PORTAL_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of an iSCSI initiator portal.

## Members

### `id`

The **VDS_OBJECT_ID** assigned to the initiator portal.

### `address`

The IP address and port of the portal.

### `ulPortIndex`

The port index assigned to the portal by the iSCSI initiator service.

## See also

[IVdsIscsiInitiatorPortal::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsiscsiinitiatorportal-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_IPADDRESS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_ipaddress)