# IPlayToManagerInterop::GetForWindow

## Description

Gets the [PlayToManager](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager) instance for the specified window.

## Parameters

### `appWindow` [in]

The window to get the [PlayToManager](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager) instance for.

### `riid` [in]

The reference ID of the specified window.

### `playToManager` [out, retval]

The [PlayToManager](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager) instance for the specified window.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the **GetForWindow** method to get the [PlayToManager](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager) for the specified window. The **GetForWindow** method is equivalent to the [GetForCurrentView](https://learn.microsoft.com/uwp/api/windows.graphics.printing.printmanager.getforcurrentview) method, except that you supply a reference to a window from a multi-window Windows Store app.

## See also

[GetForCurrentView](https://learn.microsoft.com/uwp/api/windows.graphics.printing.printmanager.getforcurrentview)

[IPlayToManagerInterop](https://learn.microsoft.com/windows/desktop/api/playtomanagerinterop/nn-playtomanagerinterop-iplaytomanagerinterop)

[PlayToManager](https://learn.microsoft.com/uwp/api/windows.media.playto.playtomanager)