# INTERACTION_CONTEXT_CONFIGURATION structure

## Description

Defines the configuration of an [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object that enables, disables, or modifies the behavior of an interaction.

## Members

### `interactionId`

One of the constants from [INTERACTION_ID enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_id).

> [!NOTE]
> INTERACTION_FLAG_NONE is not a valid value.

### `enable`

The value of this property is a bitmask, which can be set to one or more of the values from [INTERACTION_CONFIGURATION_FLAGS enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_configuration_flags).

This example shows the default setting for **INTERACTION_CONTEXT_CONFIGURATION**.

```cpp
#define INTERACTION_CONTEXT_CONFIGURATION_DEFAULT                         \
{                                                                         \
    {INTERACTION_ID_MANIPULATION,                                         \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION |                     \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION_TRANSLATION_X |       \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION_TRANSLATION_Y |       \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION_ROTATION |            \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION_SCALING |             \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION_TRANSLATION_INERTIA | \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION_ROTATION_INERTIA |    \
        INTERACTION_CONFIGURATION_FLAG_MANIPULATION_SCALING_INERTIA},     \
    {INTERACTION_ID_TAP,                                                  \
        INTERACTION_CONFIGURATION_FLAG_TAP},                              \
    {INTERACTION_ID_SECONDARY_TAP,                                        \
        INTERACTION_CONFIGURATION_FLAG_SECONDARY_TAP},                    \
    {INTERACTION_ID_HOLD,                                                 \
        INTERACTION_CONFIGURATION_FLAG_HOLD},                             \
    {INTERACTION_ID_DRAG,                                                 \
        INTERACTION_CONFIGURATION_FLAG_NONE},                             \
    {INTERACTION_ID_CROSS_SLIDE,                                          \
        INTERACTION_CONFIGURATION_FLAG_NONE}                              \
}                                                                         \
```

## See also

[SetInteractionConfigurationInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setinteractionconfigurationinteractioncontext)