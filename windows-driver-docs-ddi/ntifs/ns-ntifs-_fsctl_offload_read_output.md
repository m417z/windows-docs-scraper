# _FSCTL_OFFLOAD_READ_OUTPUT structure

## Description

The **FSCTL_OFFLOAD_READ_OUTPUT** structure contains the output for the [FSCTL_OFFLOAD_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-read) control code request.

## Members

### `Size`

The size of this structure. Set this member to **sizeof**(FSCTL_OFFLOAD_READ_OUTPUT).

### `Flags`

 Result flags. This value is a bitwise **OR** combination of these values:

| Value | Meaning |
| --- | --- |
| **OFFLOAD_READ_FLAG_FILE_TOO_SMALL**<br><br>0x00000001 | The file to read from is too small for an offload operation. |
| **OFFLOAD_READ_FLAG_ALL_ZERO_BEYOND_CURRENT_RANGE**<br><br>0x00000002 | The range extending beyond the selected range contains all zeros. |
| **OFFLOAD_READ_FLAG_CANNOT_OFFLOAD_BEYOND_CURRENT_RANGE**<br><br>0x00000004 | The offload operation cannot complete beyond the selected range. A non-offloaded read method should be used to complete the operation. |

### `TransferLength`

The length, in bytes, of data represented by **Token**.

### `Token`

A byte array that contains a token structure, [STORAGE_OFFLOAD_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_offload_token), representing a file data within a range specified in [FSCTL_OFFLOAD_READ_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_read_input). The contents of **Token** must remain unmodified between offload operations.

## Remarks

If the [FSCTL_OFFLOAD_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-read) operation is successful, the storage device's copy provider returns, in **FSCTL_OFFLOAD_READ_OUTPUT**, a unique token value identifying the portion of file data read.

The copy provider retains the data read for the duration in the **TokenTimeToLive** member of the [FSCTL_OFFLOAD_READ_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_read_input) structure.

**Token** represents a contiguous region of the file beginning with the requested offset in the **FileOffset** member of [FSCTL_OFFLOAD_READ_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_read_input). The resulting length copied, **TransferLength**, may be smaller than what was originally specified in **CopyLength** member of **FSCTL_OFFLOAD_READ_INPUT**. A smaller value indicates that **Token** was able to logically represent less data than was requested.

 If less data than requested was transferred, the read operation may be completed by performing another [FSCTL_OFFLOAD_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-read) request. The next request uses updated **FileOffset** member in the [FSCTL_OFFLOAD_READ_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_read_input) structure with the value in **TransferLength** and an adjusted read length of the previous length minus the value in **TransferLength**. Also, an incomplete read operation can be completed through a non-offloaded read method, using the [ZwReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntreadfile) routine, for example.

## See also

[FSCTL_OFFLOAD_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-read)

[FSCTL_OFFLOAD_READ_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_read_input)

[STORAGE_OFFLOAD_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_offload_token)