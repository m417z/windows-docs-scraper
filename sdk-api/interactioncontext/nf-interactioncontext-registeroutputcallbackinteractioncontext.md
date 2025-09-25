# RegisterOutputCallbackInteractionContext function

## Description

Registers a callback to receive interaction events from an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

> [!NOTE]
> See [RegisterOutputCallbackInteractionContext2 function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext2) for enhanced gesture recognition support.

## Parameters

### `interactionContext` [in]

Handle to the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `outputCallback` [in]

The [INTERACTION_CONTEXT_OUTPUT_CALLBACK callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback).

### `clientData` [in, optional]

A pointer to an object that contains information about the client. The value typically points to the object for which the member function is called (**this**).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

Each instance of an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) is limited to one output callback. Registering a callback function overwrites any existing callback registration for the Interaction Context.

This function is typically called after the creation of an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) or when the Interaction Context is reassigned to another UI element.

## See also

[INTERACTION_CONTEXT_OUTPUT structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output)

[INTERACTION_CONTEXT_OUTPUT2 structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output2)

[INTERACTION_CONTEXT_OUTPUT_CALLBACK callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback)

[INTERACTION_CONTEXT_OUTPUT_CALLBACK2 callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback2)