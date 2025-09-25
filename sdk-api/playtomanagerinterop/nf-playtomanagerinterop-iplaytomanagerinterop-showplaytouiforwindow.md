# IPlayToManagerInterop::ShowPlayToUIForWindow

## Description

Displays the Play To UI for the specified window.

## Parameters

### `appWindow` [in]

The window to show the Play To UI for.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the **ShowPlayToUIForWindow** method to show the Play To UI for the specified window. The **ShowPlayToUIForWindow** method is equivalent to the [ShowPlayToUI](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager.showplaytoui) method, except that you supply a reference to a window from a multi-window Windows Store app.

## See also

[IPlayToManagerInterop](https://learn.microsoft.com/windows/desktop/api/playtomanagerinterop/nn-playtomanagerinterop-iplaytomanagerinterop)

[PlayToManager](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager)

[ShowPlayToUI](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager.showplaytoui)