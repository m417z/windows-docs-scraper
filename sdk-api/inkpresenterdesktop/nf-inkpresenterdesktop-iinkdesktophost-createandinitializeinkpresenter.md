# IInkDesktopHost::CreateAndInitializeInkPresenter

## Description

Creates an [IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop) object on an application thread, connects it to the app's [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal) visual tree, and sets the size of the object.

## Parameters

### `rootVisual` [in]

The [IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual) of the app.

### `width` [in]

The width, in pixels, of the inking area.

### `height` [in]

The height, in pixels, of the inking area.

### `riid` [in]

A reference to the interface identifier of an [IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop) object.

### `ppv` [out]

Address of a pointer variable that receives the interface pointer identified by *riid*.

## Return value

If successful, returns the requested interface pointer. Otherwise, returns **NULL**.

## See also

[Complex ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[IInkDesktopHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkdesktophost)

[Pen and stylus interactions](https://learn.microsoft.com/windows/uwp/input-and-devices/pen-and-stylus-interactions)

**Samples**

[Complex Ink sample](https://github.com/microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[Simple ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/SimpleInk)