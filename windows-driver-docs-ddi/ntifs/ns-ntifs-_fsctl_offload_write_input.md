# FSCTL_OFFLOAD_WRITE_INPUT structure

## Description

The **FSCTL_OFFLOAD_WRITE_INPUT** structure contains the input for the [**FSCTL_OFFLOAD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-write) control code request.

## Members

### `Size`

The size of this structure. Set this member to ```sizeof(FSCTL_OFFLOAD_WRITE_INPUT)```.

### `Flags`

 This member is not used. Set to 0.

### `FileOffset`

 The position in the file to begin writing to. The offset value must be aligned to a logical sector boundary on the volume.

### `CopyLength`

 The length, in bytes, of data to write, starting at **FileOffset**. The length value must align to a logical sector boundary on the volume, except when the length matches end-of-file.

### `TransferOffset`

 The position in the data associated with **Token** to begin writing from.

### `Token`

A byte array that contains a [**STORAGE_OFFLOAD_TOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_offload_token) token structure that represents a file data range to be logically written. The contents of **Token** must remain unmodified between offload operations.

## Remarks

**CopyLength** can be zero. The value of **FileOffset** + **CopyLength** is bounded by both **MAXULONGLONG** and **MAXFILESIZE**. [**FSCTL_OFFLOAD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-write) returns with **STATUS_INVALID_PARAMETER** if these conditions are not met.

## See also

[**FSCTL_OFFLOAD_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-read)

[**FSCTL_OFFLOAD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-write)

[**FSCTL_OFFLOAD_WRITE_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_write_output)

[**STORAGE_OFFLOAD_TOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_offload_token)