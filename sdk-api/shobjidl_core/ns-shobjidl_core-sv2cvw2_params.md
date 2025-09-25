# SV2CVW2_PARAMS structure

## Description

Holds the parameters for the [IShellView2::CreateViewWindow2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview2-createviewwindow2) method.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure.

### `psvPrev`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface of the previous view. A Shell view can use this parameter to communicate with a previous view with the same implementation. It can also be used to optimize browsing between like views. This parameter may be **NULL**.

### `pfs`

Type: **LPFOLDERSETTINGS**

A [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure with information needed to create the view.

### `psbOwner`

Type: **[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)***

A pointer to the current instance of the [IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser) interface of the parent Shell browser. [IShellView2::CreateViewWindow2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview2-createviewwindow2) should call this interface's [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and store the interface pointer. It can be used for communication with the Windows Explorer window.

### `prcView`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A **RECT** structure that defines the view's display area.

### `pvid`

Type: **const SHELLVIEWID***

A pointer to a view ID. The view ID can be one of the Windows-defined VIDs or a custom, view-defined VID. This value takes precedence over the view mode designated in the [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure pointed to by **pfs**.

### `hwndView`

Type: **HWND**

A window handle to the new Shell view.