# INameSpaceTreeControlDropHandler::OnDropPosition

## Description

Called when the item is being dropped within the same level (within the same parent folder) in the tree.

## Parameters

### `psiOver` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interface representing the item underneath the mouse cursor. Optional.

### `psiaData` [in]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) array representing a data object.

### `iNewPosition` [in]

Type: **int**

The index if the item being dropped is between items; otherwise, NSTCDHPOS_ONTOP (-1).

### `iOldPosition` [in]

Type: **int**

Specifies old position.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Failing this method prevents the item rearrangement from happening.