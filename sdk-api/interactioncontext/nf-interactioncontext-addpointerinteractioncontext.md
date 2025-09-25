# AddPointerInteractionContext function

## Description

Include the specified pointer in the set of pointers processed by the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Parameters

### `interactionContext` [in]

Handle to the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

### `pointerId` [in]

ID of the pointer.

## Return value

If this function succeeds, it returns S_OK.
Otherwise, it returns an HRESULT error code.

## Remarks

Turn pointer filtering on by setting INTERACTION_CONTEXT_PROPERTY_FILTER_POINTERS in [SetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setpropertyinteractioncontext).

## See also

[GetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getpropertyinteractioncontext)

[RemovePointerInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-removepointerinteractioncontext)

[SetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setpropertyinteractioncontext)