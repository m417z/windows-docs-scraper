# IPrintManagerInterop::GetForWindow

## Description

Gets the [PrintManager](https://learn.microsoft.com/uwp/api/Windows.Graphics.Printing.PrintManager) instance for the specified window.

## Parameters

### `appWindow` [in]

The window to get the [PrintManager](https://learn.microsoft.com/uwp/api/Windows.Graphics.Printing.PrintManager) instance for.

### `riid` [in]

The reference ID of the specified window.

### `printManager` [out, retval]

The [PrintManager](https://learn.microsoft.com/uwp/api/Windows.Graphics.Printing.PrintManager) instance for the specified window.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the **GetForWindow** method to get the [PrintManager](https://learn.microsoft.com/uwp/api/Windows.Graphics.Printing.PrintManager) for the specified window. The **GetForWindow** method is equivalent to the [GetForCurrentView](https://learn.microsoft.com/uwp/api/windows.graphics.printing.printmanager.getforcurrentview) method, except that you supply a reference to a window from a multi-window Windows Store app.

## See also

[GetForCurrentView](https://learn.microsoft.com/uwp/api/windows.graphics.printing.printmanager.getforcurrentview)

[IPrintManagerInterop](https://learn.microsoft.com/windows/desktop/api/printmanagerinterop/nn-printmanagerinterop-iprintmanagerinterop)

[PrintManager](https://learn.microsoft.com/uwp/api/Windows.Graphics.Printing.PrintManager)