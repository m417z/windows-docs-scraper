# INameSpaceTreeControlDropHandler::OnDragLeave

## Description

Called on drag leave for a specified item.

## Parameters

### `psiOver` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interface representing the item underneath the mouse cursor. Optional.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave)

[INameSpaceTreeControlDropHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontroldrophandler)