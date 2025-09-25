# IOleInPlaceFrame::RemoveMenus

## Description

Removes a container's menu elements from the composite menu.

## Parameters

### `hmenuShared` [in]

A handle to the in-place composite menu that was constructed by calls to [IOleInPlaceFrame::InsertMenus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-insertmenus) and the [InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua) function.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified handle is invalid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

The object should always give the container a chance to remove its menu elements from the composite menu before deactivating the shared user interface.

### Notes to Callers

This method is called by the object application while it is being UI-deactivated to remove its menus.

## See also

[IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe)

[IOleInPlaceFrame::SetMenu](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setmenu)

[InsertMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insertmenua)