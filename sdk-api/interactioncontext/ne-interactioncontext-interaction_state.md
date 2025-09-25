# INTERACTION_STATE enumeration

## Description

Specifies the state of the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Constants

### `INTERACTION_STATE_IDLE:0x00000000`

There are no ongoing interactions and all transitional states (inertia, double tap) are complete. It is safe to reuse the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

### `INTERACTION_STATE_IN_INTERACTION:0x00000001`

There is an ongoing interaction. One or more contacts are detected, or inertia is in progress.

### `INTERACTION_STATE_POSSIBLE_DOUBLE_TAP:0x00000002`

All contacts are lifted, but the time threshold for double tap has not been crossed.

### `INTERACTION_STATE_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[GetStateInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getstateinteractioncontext)