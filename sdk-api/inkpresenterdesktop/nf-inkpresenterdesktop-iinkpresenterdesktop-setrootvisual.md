# IInkPresenterDesktop::SetRootVisual

## Description

Sets the connection to the app's [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal) visual tree.

## Parameters

### `rootVisual` [in]

The app's [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal) visual tree.

### `device` [in]

NULL for default ink rendering, or an [IDCompositionDevice3](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice3) object used to commit all pending DirectComposition commands for custom drying of ink input to the app's [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal) visual tree.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Complex ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop)

[Pen and stylus interactions](https://learn.microsoft.com/windows/uwp/input-and-devices/pen-and-stylus-interactions)

**Samples**

[Complex Ink sample](https://github.com/microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[Simple ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/SimpleInk)