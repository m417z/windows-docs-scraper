# IVdsDiskPartitionMF2::FormatPartitionEx2

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Formats an existing OEM, ESP, or unknown partition. This method is identical to the [IVdsDiskPartitionMF::FormatPartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-formatpartition) method, except that formatting options are specified by using the *Options* parameter.

## Parameters

### `ullOffset` [in]

The byte offset of the partition from the beginning of the disk. This offset must be the offset of the start of a partition.

### `pwszFileSystemTypeName` [in]

A **NULL**-terminated Unicode string containing the name of the file system with which to format the partition. Must be **NULL** or one of the following: "NTFS", "FAT","FAT32", "UDF", or "EXFAT". If this parameter is **NULL**, a default value is used. For more information, see [VDS_FILE_SYSTEM_FORMAT_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_format_support_flag).

### `usFileSystemRevision` [in]

The revision of the file system, if any. This member is expressed as a 16-bit binary-coded decimal number, where a decimal point is implied between the second and third digits. For example, a value of 0x0250 indicates revision 2.50.

### `ulDesiredUnitAllocationSize` [in]

The size of the allocation unit for the file system, in bytes. The value must be a power of 2. If the value is 0, a default allocation unit determined by the file system type will be used. The allocation unit range is file system dependent.

### `pwszLabel` [in]

A **NULL**-terminated Unicode string containing the label to assign to the new file system for the partition. The maximum label size is file system dependent.

### `Options` [in]

A bitmask of [VDS_FORMAT_OPTION_FLAGS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_format_option_flags) enumeration values that specify formatting options.

### `ppAsync` [out]

A pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they are done with it.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The volume was partitioned successfully. |
| **VDS_E_BAD_PROVIDER_DATA**<br><br>0x80042441L | A provider returned bad data. |
| **VDS_E_DISK_REMOVEABLE**<br><br>0x8004255AL | The operation is not supported on removable media. |
| **VDS_E_FS_NOT_DETERMINED**<br><br>0x80042593L | The default file system could not be determined. |
| **VDS_E_MISSING_DISK**<br><br>0x80042454L | The disk is missing. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The partition does not exist. |
| **VDS_E_PARTITION_NOT_OEM**<br><br>0x8004256FL | The operation is not supported on non-OEM partitions. |

In addition, the [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface can return the
following related warnings and error codes.

| Return code/value | Description |
| --- | --- |
| **VDS_S_VOLUME_COMPRESS_FAILED**<br><br>0x00042443L | The file system is formatted but not compressed. |
| **VDS_E_ACCESS_DENIED**<br><br>0x80042427L | Access is denied. |
| **VDS_E_BAD_LABEL**<br><br>0x80042429L | The label is not valid. |
| **VDS_E_CANT_QUICK_FORMAT**<br><br>0x8004242AL | The volume cannot be quick-formatted. |
| **VDS_E_CLUSTER_COUNT_BEYOND_32BITS**<br><br>0x80042430L | The number of clusters is too large to be represented as a 32-bit integer. |
| **VDS_E_CLUSTER_SIZE_TOO_BIG**<br><br>0x8004242FL | The cluster size is too large to allow formatting. |
| **VDS_E_CLUSTER_SIZE_TOO_SMALL**<br><br>0x8004242EL | The cluster size is too small to allow formatting. |
| **VDS_E_INCOMPATIBLE_FILE_SYSTEM**<br><br>0x80042425L | The file system is incompatible. |
| **VDS_E_INCOMPATIBLE_MEDIA**<br><br>0x80042426L | The media is incompatible. |
| **VDS_E_IO_ERROR**<br><br>0x8004242BL | An I/O error occurred during format. |
| **VDS_E_MEDIA_WRITE_PROTECTED**<br><br>0x80042428L | The media is write-protected. |
| **VDS_E_VOLUME_TOO_BIG**<br><br>0x8004242DL | The volume size is too large to format. |
| **VDS_E_VOLUME_TOO_SMALL**<br><br>0x8004242CL | The volume size is too small to format. |

## See also

[IVdsDiskPartitionMF2](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdiskpartitionmf2)

[VDS_FILE_SYSTEM_FORMAT_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_file_system_format_support_flag)

[VDS_FORMAT_OPTION_FLAGS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_format_option_flags)