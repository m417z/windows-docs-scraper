# NVME_FUSED_OPERATION_CODES enumeration

## Description

Contains values that indicate whether a command is the first or second command in a fused operation.

## Constants

### `NVME_FUSED_OPERATION_NORMAL`

A normal operation without fusing commands.

### `NVME_FUSED_OPERATION_FIRST_CMD`

The first command in a fused operation.

### `NVME_FUSED_OPERATION_SECOND_CMD`

The second command in a fused operation.

## Remarks

Use this enumeration to specify values in the **FUSE** field of the [NVME_COMMAND_DWORD0](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0) structure to indicate whether a command is part of a fused operation.

## See also

[NVME_COMMAND_DWORD0](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_dword0)