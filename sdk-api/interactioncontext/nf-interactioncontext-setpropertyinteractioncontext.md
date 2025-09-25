# SetPropertyInteractionContext function

## Description

Sets [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object properties.

## Parameters

### `interactionContext` [in]

Handle to the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

### `contextProperty` [in]

One of the constants identified by [INTERACTION_CONTEXT_PROPERTY enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_context_property).

### `value` [in]

The value of the constant identified by *contextProperty*.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[AddPointerInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-addpointerinteractioncontext)

[GetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getpropertyinteractioncontext)