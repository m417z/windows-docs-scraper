# DestroyInteractionContext function

## Description

Destroys the specified [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Parameters

### `interactionContext` [in]

The handle of the interaction context.

## Return value

If this function succeeds, it returns S_OK.
Otherwise, it returns an HRESULT error code.

## Remarks

**DestroyInteractionContext** must be called to destroy any interaction context created by [CreateInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-createinteractioncontext).

## See also

[ResetInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-resetinteractioncontext)

[StopInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-stopinteractioncontext)