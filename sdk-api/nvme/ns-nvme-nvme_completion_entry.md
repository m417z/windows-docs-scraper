# NVME_COMPLETION_ENTRY structure

## Description

Specifies an entry in the Completion Queue that is 16 bytes in size.

## Members

### `DW0`

The contents of Dword 0 contain command specific information.

If a command uses Dword 0, then the definition of this Dword is contained within the associated command definition. If a command does not use Dword 0, then this field is reserved.

### `Reserved`

The contents of Dword 1 which are reserved.

### `DW2`

A union that contains the information in Dword 2.

### `DW2.DUMMYSTRUCTNAME`

### `DW2.DUMMYSTRUCTNAME.SQHD`

Indicates the current Submission Queue Head pointer for the Submission Queue indicated in the SQ Identifier (**SQID**) field. This is used to indicate to the host the Submission Queue entries that have been consumed and may be re-used for new entries.

> [!NOTE]
> The value returned is the value of the Submission Queue Head pointer when the completion queue entry was created. By the time host software consumes the completion queue entry, the controller may have an SQ Head pointer that has advanced beyond the value indicated.

### `DW2.DUMMYSTRUCTNAME.SQID`

Specifies the Submission Queue to which the associated command was issued to. The **SQID** field is used in combination with the Command Identifier (**CID**) by the host software to uniquely determine the completed command when more than one Submission Queue shares a single Completion Queue.

### `DW2.AsUlong`

### `DW3`

A union that contains the information in Dword 3.

### `DW3.DUMMYSTRUCTNAME`

### `DW3.DUMMYSTRUCTNAME.CID`

Indicates the identifier of the command that is being completed.

This identifier is assigned by host software when the command is submitted to the Submission Queue. The combination of the SQ Identifier **SQID** and Command Identifier **CID** uniquely identifies the command that is being completed. The maximum number of requests outstanding at one time is 64K.

### `DW3.DUMMYSTRUCTNAME.Status`

A [NVME_COMMAND_STATUS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_status) structure that indicates the status for the command that is being completed.

A value of `0h` for this Field indicates a successful command completion with no fatal or non-fatal error conditions. Unless otherwise noted, if a command fails to complete successfully for multiple reasons, then the particular status code returned is chosen by the vendor.

### `DW3.AsUlong`

## Remarks

## See also