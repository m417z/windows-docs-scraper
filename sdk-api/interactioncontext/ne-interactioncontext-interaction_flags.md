# INTERACTION_FLAGS enumeration

## Description

Specifies the state of an interaction.

## Constants

### `INTERACTION_FLAG_NONE:0x00000000`

No flags set.

### `INTERACTION_FLAG_BEGIN:0x00000001`

The beginning of an interaction.

### `INTERACTION_FLAG_END:0x00000002`

The end of an interaction (including inertia).

### `INTERACTION_FLAG_CANCEL:0x00000004`

Interaction canceled. INTERACTION_FLAG_END also set on cancel.

### `INTERACTION_FLAG_INERTIA:0x00000008`

Inertia being processed.

### `INTERACTION_FLAG_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[INTERACTION_CONTEXT_OUTPUT structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output)

[INTERACTION_CONTEXT_OUTPUT2 structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output2)

[INTERACTION_CONTEXT_OUTPUT_CALLBACK callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback)

[INTERACTION_CONTEXT_OUTPUT_CALLBACK2 callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback2)

[RegisterOutputCallbackInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext)

[RegisterOutputCallbackInteractionContext2 function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext2)