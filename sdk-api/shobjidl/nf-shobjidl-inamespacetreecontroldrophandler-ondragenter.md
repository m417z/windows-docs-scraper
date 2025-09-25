# INameSpaceTreeControlDropHandler::OnDragEnter

## Description

Called on drag enter to set drag effect, as specified.

## Parameters

### `psiOver` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interface representing the item underneath the mouse cursor. Optional.

### `psiaData` [in]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) array containing the items being dragged.

### `fOutsideSource` [in]

Type: **BOOL**

Specifies whether drag started outside target area.

### `grfKeyState` [in]

Type: **DWORD**

The current state of keyboard modifier keys.

### `pdwEffect` [in, out]

Type: **DWORD***

On success, contains a pointer to the drag effect value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Failing this method blocks the drag operation in the namespace tree control (NSTC).

## See also

[IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter)

[INameSpaceTreeControlDropHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontroldrophandler)