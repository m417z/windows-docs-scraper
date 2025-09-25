# FSCTL_OFFLOAD_WRITE_OUTPUT structure

## Description

The **FSCTL_OFFLOAD_WRITE_OUTPUT** structure contains the output for the [**FSCTL_OFFLOAD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-write) control code request.

## Members

### `Size`

The size in bytes of this structure. Set this member to ```sizeof(FSCTL_OFFLOAD_WRITE_OUTPUT)```.

### `Flags`

Result flags for the offload write operation. This value is either 0 or the following:

| Value | Meaning |
| ----- | ------- |
| OFFLOAD_READ_FLAG_FILE_TOO_SMALL | The file to write to is too small for an offload operation. |

### `LengthWritten`

The length of data written for the transfer specified in [**FSCTL_OFFLOAD_WRITE_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_write_input).

## Remarks

 The resulting length written, **LengthWritten**, may be smaller than what was originally specified in the **CopyLength** member of [**FSCTL_OFFLOAD_WRITE_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_write_input). A smaller value indicates that less data was able to be logically written with the specified **Token** than was requested.

 If less data than requested was written, the write operation may be completed by performing another [**FSCTL_OFFLOAD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-write) request. The next request uses an updated **FileOffset** member in the [**FSCTL_OFFLOAD_WRITE_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_write_input) structure with the value in **LengthWritten** and an adjusted write length of the previous length minus the value in **LengthWritten**. An incomplete write operation can also be completed through a non-offloaded write method, such as using the [**ZwWriteFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile) routine, for example.

## See also

[**FSCTL_OFFLOAD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-write)

[**FSCTL_OFFLOAD_WRITE_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_write_input)