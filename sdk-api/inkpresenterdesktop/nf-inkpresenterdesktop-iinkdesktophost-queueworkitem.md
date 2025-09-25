# IInkDesktopHost::QueueWorkItem

## Description

Add an ink operation to a work queue for execution on the [IInkDesktopHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkdesktophost) thread.

The app is responsible for synchronizing the work queue with the UI thread.

## Parameters

### `workItem` [in]

An [IInkHostWorkItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkhostworkitem) object representing an ink operation.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Complex ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[IInkDesktopHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/inkpresenterdesktop/nn-inkpresenterdesktop-iinkdesktophost)

[Pen and stylus interactions](https://learn.microsoft.com/windows/uwp/input-and-devices/pen-and-stylus-interactions)

**Samples**

[Complex Ink sample](https://github.com/microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)

[Simple ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/SimpleInk)