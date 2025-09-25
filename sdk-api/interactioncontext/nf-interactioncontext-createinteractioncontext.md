# CreateInteractionContext function

## Description

Creates and initializes an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Parameters

### `interactionContext` [out]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

## Return value

If this function succeeds, it returns S_OK.
Otherwise, it returns an HRESULT error code.

## Remarks

[DestroyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-destroyinteractioncontext) must be called to destroy any interaction context created by **CreateInteractionContext**.

## See also

[ResetInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-resetinteractioncontext)

[StopInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-stopinteractioncontext)