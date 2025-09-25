# SetInteractionConfigurationInteractionContext function

## Description

Configures the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object to process the specified manipulations.

## Parameters

### `interactionContext` [in]

The handle of the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `configurationCount` [in]

The number of interactions being configured.

### `configuration` [in]

The interactions to enable for this [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

By default, no configuration flags are set (no interactions are enabled). Each interaction must be explicitly declared.

Configuration changes are applied only to new interactions.

## See also

[GetInteractionConfigurationInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getinteractionconfigurationinteractioncontext)

[INTERACTION_CONTEXT_CONFIGURATION structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_configuration)