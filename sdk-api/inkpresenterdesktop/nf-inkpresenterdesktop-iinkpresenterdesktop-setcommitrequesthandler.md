# IInkPresenterDesktop::SetCommitRequestHandler

## Description

Sets an [IInkCommitRequestHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkcommitrequesthandler) object that enables the app (instead of an [IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop) object) to commit all pending Microsoft DirectComposition commands to the app's [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal) visual tree.

This supports a custom drying mode and synchronizes the transition of "wet" ink from the [IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop) object to "dry" ink in the app's [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal) visual tree.

## Parameters

### `handler` [in]

The [IInkCommitRequestHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkcommitrequesthandler) that processes the ink input.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Complex ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[IInkPresenterDesktop](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkpresenterdesktop)

[Pen and stylus interactions](https://learn.microsoft.com/windows/uwp/input-and-devices/pen-and-stylus-interactions)

**Samples**

[Complex Ink sample](https://github.com/microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[Simple ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/SimpleInk)