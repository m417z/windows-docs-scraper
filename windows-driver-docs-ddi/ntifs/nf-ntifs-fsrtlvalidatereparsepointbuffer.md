# FsRtlValidateReparsePointBuffer function

## Description

The **FsRtlValidateReparsePointBuffer** routine verifies that the specified reparse point buffer is valid.

## Parameters

### `BufferLength` [in]

The length of the reparse point buffer.

### `ReparseBuffer` [in]

The reparse point buffer to be validated.

## Return value

The **FsRtlValidateReparsePointBuffer** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The buffer is valid. |
| **STATUS_IO_REPARSE_DATA_INVALID** | The buffer is not valid, such as if the buffer is too long or the length of the buffer and the data length in its header are not consistent. |
| **STATUS_IO_REPARSE_TAG_INVALID** | The buffer has an invalid reparse tag. |

## Remarks

For more information about reparse points, see [Reparse Points in a File System Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-points-in-a-file-system-filter-driver).

Reparse tags contain several bits that cannot be set except by system components. For more information, see [Reparse Point Tags](https://learn.microsoft.com/windows/win32/fileio/reparse-point-tags).

## See also

[REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[REPARSE_GUID_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_guid_data_buffer)