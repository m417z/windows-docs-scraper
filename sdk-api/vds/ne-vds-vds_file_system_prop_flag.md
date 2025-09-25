# VDS_FILE_SYSTEM_PROP_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of file-system compression.

## Constants

### `VDS_FPF_COMPRESSED:0x1`

If set, the file system supports file compression.

## Remarks

This enumeration provides the values for the *ulFlags* member of the [VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop) structure.

**Note** Additional constants might be added to the **VDS_FILE_SYSTEM_PROP_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_FILE_SYSTEM_PROP_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_FILE_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_file_system_prop)