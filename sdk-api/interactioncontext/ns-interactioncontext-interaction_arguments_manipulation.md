# INTERACTION_ARGUMENTS_MANIPULATION structure

## Description

Defines the state of a manipulation.

## Members

### `delta`

The change in translation, rotation, and scale since the last [INTERACTION_CONTEXT_OUTPUT_CALLBACK callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback).

### `cumulative`

The accumulated change in translation, rotation, and scale since the interaction started.

### `velocity`

The velocities of the accumulated transformations for the interaction.

### `railsState`

One of the constants from [MANIPULATION_RAILS_STATE enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-manipulation_rails_state).

## See also

[INTERACTION_CONTEXT_OUTPUT structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output)

[INTERACTION_CONTEXT_OUTPUT2 structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output2)

[RegisterOutputCallbackInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext)

[RegisterOutputCallbackInteractionContext2 function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext2)