# IDataTransferManagerInterop::GetForWindow

## Description

Gets the [DataTransferManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager) instance for the specified window.

## Parameters

### `appWindow` [in]

The window whose [DataTransferManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager) instance is to be retrieved.

### `riid` [in]

The requested interface ID of the [DataTransferManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager) instance.

### `dataTransferManager` [out, optional]

Receives the [DataTransferManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager) instance.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is equivalent to the [DataTransferManager.GetForCurrentView](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager.getforcurrentview) method, except that you specify a window from a multi-window Windows Store app.

## See also

[DataTransferManager](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager)

[DataTransferManager.GetForCurrentView](https://learn.microsoft.com/uwp/api/windows.applicationmodel.datatransfer.datatransfermanager.getforcurrentview)

[IDataTransferManagerInterop](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idatatransfermanagerinterop)