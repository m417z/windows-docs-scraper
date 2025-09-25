# VDS_POOL_CUSTOM_ATTRIBUTES structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines a custom attribute of a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object). This structure is used in the [pPoolCustomAttributes](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes) member of the **VDS_POOL_ATTRIBUTES** structure.

## Members

### `pwszName`

A string containing the name of the custom attribute.

### `pwszValue`

A string containing the value of the custom attribute.

## Remarks

A custom attribute can be used to indicate, for example, the RAID types that can be created in the storage pool in cases such as the following:

* The storage pool supports the creation of LUNs without any RAID type.
* The storage pool supports more than one RAID type. This can happen if the storage pool spans more than one subsystem.

## See also

[VDS_POOL_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes)