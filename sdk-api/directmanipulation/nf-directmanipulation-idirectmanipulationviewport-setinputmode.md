# IDirectManipulationViewport::SetInputMode

## Description

Specifies if input is visible to the UI thread.

## Parameters

### `mode` [in]

One of the values from [DIRECTMANIPULATION_INPUT_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_input_mode).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

DIRECTMANIPULATION_INPUT_MODE_AUTOMATIC is the default mode for [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal).

[Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) consumes all the input that drives the manipulation and the application receives WM_POINTERCAPTURECHANGED messages.

In some situations an application may want to receive input that is driving a manipulation. Set DIRECTMANIPULATION_INPUT_MODE_MANUAL in this case. The application will receive all input messages, even input used by [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) to drive a manipulation.

**Note** The application will not receive WM_POINTERCAPTURECHANGED messages.

Calling this method with [DIRECTMANIPULATION_INPUT_MODE_MANUAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_input_mode) set is similar to calling [SetViewportOptions(DIRECTMANIPULATION_VIEWPORT_OPTIONS_INPUT)](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setviewportoptions). However, calling **SetViewportOptions** also overrides all other settings.

#### Examples

The following example shows how to use this method.

```
HRESULT hr = pViewport->SetInputMode(DIRECTMANIPULATION_INPUT_MODE_AUTOMATIC);
```

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)