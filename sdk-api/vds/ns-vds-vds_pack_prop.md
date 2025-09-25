# VDS_PACK_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a pack object.

## Members

### `id`

The GUID of the pack object.

### `pwszName`

A string representing the pack name. Packs managed by the basic provider have no name.

### `status`

The pack status enumerated by [VDS_PACK_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_pack_status).

### `ulFlags`

The pack flags enumerated by [VDS_PACK_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_pack_flag).

## Remarks

The [IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties) method returns this structure to report the property details of a pack object.

## See also

[IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_PACK_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_pack_flag)

[VDS_PACK_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_pack_status)