# INTERACTION_CONTEXT_OUTPUT2 structure

## Description

Defines the output of the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Members

### `interactionId`

ID of the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

### `interactionFlags`

One of the constants from [INTERACTION_FLAGS enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_flags).

### `inputType`

One of the constants from [POINTER_INPUT_TYPE enumeration](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type).

### `contactCount`

The number of contacts that can be recognized.

### `currentContactCount`

The number of current contacts.

### `x`

The x-coordinate of the input pointer, in HIMETRIC units.

### `y`

The y-coordinate of the input pointer, in HIMETRIC units.

### `arguments`

Union of *arguments* sub-fields.

### `arguments.manipulation`

The state of the manipulation.

### `arguments.tap`

The state of the tap gesture.

### `arguments.crossSlide`

The state of the cross-slide interaction.

## Remarks

Provides enhanced gesture recognition support compared to the [INTERACTION_CONTEXT_OUTPUT structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_output).

## See also

[INTERACTION_ARGUMENTS_CROSS_SLIDE structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_arguments_cross_slide)

[INTERACTION_ARGUMENTS_MANIPULATION structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_arguments_manipulation)

[INTERACTION_ARGUMENTS_TAP structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_arguments_tap)

[INTERACTION_CONTEXT_OUTPUT_CALLBACK callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback)

[INTERACTION_CONTEXT_OUTPUT_CALLBACK2 callback function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nc-interactioncontext-interaction_context_output_callback2)

[INTERACTION_FLAGS enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_flags)

[RegisterOutputCallbackInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext)

[RegisterOutputCallbackInteractionContext2 function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-registeroutputcallbackinteractioncontext2)