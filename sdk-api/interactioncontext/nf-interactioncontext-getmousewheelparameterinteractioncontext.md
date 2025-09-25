# GetMouseWheelParameterInteractionContext function

## Description

Gets the mouse wheel state for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `value` [out]

The value of *parameter*.

### `parameter` [in]

One of the constants from [MOUSE_WHEEL_PARAMETER enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-mouse_wheel_parameter).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[SetMouseWheelParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setmousewheelparameterinteractioncontext)