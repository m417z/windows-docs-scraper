# PFND3D12DDI_EXECUTE_META_COMMAND_0052 callback function

## Description

**PFND3D12DDI_EXECUTE_META_COMMAND_0052** executes a meta-command.

## Parameters

### `unnamedParam1`

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam2`

A handle to the meta-command.

### `unnamedParam3`

A pointer to the execution parameters for the meta-command.

### `unnamedParam4`

Size of the execution parameters for the meta-command, in bytes.

## Remarks

The meta-command initialize call must be executed at least once prior to any execute call being executed on the GPU timeline.

## See also

[**PFND3D12DDI_INITIALIZE_META_COMMAND_0052**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_initialize_meta_command_0052)