# NVME_CDW10_ABORT structure

## Description

Contains parameters for the Abort command that is used to abort a specific command previously submitted to the Admin Submission Queue or an I/O Submission Queue.

The **NVME_CDW10_ABORT** structure is used in the **CDW10** field of the **ABORT** parameter in the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure. All other command specific fields in the **ABORT** structure are reserved.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.SQID`

The Submission Queue Identifier (SQID) field specifies the identifier of the Submission Queue associated with the command to be aborted.

### `DUMMYSTRUCTNAME.CID`

The Command Identifier (CID) field specifies the command identifier of the command to be aborted, that was specified in the **CID** field of the [NVME_COMMAND_DWORD0](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0) structure within the **CDW0** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) itself.

### `AsUlong`

## Remarks

Host software may have multiple Abort commands outstanding, subject to the constraints of the Abort Command Limit indicated in the **ACL** field of the [Identify Controller data structure](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data).

An Abort command is a best effort command; the command to abort may have already completed, currently be in execution, or may be deeply queued. If or when a controller chooses to complete the command when the command to abort is not found, is implementation specific.

## See also

- [NVME_COMMAND_DWORD0](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0) structure
- [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command)