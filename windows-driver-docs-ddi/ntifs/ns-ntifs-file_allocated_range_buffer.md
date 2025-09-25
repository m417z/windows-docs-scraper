## Description

**FILE_ALLOCATED_RANGE_BUFFER** structures are used as input and output during a [**FSCTL_QUERY_ALLOCATED_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_allocated_ranges) control code request.

## Members

### `FileOffset`

On FSCTL input, contains the file offset in bytes of the start of a range of bytes in a file. **FileOffset** must be greater than or equal to 0.

On FSCTL output, contains the file offset in bytes from the start of the file; the start of a range of bytes to which storage is allocated. If the file is a sparse file, **FileOffset** can contain ranges of bytes for which storage is not allocated; these ranges will be excluded from the list of allocated ranges returned by [**FSCTL_QUERY_ALLOCATED_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_allocated_ranges). Because an application using a sparse file can choose whether or not to allocate disk space for each sequence of 0x00-valued bytes, the allocated ranges can contain 0x00-valued bytes. This value must be greater than or equal to 0 on output.

### `Length`

Contains the size in bytes of the range. On FSCTL input, **Length** must be greater than or equal to 0. On FSCTL output, **Length** must be greater than 0.

## See also

 [**FSCTL_QUERY_ALLOCATED_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_query_allocated_ranges)