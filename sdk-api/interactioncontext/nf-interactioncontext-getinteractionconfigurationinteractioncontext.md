# GetInteractionConfigurationInteractionContext function

## Description

Gets interaction configuration state for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `configurationCount` [in]

Number of interaction configurations.

### `configuration` [out]

The interactions enabled for this [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[INTERACTION_CONTEXT_CONFIGURATION structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-interaction_context_configuration)

[SetInteractionConfigurationInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setinteractionconfigurationinteractioncontext)