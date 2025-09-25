# MANIPULATION_RAILS_STATE enumeration

## Description

Specifies the rail states for an interaction.

## Constants

### `MANIPULATION_RAILS_STATE_UNDECIDED:0x00000000`

Rail state not defined yet.

### `MANIPULATION_RAILS_STATE_FREE:0x00000001`

Interaction is not constrained to rail.

### `MANIPULATION_RAILS_STATE_RAILED:0x00000002`

Interaction is constrained to rail.

### `MANIPULATION_RAILS_STATE_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[INTERACTION_ARGUMENTS_MANIPULATION structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_arguments_manipulation)

[RegisterOutputCallbackInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext)

[RegisterOutputCallbackInteractionContext2 function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext2)