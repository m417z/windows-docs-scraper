# D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063 enumeration

## Description

**D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063** specifies the parameter stages for video extension commands.

## Constants

### `D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_CREATION:0`

The parameter stage is in video extension command creation.

### `D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_INITIALIZATION:1`

The parameter stage is in video extension command initialization.

### `D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_EXECUTION:2`

The parameter stage is in video extension command execution.

### `D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_CAPS_INPUT:3`

The parameter stage is input parameters passed to capabilities queries.

### `D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_CAPS_OUTPUT:4`

The parameter stage is output parameters passed to capabilities queries.

### `D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0076_DEVICE_EXECUTE_INPUT:5`

The parameter stage is device execution input.

### `D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0076_DEVICE_EXECUTE_OUTPUT:6`

The parameter stage is device execution input.

## Remarks

Video Extensions support different parameterization at creation, initialization, and execution. Values from this enumeration are used when querying for video extension parameter information.