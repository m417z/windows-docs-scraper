# INTERACTION_CONFIGURATION_FLAGS enumeration

## Description

Specifies the interactions to enable when configuring an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Constants

### `INTERACTION_CONFIGURATION_FLAG_NONE:0x00000000`

No interactions enabled.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION:0x00000001`

All manipulations enabled (move, rotate, and scale).

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_TRANSLATION_X:0x00000002`

Translate (move) along the x-axis.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_TRANSLATION_Y:0x00000004`

Translate (move) along the y-axis.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_ROTATION:0x00000008`

Rotation.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_SCALING:0x00000010`

Scaling.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_TRANSLATION_INERTIA:0x00000020`

Translation inertia (in direction of move) after contact lifted.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_ROTATION_INERTIA:0x00000040`

Rotation inertia after contact lifted.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_SCALING_INERTIA:0x00000080`

Scaling inertia after contact lifted.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_RAILS_X:0x00000100`

Interactions are constrained along the x-axis.

Rails indicate that slight motions off the primary axis of motion are ignored. This makes for a tighter experience for users; when they attempt to pan along a single axis, they are constrained to the axis.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_RAILS_Y:0x00000200`

Interactions are constrained along the y-axis.

Rails indicate that slight motions off the primary axis of motion are ignored. This makes for a tighter experience for users; when they attempt to pan along a single axis, they are constrained to the axis.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_EXACT:0x00000400`

Report exact distance from initial contact to end of the interaction.

By default, a small distance threshold is subtracted from the first manipulation delta reported by the system. This distance threshold is intended to account for slight movements of the contact when processing a tap gesture. If this flag is set, the distance threshold is not subtracted from the first delta.

### `INTERACTION_CONFIGURATION_FLAG_MANIPULATION_MULTIPLE_FINGER_PANNING:0x00000800`

### `INTERACTION_CONFIGURATION_FLAG_CROSS_SLIDE:0x00000001`

All cross-slide interactions enabled.

### `INTERACTION_CONFIGURATION_FLAG_CROSS_SLIDE_HORIZONTAL:0x00000002`

Cross-slide along the x-axis.

### `INTERACTION_CONFIGURATION_FLAG_CROSS_SLIDE_SELECT:0x00000004`

Selection using cross-slide.

### `INTERACTION_CONFIGURATION_FLAG_CROSS_SLIDE_SPEED_BUMP:0x00000008`

Speed bump effect.

A speed bump is a region in which the user experiences a slight drag (or friction) during the swipe or slide gesture.

### `INTERACTION_CONFIGURATION_FLAG_CROSS_SLIDE_REARRANGE:0x00000010`

Rearrange using cross-slide.

### `INTERACTION_CONFIGURATION_FLAG_CROSS_SLIDE_EXACT:0x00000020`

Report exact distance from initial contact to end of the interaction.

By default, a small distance threshold is subtracted from the first cross-slide delta reported by the system. This distance threshold is intended to account for slight movements of the contact when processing a tap gesture. If this flag is set, the distance threshold is not subtracted from the first delta.

### `INTERACTION_CONFIGURATION_FLAG_TAP:0x00000001`

Tap.

### `INTERACTION_CONFIGURATION_FLAG_TAP_DOUBLE:0x00000002`

Double tap.

### `INTERACTION_CONFIGURATION_FLAG_SECONDARY_TAP:0x00000001`

Secondary tap.

### `INTERACTION_CONFIGURATION_FLAG_HOLD:0x00000001`

Hold.

### `INTERACTION_CONFIGURATION_FLAG_HOLD_MOUSE:0x00000002`

Hold with mouse.

### `INTERACTION_CONFIGURATION_FLAG_DRAG:0x00000001`

Drag with mouse.

### `INTERACTION_CONFIGURATION_FLAG_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[INTERACTION_CONTEXT_CONFIGURATION structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_configuration)

[SetInteractionConfigurationInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setinteractionconfigurationinteractioncontext)