# SetCrossSlideParametersInteractionContext function

## Description

Configures the cross-slide interaction.

## Parameters

### `interactionContext` [in]

The handle of the interaction context.

### `parameterCount` [in]

Number of parameters to set.

### `crossSlideParameters` [in]

The cross-slide threshold and its distance threshold.

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

**SetCrossSlideParametersInteractionContext** fails if a [CROSS_SLIDE_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-cross_slide_parameter) is enabled, but not specified in the *crossSlideParameters* parameter.

### Examples

This example demonstrates how to set custom cross-slide thresholds.

```cpp
//  SetCrossSlideParametersInteractionContext

CROSS_SLIDE_PARAMETER crossSlideParameters[4];
crossSlideParameters[0].threshold = CROSS_SLIDE_THRESHOLD_SELECT_START;
crossSlideParameters[0].distance = customSelectStart;
crossSlideParameters[1].threshold = CROSS_SLIDE_THRESHOLD_SPEED_BUMP_START;
crossSlideParameters[1].distance = customSpeedBumpStart;
crossSlideParameters[2].threshold = CROSS_SLIDE_THRESHOLD_SPEED_BUMP_END;
crossSlideParameters[2].distance = customSpeedBumpEnd;
crossSlideParameters[3].threshold = CROSS_SLIDE_THRESHOLD_REARRANGE_START;
crossSlideParameters[3].distance = customRearrangeStart;

// set thresholds for select, speedbump, and rearrange
SetCrossSlideParametersInteractionContext(
    m_interactionContext,
    4,
    crossSlideParameters);
```

## See also

[CROSS_SLIDE_PARAMETER structure](https://learn.microsoft.com/windows/win32/api/interactioncontext/ns-interactioncontext-cross_slide_parameter)

[GetCrossSlideParameterInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-getcrossslideparameterinteractioncontext)