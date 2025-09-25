# VDS_ISCSI_PORTALGROUP_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of an iSCSI portal group.

## Members

### `id`

The [VDS_OBJECT_ID](https://learn.microsoft.com/windows/desktop/VDS/vds-data-types) assigned to the portal group.

### `tag`

The portal group tag that is assigned by the provider to the portal group. For more information about portal group tags, see the iSCSI specification at [https://go.microsoft.com/fwlink/p/?linkid=158752](https://www.ietf.org/rfc/rfc3720.txt).

## See also

[IVdsIscsiPortalGroup::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportalgroup-getproperties)