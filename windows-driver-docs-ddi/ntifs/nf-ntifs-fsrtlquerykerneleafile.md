# FsRtlQueryKernelEaFile function

## Description

The routine **FsRtlQueryKernelEaFile** is used to build an explicit QueryEA request and synchronously wait
for it to complete, returning the result. This allows the caller to do
this by FileObject instead of a handle.

## Parameters

### `FileObject` [in]

A pointer to a **FileObject** to send the QueryEA request to.

### `ReturnedEaData` [out]

A pointer to a caller-supplied [FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)-structured output buffer, where the extended attribute values are to be returned.

### `Length` [in]

Specifies the length, in bytes, of **ReturnedEaData**

### `ReturnSingleEntry` [in]

Specifies whether only a single entry should be returned
rather than filling the buffer with as many EAs as possible.

### `EaList` [in]

A pointer to a caller-supplied [FILE_GET_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_ea_information)-structured input buffer, which specifies the extended attributes to be queried. This parameter is optional and can be **NULL**.

### `EaListLength` [in]

Specifies the length of **EaList**, if an EA list was
supplied.

### `EaIndex` [in, optional]

Supplies the optional index of an EA whose value is to be
returned. If specified, then only that EA is returned.

### `RestartScan` [in]

Specifies whether the scan of the EAs should be restarted
from the beginning.

### `LengthReturned` [out, optional]

Specifies the amount of valid data that is returned in the
**ReturnedEaData** buffer.

## Return value

The routine **FsRtlQueryKernelEaFile** returns one of the status codes:

| Return code | Description |
| --- | --- |
| **STATUS_EAS_NOT_SUPPORTED** | The file system does not support extended attributes. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request failed as it was a direct device open. |
| **STATUS_INSUFFICIENT_RESOURCES** | The I/O request packet (IRP) could not be allocated for this request. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

This routine **FsRtlQueryKernelEaFile** assumes all passed in buffers are from kernel mode as it requires that the given Input and Output buffers if specified, be kernel mode addresses. The operation will fail if a user mode address is specified.

## See also

[FsRtlSetKernelEaFile](https://learn.microsoft.com/previous-versions/mt807493(v=vs.85))

[ZwQueryEaFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryeafile)

[ZwSetEaFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwseteafile)