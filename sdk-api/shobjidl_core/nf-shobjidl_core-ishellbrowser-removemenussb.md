# IShellBrowser::RemoveMenusSB

## Description

Permits the container to remove any of its menu elements from the in-place composite menu and to free all associated resources.

## Parameters

### `hmenuShared`

Type: **HMENU**

A handle to the in-place composite menu that was constructed by calls to [IShellBrowser::InsertMenusSB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-insertmenussb) and the [InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua) function.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

This method is similar to the [IOleInPlaceFrame::RemoveMenus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-removemenus) method.

The object should always permit the container to remove its menu elements from the composite menu before deactivating the shared user interface.

### Notes to Calling Applications

The method is called by the object application while it is being UI-deactivated so the browser can remove its menus.

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)