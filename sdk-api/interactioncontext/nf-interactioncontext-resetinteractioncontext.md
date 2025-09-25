# ResetInteractionContext function

## Description

Resets the [interaction state](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_state), interaction configuration settings, and all parameters to their initial state. Current interactions are cancelled without notifications.
[Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) must be reconfigured before next use.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

Useful for managing a pool of [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) objects.

Current interactions are cancelled without notifications.

## See also

[CreateInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-createinteractioncontext)

[DestroyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-destroyinteractioncontext)

[StopInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-stopinteractioncontext)