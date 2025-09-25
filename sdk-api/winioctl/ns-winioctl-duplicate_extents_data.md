# DUPLICATE_EXTENTS_DATA structure

## Description

Contains parameters for the [FSCTL_DUPLICATE_EXTENTS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_duplicate_extents_to_file) control code that performs the [Block Cloning](https://learn.microsoft.com/windows/desktop/FileIO/block-cloning) operation.

## Members

### `FileHandle`

A handle to the source file from which the byte range is to be copied.
To retrieve a file handle, use the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `SourceFileOffset`

The offset, in bytes, to the beginning of the range to copy from the source file.

### `TargetFileOffset`

The offset, in bytes, to place the copied byte range in the destination file.

### `ByteCount`

The length, in bytes, of the range to copy.

## See also

[Block Cloning](https://learn.microsoft.com/windows/desktop/FileIO/block-cloning)

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_DUPLICATE_EXTENTS_TO_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_duplicate_extents_to_file)

[File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)