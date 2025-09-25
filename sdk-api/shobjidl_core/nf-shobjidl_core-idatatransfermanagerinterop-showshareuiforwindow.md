# IDataTransferManagerInterop::ShowShareUIForWindow

## Description

Displays the UI for sharing content for the specified window.

## Parameters

### `appWindow` [in]

The window to show the share UI for.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is equivalent to the [DataTransferManager.ShowShareUI](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager.showshareui) method, except that you specify a window from a multi-window Windows Store app.

## See also

[DataTransferManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager)

[DataTransferManager.ShowShareUI](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager.showshareui)

[IDataTransferManagerInterop](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idatatransfermanagerinterop)