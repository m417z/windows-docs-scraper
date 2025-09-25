# SetMouseWheelParameterInteractionContext function

## Description

Sets the parameter values for mouse wheel input.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `value` [in]

The value for *parameter*.

### `parameter` [in]

One of the constants identified by [MOUSE_WHEEL_PARAMETER enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-mouse_wheel_parameter).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[GetMouseWheelParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getmousewheelparameterinteractioncontext)