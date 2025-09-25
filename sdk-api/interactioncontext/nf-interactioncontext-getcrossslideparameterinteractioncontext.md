# GetCrossSlideParameterInteractionContext function

## Description

Gets the cross-slide interaction behavior.

## Parameters

### `interactionContext` [in]

The handle of the interaction context.

### `threshold` [in]

One of the constants from [CROSS_SLIDE_THRESHOLD enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-cross_slide_threshold).

### `distance` [out]

The distance threshold of *threshold*.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## See also

[CROSS_SLIDE_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-cross_slide_parameter)

[SetCrossSlideParametersInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setcrossslideparametersinteractioncontext)