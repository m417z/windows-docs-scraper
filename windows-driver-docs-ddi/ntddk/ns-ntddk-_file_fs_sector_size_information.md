# _FILE_FS_SECTOR_SIZE_INFORMATION structure

## Description

The **FILE_FS_SECTOR_SIZE_INFORMATION** structure is used to query physical and logical sector size information for a file system volume.

## Members

### `LogicalBytesPerSector`

Logical bytes per sector reported by physical storage. This is the same value as the block size for used for Logical Block Addressing (LBA).

### `PhysicalBytesPerSectorForAtomicity`

Actual bytes per sector reported by physical storage used for an atomic write.

### `PhysicalBytesPerSectorForPerformance`

Bytes per sector reported by physical storage for best performance.

### `FileSystemEffectivePhysicalBytesPerSectorForAtomicity`

The portion of **PhysicalBytesPerSectorForAtomicity** considered as the physical sector size by the file system.

### `Flags`

Flags for sector alignment and performance capabilities. This value is a bitwise OR combination of the following:

| Value | Meaning |
| --- | --- |
| **SSINFO_FLAGS_ALIGNED_DEVICE** | Logical sectors of the storage device are aligned to physical sector boundaries. |
| **SSINFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE** | The partition is aligned to physical sector boundaries on the storage device. |
| **SSINFO_FLAGS_NO_SEEK_PENALTY** | The storage device has no seek penalty. |
| **SSINFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE** | The storage device supports the TRIM operation. |

### `ByteOffsetForSectorAlignment`

The offset, in bytes, of the beginning of the first logical sector within the first physical sector. This member is set to **SSINFO_OFFSET_UNKNOWN** if proper device information is not available to calculate the value.

### `ByteOffsetForPartitionAlignment`

The offset value, in bytes, used to align the partition to a physical sector boundary. This member is set to **SSINFO_OFFSET_UNKNOWN** if proper device information is not available to calculate the value.

## Remarks

This information can be queried in either of the following ways:

* Call [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile), passing **FileFsSectorSizeInformation** as the value of *FileInformationClass* and passing a caller-allocated, **FILE_FS_SECTOR_SIZE_INFORMATION**-structured buffer as the value of *FileInformation*.
* Create an IRP with major function code [IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information).
* Call [FsRtlGetSectorSizeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetsectorsizeinformation) with a pointer to a **FILE_FS_SECTOR_SIZE_INFORMATION**-structured buffer. The **FileSystemEffectivePhysicalBytesPerSectorForAtomicity** member will not have a value initialized by the file system when this structure is returned from **FsRtlGetSectorSizeInformation**. A file system driver will typically call this function and then set its own value for **FileSystemEffectivePhysicalBytesPerSectorForAtomicity**.

No specific access rights are required to query this information. Thus this information is available as long as the volume is accessed through an open handle to the volume itself, or to a file or directory on the volume.

The size of the buffer passed in the *FileInformation* parameter to [FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile) must be at least **sizeof** (FILE_FS_SECTOR_SIZE_INFORMATION).

The file system uses the value of **LogicalBytesPerSector** to determine the size of an allocation unit. The **LogicalBytesPerSector** member of this structure is equivalent to the **BytesPerSector** member of the [FILE_FS_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information) and [FILE_FS_FULL_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information) structures.

If the system is unable to determine values for **PhysicalBytesPerSectorForAtomicity** and **PhysicalBytesPerSectorForPerformance** from the storage device, then they are set to the value of **LogicalBytesPerSector.**

## See also

[FILE_FS_FULL_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_full_size_information)

[FILE_FS_SIZE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_file_fs_size_information)

[FltQueryVolumeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[FsRtlGetSectorSizeInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlgetsectorsizeinformation)

[IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[ZwQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryvolumeinformationfile)