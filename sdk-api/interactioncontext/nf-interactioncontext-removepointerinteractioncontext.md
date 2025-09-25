# RemovePointerInteractionContext function

## Description

Remove the specified pointer from the set of pointers processed by the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Parameters

### `interactionContext` [in]

Handle to the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

### `pointerId` [in]

ID of the pointer.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[AddPointerInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-addpointerinteractioncontext)