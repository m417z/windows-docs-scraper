# VDS_ISCSI_TARGET_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of an iSCSI target.

## Members

### `id`

The **VDS_OBJECT_ID** of the target.

### `pwszIscsiName`

A null-terminated, human-readable string that is the iSCSI name of the target.

### `pwszFriendlyName`

A null-terminated, human-readable string that is the friendly name of the target. This corresponds to the
iSCSI alias.

### `bChapEnabled`

If **TRUE**, a CHAP shared secret is required to login to this target.

## See also

[IVdsIscsiTarget::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsitarget-getproperties)