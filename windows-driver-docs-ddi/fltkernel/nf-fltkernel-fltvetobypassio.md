## Description

**FltVetoBypassIo** retrieves information needed to veto a BypassIO request.

## Parameters

### `CallbackData` [in]

Pointer to the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) for [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io).

### `FltObjects` [in]

Pointer to the [**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure for the BypassIO operation.

### `OperationStatus` [in]

The NTSTATUS error code provided by the filter for the veto.

### `FailureReason` [in]

A unique, descriptive string that provides details about why the filter is vetoing the BypassIO enable request.

## Return value

**FltVetoBypassIo** returns STATUS_SUCCESS upon successful completion; otherwise, it returns an NTSTATUS value such as one of the following.

| Value | Meaning |
| ----- | ------- |
| STATUS_BUFFER_TOO_SMALL | The FSCTL's [output buffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output) is too small. |
| STATUS_INVALID_BUFFER_SIZE | The FSCTL's [input buffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input) is too small. |
| STATUS_INVALID_PARAMETER_3 | An appropriate error code was not provided. |
| STATUS_INVALID_PARAMETER_4 | An appropriate failure reason was not provided. |
| STATUS_NOT_SUPPORTED | The requested operation isn't supported or wasn't requested from a pre-op callback. |

## Remarks

A minifilter calls **FltVetoBypassIo** when it intends to veto a [FS_BPIO_OP_ENABLE or FS_BPIO_OP_QUERY request](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations) on a file. A minifilter should only call this routine from its pre-operation callback.

**FltVetoBypassIo** fills in the caller-allocated [**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output) structure associated with **CallbackData** with the information needed to veto the BypassIO request. The caller must provide a buffer that is large enough to hold the structure.

**FltVetoBypassIo** logs an ETW event with the status, filter-provided reason, and filter's name.

See [BypassIO for filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio) and [Supporting BypassIO operations](https://learn.microsoft.com/windows-hardware/drivers/ifs/bypassio-operations) for more information.

## See also

[**FS_BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_input)

[**FS_BPIO_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ne-ntifs-fs_bpio_operations)

[**FS_BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-fs_bpio_output)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)