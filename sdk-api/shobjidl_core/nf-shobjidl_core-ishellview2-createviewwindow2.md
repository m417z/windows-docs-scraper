# IShellView2::CreateViewWindow2

## Description

Used to request the creation of a new Shell view window. It can be either the right pane of Windows Explorer or the client window of a folder window.

## Parameters

### `lpParams`

Type: **LPSV2CVW2_PARAMS**

A pointer to an [SV2CVW2_PARAMS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-sv2cvw2_params) structure that defines the new view window.

## Return value

Type: **HRESULT**

Returns a success code if successful, or a COM error code otherwise. Use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to determine whether the operation succeeded or failed.

## Remarks

This method supersedes [CreateViewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-createviewwindow). With **CreateViewWindow2**, developers are not restricted to the standard view modes provided by **CreateViewWindow**, but may also create their own. All view modes are now identified by their GUID.

The size of the structure, previous view window, folder settings, parent Shell browser, and view rectangle are passed into **IShellView2::CreateViewWindow2** in the first five members of *lpParams*. The method is responsible for creating the new window and passing back its window handle and the GUID of the view mode in the last two parameters. **IShellView2::CreateViewWindow2** should call the parent browser's [IShellBrowser::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and store the interface pointer. It can be used for communication with the Windows Explorer window.

## See also

[IShellView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview2)

[IShellView2::GetView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview2-getview)