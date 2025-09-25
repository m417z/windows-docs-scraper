# D3D12DDIARG_META_COMMAND_DESC structure

## Description

The **D3D12DDIARG_META_COMMAND_DESC** structure contains the description of a meta-command. A meta-command is a Direct3D object intended to represent an IHV-accelerated algorithm. It’s an opaque reference to a command generator implemented by the driver.

## Members

### `Id`

The id of a meta-command.

### `Name`

Pointer to a wide string that holds the name of the meta-command. The driver allocates and keeps this string for the lifetime of the device.

### `InitializationDirtyState`

A [**D3D12DDI_GRAPHICS_STATES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_graphics_states) value specifying the command list states that are modified by the initialization call.

### `ExecutionDirtyState`

A [**D3D12DDI_GRAPHICS_STATES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_graphics_states) value specifying the command list states that are modified by the execute call.

## Remarks

## See also

[**PFND3D12DDI_ENUMERATE_META_COMMANDS_0052**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_enumerate_meta_commands_0052)