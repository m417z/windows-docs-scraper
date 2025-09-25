# IShellView3::CreateViewWindow3

## Description

Requests the creation of a new Shell view window. The view can be either the right pane of Windows Explorer or the client window of a folder window. This method replaces [CreateViewWindow2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview2-createviewwindow2).

## Parameters

### `psbOwner` [in]

Type: **[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)***

A pointer to an [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser) interface to provide namespace extension services.

### `psvPrev` [in]

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface that represents the previous view in the Windows Explorer or folder window.

### `dwViewFlags` [in]

Type: **SV3CVW3_FLAGS**

Flags that specify details of the view being created.

#### SV3CVW3_DEFAULT

The default view.

#### SV3CVW3_NONINTERACTIVE

In the case of an error, the view should fail silently rather than displaying a UI.

#### SV3CVW3_FORCEVIEWMODE

The view mode set by **IShellView3::CreateViewWindow3** overrides the saved view state.

#### SV3CVW3_FORCEFOLDERFLAGS

Folder flags set by **IShellView3::CreateViewWindow3** override the saved view state.

### `dwMask` [in]

Type: **[FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags)**

A bitwise mask that specifies which folder options specified in *dwFlags* are to be used.

### `dwFlags` [in]

Type: **[FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags)**

A bitwise value that contains the folder options, as [FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags), to use in the new view.

### `fvMode` [in]

Type: **[FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode)**

A bitwise value that contains the folder view mode options, as [FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode), to use in the new view.

### `pvid` [in]

Type: **const SHELLVIEWID***

A pointer to Shell view ID as a **GUID**.

### `prcView` [in]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a **RECT** structure that provides the dimensions of the view window.

### `phwndView` [out]

Type: **HWND***

A value that receives a pointer to the handle of the new Shell view window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.