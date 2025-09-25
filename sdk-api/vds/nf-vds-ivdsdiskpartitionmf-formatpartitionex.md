# IVdsDiskPartitionMF::FormatPartitionEx

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Formats an existing OEM, ESP, or unknown partition.

## Parameters

### `ullOffset` [in]

Byte offset of the partition from the beginning of the disk. This offset must be the offset of the start of a partition.

### `pwszFileSystemTypeName` [in]

A **NULL**-terminated Unicode string containing the name of the file system with which to format the partition. Must be **NULL** or one of the following: "NTFS", "FAT","FAT32", "UDF", or "EXFAT". If this parameter is **NULL**, a default value is used.

### `usFileSystemRevision` [in]

The revision of the file system, if any. This member is expressed as a 16-bit binary-coded decimal number, where a decimal point is implied between the second and third digits. For example, a value of 0x0250 indicates revision 2.50.

### `ulDesiredUnitAllocationSize` [in]

The size of the allocation unit for the file system, in bytes. The value must be a power of 2. If the value is 0, a default allocation unit determined by the file system type will be used. The allocation unit range is file system dependent.

### `pwszLabel` [in]

**Null**-terminated Unicode string to assign to the new file system for the volume. The maximum label size is file system dependent.

### `bForce` [in]

Boolean that determines whether a file system format is forced, regardless of whether the partition is in use.

### `bQuickFormat` [in]

Boolean that determines whether a file system volume is quick-formatted. A quick format does not verify each sector on the volume.

### `bEnableCompression` [in]

Boolean that determines whether a file system will be created with compression enabled.

**Note** This parameter is ignored if the file system is not NTFS.

### `ppAsync` [out]

Pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they are done with it.

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

## Remarks

This method formats only OEM, ESP, and unknown partitions. For other partitions, you must instead format the corresponding volume by using the [IVdsVolumeMF::Format](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-format) or [IVdsVolumeMF2::FormatEx](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf2-formatex) method. Note that OEM, ESP, and unknown partitions are not exposed as volumes and therefore cannot be formatted with **Format** or **FormatEx**.

This method cannot be used to format removable media.

If an OEM partition is formatted as FAT or FAT32, the partition type does not change. If it is formatted with NTFS, the partition type changes to PARTITION_IFS (0x07). For information about partition types, see [CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters).

For more information about file system limits such as minimum and maximum allocation unit size (also called cluster size), see [NTFS Technical Reference](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc758691(v=ws.10)) and [FAT Technical Reference](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc758586(v=ws.10)).

## See also

[IVdsAdvancedDisk::FormatPartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-formatpartition)

[IVdsDiskPartitionMF](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdiskpartitionmf)