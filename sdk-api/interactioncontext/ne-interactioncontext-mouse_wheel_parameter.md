# MOUSE_WHEEL_PARAMETER enumeration

## Description

Specifies the manipulations that can be mapped to mouse wheel rotation.

## Constants

### `MOUSE_WHEEL_PARAMETER_CHAR_TRANSLATION_X:0x00000001`

Scrolling/panning distance along the x-axis.

### `MOUSE_WHEEL_PARAMETER_CHAR_TRANSLATION_Y:0x00000002`

Scrolling/panning distance along the y-axis.

### `MOUSE_WHEEL_PARAMETER_DELTA_SCALE:0x00000003`

The relative change in scale, as a multiplier, since the last input message.

### `MOUSE_WHEEL_PARAMETER_DELTA_ROTATION:0x00000004`

The relative change in rotation, in radians, since the last input message.

### `MOUSE_WHEEL_PARAMETER_PAGE_TRANSLATION_X:0x00000005`

Paging distance along the x-axis.

### `MOUSE_WHEEL_PARAMETER_PAGE_TRANSLATION_Y:0x00000006`

Paging distance along the y-axis.

### `MOUSE_WHEEL_PARAMETER_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[GetMouseWheelParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getmousewheelparameterinteractioncontext)

[SetMouseWheelParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setmousewheelparameterinteractioncontext)