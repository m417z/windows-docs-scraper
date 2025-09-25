# IShellView::UIActivate

## Description

Called when the activation state of the view window is changed by an event that is not caused by the Shell view itself. For example, if the TAB key is pressed when the tree has the focus, the view should be given the focus.

## Parameters

### `uState`

Type: **UINT**

Flag specifying the activation state of the window. This parameter can be one of the following values.

#### SVUIA_ACTIVATE_FOCUS

Windows Explorer has just created the view window with the input focus. This means the Shell view should be able to set menu items appropriate for the focused state.

#### SVUIA_ACTIVATE_NOFOCUS

The Shell view is losing the input focus, or it has just been created without the input focus. The Shell view should be able to set menu items appropriate for the nonfocused state. This means no selection-specific items should be added.

#### SVUIA_DEACTIVATE

Windows Explorer is about to destroy the Shell view window. The Shell view should remove all extended user interfaces. These are typically merged menus and merged modeless pop-up windows.

#### SVUIA_INPLACEACTIVATE

The Shell view is active without focus. This flag is only used when **UIActivate** is exposed through the [IShellView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview2) interface.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or a COM-defined error value otherwise.

## Remarks

Before remerging menu items, the Shell view typically hooks the [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus) message and calls the [OnViewWindowActive](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellbrowser-onviewwindowactive) method. The Shell view should not hook the [NM_KILLFOCUS](https://learn.microsoft.com/windows/desktop/Controls/nm-killfocus) message to remerge menu items.

### Notes to Calling Applications

Call this method to inform the view of an activation state change.

### Notes to Implementers

Use this method to track the activation state and change any behavior, as appropriate.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)