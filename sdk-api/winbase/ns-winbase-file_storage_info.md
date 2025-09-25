# FILE_STORAGE_INFO structure

## Description

Contains directory information for a file. This structure is returned from the
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex) function when
**FileStorageInfo** is passed in the *FileInformationClass*
parameter.

## Members

### `LogicalBytesPerSector`

Logical bytes per sector reported by physical storage. This is the smallest size for which uncached I/O is
supported.

### `PhysicalBytesPerSectorForAtomicity`

Bytes per sector for atomic writes. Writes smaller than this may require a read before the entire block can
be written atomically.

### `PhysicalBytesPerSectorForPerformance`

Bytes per sector for optimal performance for writes.

### `FileSystemEffectivePhysicalBytesPerSectorForAtomicity`

This is the size of the block used for atomicity by the file system. This may be a trade-off between the
optimal size of the physical media and one that is easier to adapt existing code and structures.

### `Flags`

This member can contain combinations of flags specifying information about the alignment of the
storage.

| Value | Meaning |
| --- | --- |
| **STORAGE_INFO_FLAGS_ALIGNED_DEVICE**<br><br>0x00000001 | When set, this flag indicates that the logical sectors of the storage device are aligned to physical sector boundaries. |
| **STORAGE_INFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE**<br><br>0x00000002 | When set, this flag indicates that the partition is aligned to physical sector boundaries on the storage device. |

### `ByteOffsetForSectorAlignment`

Logical sector offset within the first physical sector where the first logical sector is placed, in bytes.
If this value is set to **STORAGE_INFO_OFFSET_UNKNOWN** (0xffffffff), there was
insufficient information to compute this field.

### `ByteOffsetForPartitionAlignment`

Offset used to align the partition to a physical sector boundary on the storage device, in bytes. If this
value is set to **STORAGE_INFO_OFFSET_UNKNOWN** (0xffffffff), there was insufficient
information to compute this field.

## Remarks

If a volume is built on top of storage devices with different properties (for example a mirrored, spanned,
striped, or RAID configuration) the sizes returned are those of the largest size of any of the underlying storage
devices.

## See also

[FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class)

[File Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/file-management-structures)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)