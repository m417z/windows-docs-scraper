# INTERACTION_CONTEXT_PROPERTY enumeration

## Description

Specifies properties of the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Constants

### `INTERACTION_CONTEXT_PROPERTY_MEASUREMENT_UNITS:0x00000001`

Measurement units used by the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object: himetric (0.01mm) or screen pixels.

### `INTERACTION_CONTEXT_PROPERTY_INTERACTION_UI_FEEDBACK:0x00000002`

UI feedback is provided.

### `INTERACTION_CONTEXT_PROPERTY_FILTER_POINTERS:0x00000003`

Pointer filtering is active.

### `INTERACTION_CONTEXT_PROPERTY_MAX:0xffffffff`

Maximum number of interactions exceeded.

## See also

[GetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getpropertyinteractioncontext)

[SetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setpropertyinteractioncontext)