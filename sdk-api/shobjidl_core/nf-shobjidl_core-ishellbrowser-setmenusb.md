# IShellBrowser::SetMenuSB

## Description

Installs the composite menu in the view window.

## Parameters

### `hmenuShared`

Type: **HMENU**

A handle to the composite menu constructed by calls to [IShellBrowser::InsertMenusSB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-insertmenussb) and the [InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua) function.

### `holemenuRes`

Type: **HOLEMENU**

### `hwndActiveObject`

Type: **HWND**

The view's window handle.

## Return value

Type: **RESULT**

Returns **S_OK** if successful, or a COM-defined error value otherwise.

## Remarks

This method is similar to the [IOleInPlaceFrame::SetMenu](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setmenu) method. However, Windows Explorer performs menu dispatch based on the menu item identifier.

The availability of specific menu items depends on whether the view has the focus. Accordingly, it is necessary to call the [IShellBrowser::OnViewWindowActive](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-onviewwindowactive) method whenever the view window (or one of its child windows) has the focus.

### Notes to Calling Applications

The object calls **IShellBrowser_SetMenuSB** to ask the container to install the composite menu structure set up by calls to [IShellBrowser::InsertMenusSB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-insertmenussb).

### Notes to Implementers

A container's implementation of this method should call the **SetMenu** function.

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)