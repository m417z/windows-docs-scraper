# _NSTCITEMSTATE enumeration

## Description

Specifies the state of a tree item. These values are used by methods of the [INameSpaceTreeControl](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacetreecontrol) interface.

## Constants

### `NSTCIS_NONE:0`

The item has default state; it is not selected, expanded, bolded or disabled.

### `NSTCIS_SELECTED:0x1`

The item is selected.

### `NSTCIS_EXPANDED:0x2`

The item is expanded.

### `NSTCIS_BOLD:0x4`

The item is bold.

### `NSTCIS_DISABLED:0x8`

The item is disabled.

### `NSTCIS_SELECTEDNOEXPAND:0x10`

**Windows 7 and later**. The item is selected, but not expanded.

## See also

[INameSpaceTreeControl::GetItemState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacetreecontrol-getitemstate)

[INameSpaceTreeControl::SetItemState](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacetreecontrol-setitemstate)