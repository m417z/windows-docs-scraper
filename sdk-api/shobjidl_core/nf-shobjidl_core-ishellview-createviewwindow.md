# IShellView::CreateViewWindow

## Description

Creates a view window. This can be either the right pane of Windows Explorer or the client window of a folder window.

## Parameters

### `psvPrevious` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

The address of the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface of the view window being exited. Views can use this parameter to communicate with a previous view of the same implementation. This interface can be used to optimize browsing between like views. This pointer may be **NULL**.

### `pfs` [in]

Type: **LPCFOLDERSETTINGS**

The address of a [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure. The view should use this when creating its view.

### `psb` [in]

Type: **[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)***

The address of the current instance of the [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser) interface. The view should call this interface's [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and keep the interface pointer to allow communication with the Windows Explorer window.

### `prcView` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

The dimensions of the new view, in client coordinates.

### `phWnd` [out]

Type: **HWND***

The address of the window handle being created.

## Return value

Type: **HRESULT**

Returns a success code if successful, or a COM error code otherwise. Use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to determine whether the operation succeeded or failed.

## Remarks

### Notes to Calling applications

Call this method when the view needs to be created.

### Notes to Implementers

Create your view window and restore any persistent state by calling the [GetViewStateStream](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-getviewstatestream) method. Store the [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser) pointer for further use.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)