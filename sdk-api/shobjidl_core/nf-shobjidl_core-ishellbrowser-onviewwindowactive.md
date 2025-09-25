# IShellBrowser::OnViewWindowActive

## Description

Called by the Shell view when the view window or one of its child windows gets the focus or becomes active.

## Parameters

### `pshv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

Address of the view object's [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) pointer.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

The view must pass its [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) implementation to this routine, although the current version of Windows Explorer does not use this parameter.

### Notes to Callers

The Shell view object must call this method before calling the [IShellBrowser::InsertMenusSB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-insertmenussb) method. This method will insert a different set of menu items depending on whether the view has the focus.

### Notes to Implementers

This method informs the browser that the view is getting the focus (when the mouse is clicked on the view, for example).

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)