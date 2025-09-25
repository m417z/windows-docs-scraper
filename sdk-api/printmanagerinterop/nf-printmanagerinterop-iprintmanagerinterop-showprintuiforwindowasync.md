# IPrintManagerInterop::ShowPrintUIForWindowAsync

## Description

Displays the UI for printing content for the specified window.

## Parameters

### `appWindow` [in]

The window to show the print UI for.

### `riid` [in]

The reference ID of the specified window.

### `asyncOperation` [out, retval]

The asynchronous operation that reports completion.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the **ShowPrintUIForWindowAsync** method to show the print UI for the specified window. The **ShowPrintUIForWindowAsync** method is equivalent to the [ShowPrintUIAsync](https://learn.microsoft.com/uwp/api/windows.graphics.printing.printmanager.showprintuiasync) method, except that you supply a reference to a window from a multi-window Windows Store app.

## See also

[IPrintManagerInterop](https://learn.microsoft.com/windows/desktop/api/printmanagerinterop/nn-printmanagerinterop-iprintmanagerinterop)

[PrintManager](https://learn.microsoft.com/uwp/api/Windows.Graphics.Printing.PrintManager)

[ShowPrintUIAsync](https://learn.microsoft.com/uwp/api/windows.graphics.printing.printmanager.showprintuiasync)