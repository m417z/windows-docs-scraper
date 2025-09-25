# VDS_PATH_ID structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines a unique
identification for a path.

## Members

### `ullSourceId`

The source ID for the path. If this is an
MPIO path, the source ID is the unique DSM ID.

### `ullPathId`

The ID of the path given by the MPIO DSM.

## See also

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info)