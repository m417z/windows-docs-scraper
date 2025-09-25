# IInkDesktopHost::CreateInkPresenter

## Description

Creates an [IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop) object on an application thread.

The [IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop) object can then be configured and connected to the app's [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal) visual tree.

**Note**

Use [CreateAndInitializeInkPresenter](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nf-inkpresenterdesktop-iinkdesktophost-createandinitializeinkpresenter) to do this in a single call.

## Parameters

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