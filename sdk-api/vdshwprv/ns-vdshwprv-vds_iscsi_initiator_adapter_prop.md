# VDS_ISCSI_INITIATOR_ADAPTER_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of an iSCSI initiator adapter.

## Members

### `id`

The **VDS_OBJECT_ID** assigned to the initiator adapter.

### `pwszName`

A null-terminated, human-readable string that is the name of the initiator adapter.

## See also

[IVdsIscsiInitiatorAdapter::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsiscsiinitiatoradapter-getproperties)