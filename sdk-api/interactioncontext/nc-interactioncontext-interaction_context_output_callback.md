# INTERACTION_CONTEXT_OUTPUT_CALLBACK callback function

## Description

Callback that receives events from an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

> [!NOTE]
> See [INTERACTION_CONTEXT_OUTPUT_CALLBACK2 callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback2) for enhanced gesture recognition support.

## Parameters

### `clientData` [in, optional]

A pointer to an object that contains information about the client. The value typically points to the object for which the member function is called.

### `output` [in]

Output of the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## See also

[INTERACTION_CONTEXT_OUTPUT_CALLBACK2 callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback2)

[INTERACTION_CONTEXT_OUTPUT structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output)

[INTERACTION_CONTEXT_OUTPUT2 structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output2)

[INTERACTION_CONTEXT_OUTPUT2 structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output2)

[RegisterOutputCallbackInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext)

[RegisterOutputCallbackInteractionContext2 function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext2)