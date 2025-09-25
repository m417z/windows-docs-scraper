# RETRIEVAL_POINTERS_BUFFER structure

## Description

Contains the output for the
[FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers) control code.

## Members

### `ExtentCount`

The count of elements in the **Extents** array.

### `StartingVcn`

The starting VCN returned by the function call. This is not necessarily the VCN requested by the function call, as the file system driver may round down to the first VCN of the extent in which the requested starting VCN is found.

### `NextVcn`

### `Lcn`

### `Extents`

Array of **Extents** structures. For the number of members in the array, see **ExtentCount**. Each member of the array has the following members.

#### NextVcn

The VCN at which the next extent begins. This value minus either **StartingVcn** (for the first **Extents** array member) or the **NextVcn** of the previous member of the array (for all other **Extents** array members) is the length, in clusters, of the current extent. The length is an input to the [FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_move_file) operation.

#### Lcn

The LCN at which the current extent begins on the volume. This value is an input to the [FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_move_file) operation. On the NTFS file system, the value (LONGLONG) –1 indicates either a compression unit that is partially allocated, or an unallocated region of a sparse file.

## See also

[Defragmentation](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files)

[FSCTL_GET_RETRIEVAL_POINTERS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_retrieval_pointers)

[FSCTL_MOVE_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_move_file)