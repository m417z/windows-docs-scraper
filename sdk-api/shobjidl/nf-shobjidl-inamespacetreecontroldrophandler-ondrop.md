# INameSpaceTreeControlDropHandler::OnDrop

## Description

Called on drop to set drop effect, as specified.

## Parameters

### `psiOver` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interface representing the item underneath the mouse cursor. Optional.

### `psiaData` [in]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) array representing a data object.

### `iPosition` [in]

Type: **int**

Specifies drop position.

### `grfKeyState` [in]

Type: **DWORD**

The current state of keyboard modifier keys.

### `pdwEffect` [in, out]

Type: **DWORD***

A pointer to the drop effect value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** To overwrite the default drop behavior, a client should fail this method; success proceeds with the default drop operation.

## See also

[IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop)

[INameSpaceTreeControlDropHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontroldrophandler)