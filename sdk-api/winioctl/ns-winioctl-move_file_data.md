# MOVE_FILE_DATA structure

## Description

Contains input data for the [FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_move_file)
control code.

## Members

### `FileHandle`

A handle to the file to be moved.

To retrieve a handle to a file, use
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

If the file is encrypted, the handle must have the **FILE_READ_DATA**,
**FILE_WRITE_DATA**, **FILE_APPEND_DATA**, or
**FILE_EXECUTE** access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

### `StartingVcn`

A VCN (cluster number relative to the beginning of a file) of the first cluster to be moved.

### `StartingLcn`

An LCN (cluster number on a volume) to which the VCN is to be moved.

### `ClusterCount`

The count of clusters to be moved.

## Remarks

To retrieve data to fill in this structure, use the
[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the
[FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers) control
code.

The first cluster of a directory on a FAT file system volume cannot be moved.

When possible, move data in blocks aligned relative to each other in 16-kilobyte (KB) increments. This reduces copy-on-write overhead when shadow copies are enabled, because shadow copy space is increased and performance is reduced when the following conditions occur:

* The move request block size is less than or equal to 16 KB.
* The move delta is not in increments of 16 KB.

The move delta is the number of bytes between the start of the source block and the start of the target block. In other words, a block starting at offset X (on-disk) can be moved to a starting offset Y if the absolute value of X minus Y is an even multiple of 16 KB. So, assuming 4-KB clusters, a move from cluster 3 to cluster 27 will be optimized, but a move from cluster 18 to cluster 24 will not. Note that mod(3,4) = 3 = mod(27,4). Mod 4 is chosen because four clusters at 4 KB each is equivalent to 16 KB. Therefore, a volume formatted to a 16-KB cluster size will result in all move files being optimized.

For more information about shadow copies, see [Volume Shadow Copy Service](https://learn.microsoft.com/windows/desktop/VSS/about-the-volume-shadow-copy-service).

## See also

[Defragmenting Files](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files)

[FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers)

[FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_move_file)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)

[GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa)

[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle)