# IVdsCreatePartitionEx::CreatePartitionEx

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a partition on a basic disk.

This method supersedes the
[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition)
method.

## Parameters

### `ullOffset` [in]

The partition offset, in bytes. If the offset is not aligned and the *ulAlign* parameter is not specified, the offset is rounded up or down to the closest alignment boundary depending on the size of the disk on which the partition is created. For more information, see the following Remarks section.

**Windows Server 2003:** Only the first partition on a basic disk can be aligned; dynamic disks cannot be aligned. For other partitions on a basic disk, you cannot specify alignment using the *ulAlign* parameter; the offset is rounded to the nearest cylinder boundary for Master Boot Record (MBR) disks, or the nearest sector boundary for GUID Partition Table (GPT) disks.

When the caller specifies both the *ullOffset* and
*ulAlign* parameters, the offset must be within the first cylinder.

### `ullSize` [in]

The size, in bytes, of the new partition.

### `ulAlign` [in]

The alignment size, in bytes.

**Windows Server 2003:** If this parameter is specified, the provider rounds up the partition offset to the closest alignment boundary; otherwise, to
the closest cylinder boundary.

If the beginning of a disk has sufficient space to accommodate the partition
size, and the *ulAlign* parameter is specified but the
*ullOffset* parameter is not, the call to **CreatePartitionEx** fails.

### `para` [in]

The pointer to parameters defined by the
[CREATE_PARTITION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-create_partition_parameters)
structure.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer, which
VDS initializes on return. Callers must release the interface. Use this pointer to cancel, wait for, or query
the status of the operation.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The partition was created successfully. |
| **VDS_E_NO_MEDIA**<br><br>0x80042412L | There is no media in a removable drive. |
| **VDS_E_DISK_IS_READ_ONLY**<br><br>0x8004280BL | The partition could not be created, because the disk is read-only. |
| **VDS_E_INVALID_OPERATION**<br><br>0x80042415L | The media does not support this operation. For example, the caller cannot create a partition on a CD-ROM. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | Creating a second partition on removable media is not supported. Alternatively, this error indicates the disk is a dynamic disk. |
| **VDS_E_PARTITION_LIMIT_REACHED**<br><br>0x80042407L | The maximum number of partitions (primary partitions or primary partitions with an extended partition) already exists when the caller tries to create an additional primary partition or extended partition. |
| **VDS_S_UPDATE_BOOTFILE_FAILED**<br><br>0x00042434L | The partition was created successfully, but VDS failed to update the boot options in the Boot Configuration Data (BCD) store.<br><br>**Windows Server 2003:** Boot options are stored in the boot.ini file on an x86 or x64 system or NVRAM on an Itanium system. |

## Remarks

This method operates on basic disks having either a GPT or MBR
partition scheme.

**Windows Server 2003:** Callers can align only the first partition of a MBR disk and must place the starting offset in
the first cylinder or the beginning of the second cylinder, at the cylinder boundary.

If the *ullOffset* parameter is specified and its value is not already aligned using the values under the **HKEY_LOCAL_MACHINE**\**System**\**CurrentControlSet**\**Services**\**Vds**\**Alignment** registry subkey, its value will be aligned automatically using the following values: The default alignment is 1 MB if the disk is 4 GB or larger, or 64 KB if the disk is smaller than 4 GB.

**Windows Server 2003:** Unaligned partition offsets are rounded to the nearest cylinder boundary for MBR disks, or to the nearest sector boundary for GPT disks.

If a dynamic disk is read-only and offline, it must be made read/write and brought online as follows before calling **CreatePartitionEx**:

1. Clear the read-only bit. (This is the **VDS_DF_READ_ONLY** flag in the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) structure.)
2. Call the [IVdsDiskOnline::Online](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdiskonline-online) method.

## See also

[IVdsAdvancedDisk::CreatePartition](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsadvanceddisk-createpartition)

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsCreatePartitionEx](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdscreatepartitionex)