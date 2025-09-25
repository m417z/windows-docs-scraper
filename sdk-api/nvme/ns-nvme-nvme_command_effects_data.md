# NVME_COMMAND_EFFECTS_DATA structure

## Description

Contains information that describes the overall possible effect of an Admin or I/O command, including any optional features of the command.

This structure is used in the **ACS** and **IOCS** fields of the [NVME_COMMAND_EFFECTS_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_log).

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.CSUPP`

Indicates whether the command is supported.

When this value is set to `1`, the command is supported by the controller. When this value is cleared to `0`, the command is not supported by the controller and
all other fields in this structure will be cleared to `0h`.

### `DUMMYSTRUCTNAME.LBCC`

Indicates whether the command can modify logical block content in one or more namespaces.

When this value is set to `1`, the command can modify logical block content in one or more namespaces. When this value is cleared to `0`, the command does not modify logical block content in any namespace. Logical block content changes include a write to a logical block.

### `DUMMYSTRUCTNAME.NCC`

Indicates whether the command can change the capabilities of a single namespace.

When this value is set to `1`, the command can change the capabilities of a single namespace. When this value is cleared to `0`, the command does not modify any namespace capabilities for the specified namespace. Namespace capability changes include a logical format change.

### `DUMMYSTRUCTNAME.NIC`

Indicates whether the command can change the number of namespaces or capabilities for multiple namespaces.

When this value is set to `1`, the command can change the number of namespaces or capabilities for multiple namespaces. When this value is cleared to `0`, the command does not modify the number of namespaces or capabilities for multiple namespaces. Namespace inventory changes (NIC) include adding or removing namespaces.

### `DUMMYSTRUCTNAME.CCC`

Indicates whether the command can change controller capabilities.

When this value is set to `1`, the command can change controller capabilities. When this value is cleared to `0`, the command does not modify controller capabilities. Controller capability changes (CCC) include a firmware update that changes the capabilities reported in the CAP register.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.CSE`

An [NVME_COMMAND_EFFECT_SBUMISSION_EXECUTION_LIMITS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_command_effect_sbumission_execution_limits) value that defines the command submission and execution recommendations for the associated command.

### `DUMMYSTRUCTNAME.Reserved1`

### `AsUlong`

## Remarks

Host software may take command effects into account when determining how to submit commands and actions to take after the command is complete. If a command changes a particular capability. the host software should re-enumerate and/or re-initialize the associated capability after the command is complete.

For example, if a namespace capability change may occur, then the host software should pause the use of the associated namespace, submit the command that may cause a namespace capability change and wait for its completion, and then re-issue the Identify command.

## See also

- [NVME_COMMAND_EFFECTS_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_log)