# SetHoldParameterInteractionContext function

## Description

Sets the hold interaction behavior.

## Parameters

### `interactionContext` [in]

The handle of the interaction context.

### `parameter` [in]

One of the constants from the [HOLD_PARAMETER enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-hold_parameter).

### `value` [out]

The value of *parameter*.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[GetHoldParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getholdparameterinteractioncontext)