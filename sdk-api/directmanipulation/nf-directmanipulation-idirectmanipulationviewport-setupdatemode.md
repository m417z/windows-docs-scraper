# IDirectManipulationViewport::SetUpdateMode

## Description

 Specifies whether a viewport updates content manually instead of during an input event.

## Parameters

### `mode` [in]

One of the values from [DIRECTMANIPULATION_INPUT_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_input_mode).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

DIRECTMANIPULATION_INPUT_MODE_AUTOMATIC is the default mode for [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal). In this mode, visual updates are pushed to compositor driven by input. This is the expected mode of operation if the application is using system-provided implementation of [IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor).

If the application provides its own implementation of [IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor), it should switch viewport update mode to manual by setting DIRECTMANIPULATION_INPUT_MODE_MANUAL. When in manual mode, the compositor pulls visual updates whenever it calls [Update](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationupdatemanager-update) on [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal).

Calling this method with [DIRECTMANIPULATION_INPUT_MODE_MANUAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_input_mode) set is similar to calling [SetViewportOptions(DIRECTMANIPULATION_VIEWPORT_OPTIONS_INPUT)](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setviewportoptions). However, calling **SetViewportOptions** also overrides all other settings.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)