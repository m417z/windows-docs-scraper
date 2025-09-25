# REPAIR_COPIES_INPUT structure

## Description

Input structure for the [FSCTL_REPAIR_COPIES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_repair_copies) control code. It describes a single block of data and indicates which of the copies is to be copied to the specified copies of the data. The

## Members

### `Size`

Set to `sizeof(REPAIR_COPIES_INPUT)`.

### `Flags`

Reserved (must be zero)

### `FileOffset`

The file position to start the repair operation.

### `Length`

The number of bytes to be repaired.

### `SourceCopy`

The zero-based copy number of the source copy.

### `NumberOfRepairCopies`

The number of copies that will be repaired. This is the size of the **RepairCopies**
array.

### `RepairCopies`

The zero-based copy numbers of the copies that will be repaired.

## See also

[FSCTL_REPAIR_COPIES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_repair_copies)

[REPAIR_COPIES_OUTPUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-repair_copies_output)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)