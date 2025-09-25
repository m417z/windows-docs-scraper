# INTERACTION_ID enumeration

## Description

Specifies the interaction states used for configuring an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object. Interactions can be static (single contact with no manipulation, such as tap, double tap, right tap, press and hold) or dynamic (one or more contacts with manipulation, such as translation, rotation, or scaling).

## Constants

### `INTERACTION_ID_NONE:0x00000000`

Not used.

### `INTERACTION_ID_MANIPULATION:0x00000001`

A compound gesture that supports translation, rotation, and scaling (dynamic).

### `INTERACTION_ID_TAP:0x00000002`

A tap gesture (static).

### `INTERACTION_ID_SECONDARY_TAP:0x00000003`

A right click gesture (static), regardless of input device. Typically used for displaying a context menu.

* Right mouse button click
* Pen barrel button click
* Touch or pen press and hold

### `INTERACTION_ID_HOLD:0x00000004`

Press and hold gesture (static).

### `INTERACTION_ID_DRAG:0x00000005`

Move with mouse or pen (dynamic).

### `INTERACTION_ID_CROSS_SLIDE:0x00000006`

Select or move through slide or swipe gestures (dynamic).

### `INTERACTION_ID_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[INTERACTION_CONTEXT_CONFIGURATION structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_configuration)

[SetInteractionConfigurationInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setinteractionconfigurationinteractioncontext)