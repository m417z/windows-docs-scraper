# VDS_ISCSI_PORTAL_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid status values for an iSCSI portal.

## Constants

### `VDS_IPS_UNKNOWN:0`

The status is unknown.

### `VDS_IPS_ONLINE:1`

The portal is available.

### `VDS_IPS_NOT_READY:2`

The portal is busy.

### `VDS_IPS_OFFLINE:4`

The portal is unavailable.

### `VDS_IPS_FAILED:5`

The portal has failed.

## Remarks

**Note** Additional constants might be added to the **VDS_ISCSI_PORTAL_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_ISCSI_PORTAL_STATUS** enumeration constant.

## See also

[IVdsIscsiPortal::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportal-setstatus)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_ISCSI_PORTAL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_portal_prop)