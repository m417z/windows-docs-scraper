# FsRtlSetKernelEaFile function

## Description

The routine **FsRtlQueryKernelEaFile** is used to set, modify and/or delete extended attribute (EA) values for a file and synchronously wait
for it to complete, returning a result. It sets the **IRP_MN_KERNEL** minor
code which allows this API to set SecureEAs. This allows the caller to do
this by FileObject instead of a handle.

## Parameters

### `FileObject` [in]

A pointer to a **FileObject** to send the QueryEA request to.

### `EaBuffer` [in]

A pointer to a caller-supplied, [FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)-structured input buffer that contains the extended attribute values to be set

### `Length` [in]

Specifies the length of the EA buffer.

## Return value

The routine **FsRtlSetKernelEaFile** receives the status of the operation and returns one of the status codes:

| Return code | Description |
| --- | --- |
| **STATUS_EA_LIST_INCONSISTENT** | The **EaList** parameter is not formatted correctly. |
| **STATUS_EAS_NOT_SUPPORTED** | The file system does not support extended attributes. |
| **STATUS_INSUFFICIENT_RESOURCES** | The I/O request packet (IRP) could not be allocated for this request. |
| **STATUS_INTERMIXED_KERNEL_EA_OPERATION** | The request cannot intermix normal and kernel EA’s in the same call. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request failed as it was a direct device open. |
| **STATUS_SUCCESS** | The request was successful. |

## Remarks

 This routine assumes all passed in buffers are from kernel mode.

One or more Kernel EA’s may be set, modified and/or deleted in a single call to **FsRtlSetKernelEaFile**. Normal EA’s may also be set using the **FsRtlSetKernelEaFile** function.
You delete EA’s by specifying an **EAName** with an **EaValueLength** of zero. You can intermix inserting new, modifying existing, or removing EA’s in a single call.

## See also

[FsRtlQueryKernelEaFile](https://learn.microsoft.com/previous-versions/mt807492(v=vs.85))

[ZwQueryEaFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryeafile)

[ZwSetEaFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwseteafile)