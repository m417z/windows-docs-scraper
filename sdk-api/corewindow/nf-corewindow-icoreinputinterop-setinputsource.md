# ICoreInputInterop::SetInputSource

## Description

Sets the input source for an app's [CoreIndependentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.coreindependentinputsource) or [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource).

## Parameters

### `value` [in]

Pointer to the base COM interface of the input source.

The input source can be either [IDCompositionVisual2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual2) or [Windows.UI.Composition.Visual](https://learn.microsoft.com/uwp/api/windows.ui.composition.visual)

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource)

[CoreIndependentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.coreindependentinputsource)

[ICoreInputInterop](https://learn.microsoft.com/windows/desktop/api/corewindow/nn-corewindow-icoreinputinterop)