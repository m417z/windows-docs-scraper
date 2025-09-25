# IDirectManipulationViewport::SetViewportOptions

## Description

Sets how the viewport handles input and output.

Calling this method overrides all settings previously specified with [SetUpdateMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setupdatemode) or [SetInputMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setinputmode).

## Parameters

### `options` [in]

One or more of the values from [DIRECTMANIPULATION_VIEWPORT_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_viewport_options).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method with [DIRECTMANIPULATION_INPUT_MODE_MANUAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_input_mode) set is similar to calling **SetViewportOptions(DIRECTMANIPULATION_VIEWPORT_OPTIONS_INPUT)**.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)