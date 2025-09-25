## Description

The **RS_ALL_COMMANDS_PARAMETER_DATA** structure contains a list of **[RS_COMMAND_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-rs_command_descriptor)** structures.

## Members

### `CommandDataLength[4]`

The length of this structure.

### `CommandDescriptor[ANYSIZE_ARRAY]`

An array of **[RS_COMMAND_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-rs_command_descriptor)** structures.

## Remarks

## See also