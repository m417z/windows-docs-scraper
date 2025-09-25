# PFND3D12DDI_CALC_PRIVATE_META_COMMAND_SIZE_0052 callback function

## Description

**PFND3D12DDI_CALC_PRIVATE_META_COMMAND_SIZE_0052** calculates the private meta-command size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `CommandId`

The command id.

### `NodeMask`

The node mask of the command list.

### `pCreationParameters`

Pointer to the creation parameters.

### `CreationParametersDataSizeInBytes`

The size in bytes of the creation parameters that **pCreationParameters** points to.

## Return value

Returns SIZE_T that describes the meta-command size, in bytes.