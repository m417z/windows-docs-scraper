# QCMINFO structure

## Description

Contains information for merging menu items into Windows Explorer menus.

## Members

### `hmenu`

Type: **HMENU**

[in] The handle of the menu where the new commands are to be added.

### `indexMenu`

Type: **UINT**

[in] The zero-based index where the first menu item are to be inserted.

### `idCmdFirst`

Type: **UINT**

[in, out] On entry, this member contains the first available ID to be used for the context menu. On exit, it contains the last ID added plus one.

### `idCmdLast`

Type: **UINT**

[in] The maximum value for a menu item identifier. The difference between the input value of **idCmdFirst** and **idCmdLast** is the maximum number of menu items that can be added.

### `pIdMap`

Type: **QCMINFO_IDMAP***

Not used, must be **NULL**.

## Remarks

See [IContextMenu::QueryContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-querycontextmenu) as this structure performs the same role as the parameters of that method. Note, however, that the information provided by the return value of that method is not a parallel to the information provided by the return value of an operation involving **QCMINFO**.

## See also

[DFM_MERGECONTEXTMENU](https://learn.microsoft.com/windows/desktop/shell/registering-control-panel-items)

[DFM_MERGECONTEXTMENU_BOTTOM](https://learn.microsoft.com/windows/desktop/shell/reg-middleware-apps)

[DFM_MERGECONTEXTMENU_TOP](https://learn.microsoft.com/windows/desktop/shell/samples-aerowizards)

[SFVM_MERGEMENU](https://learn.microsoft.com/windows/desktop/shell/sfvm-mergemenu)