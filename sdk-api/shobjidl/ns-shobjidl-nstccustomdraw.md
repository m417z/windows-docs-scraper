# NSTCCUSTOMDRAW structure

## Description

Custom draw structure used by [INameSpaceTreeControlCustomDraw](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrolcustomdraw) methods.

## Members

### `psi`

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to a Shell item.

### `uItemState`

Type: **UINT**

The current item state. See [NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw) for more detail.

### `nstcis`

Type: **[NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate)**

The state of a tree item. See [NSTCITEMSTATE](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_nstcitemstate).

### `pszText`

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string that contains the item text, if the structure specifies item attributes.

### `iImage`

Type: **int**

The index in the tree-view control's image list.

### `himl`

Type: **HIMAGELIST**

A handle to an image list.

### `iLevel`

Type: **int**

The zero-based level of the item being drawn.

### `iIndent`

Type: **int**

A tree-level indent.