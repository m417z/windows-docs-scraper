# __VDS_PARTITION_STYLE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

This enumeration is
not for explicit use.

## Constants

### `VDS_PARTITION_STYLE_MBR:0`

This value is not intended for use.

### `VDS_PARTITION_STYLE_GPT`

This value is not intended for use.

### `VDS_PARTITION_STYLE_RAW`

This value is not intended for use.

## Remarks

**Note** Additional constants might be added to the **tag_VDS_PARTITION_STYLE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **tag_VDS_PARTITION_STYLE** enumeration constant.

## See also

[VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style)