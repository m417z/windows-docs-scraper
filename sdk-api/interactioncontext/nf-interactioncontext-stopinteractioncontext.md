# StopInteractionContext function

## Description

Sets the [interaction state](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_state) to INTERACTION_STATE_IDLE and leaves all interaction configuration settings and parameters intact. Current interactions are cancelled and notifications sent as required.
[Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) does not have to be reconfigured before next use.

## Parameters

### `interactionContext` [in]

Handle to the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[CreateInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-createinteractioncontext)

[DestroyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-destroyinteractioncontext)

[ResetInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-resetinteractioncontext)