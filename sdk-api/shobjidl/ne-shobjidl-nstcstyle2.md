# NSTCSTYLE2 enumeration

## Description

Used by methods of the [INameSpaceTreeControl2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-inamespacetreecontrol2) to specify extended display styles in a Shell namespace treeview.

## Constants

### `NSTCS2_DEFAULT:0`

Displays the tree nodes in default mode, which includes none of the following values.

### `NSTCS2_INTERRUPTNOTIFICATIONS:0x1`

Displays interrupt notifications.

### `NSTCS2_SHOWNULLSPACEMENU:0x2`

Displays the context menu in the padding space.

### `NSTCS2_DISPLAYPADDING:0x4`

Inserts spacing (padding) between top-level nodes.

### `NSTCS2_DISPLAYPINNEDONLY:0x8`

Filters items based on the [System.IsPinnedToNameSpaceTree](https://learn.microsoft.com/windows/desktop/properties/props-system-ispinnedtonamespacetree) value when [INameSpaceTreeControlFolderCapabilities](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-inamespacetreecontrolfoldercapabilities) is implemented.

### `NTSCS2_NOSINGLETONAUTOEXPAND:0x10`

### `NTSCS2_NEVERINSERTNONENUMERATED:0x20`

Do not insert nonenumerated (SFGAO_NONENUMERATED) items in the tree.

#### - NSTCS2_NOSINGLETONAUTOEXPAND

Prevents automatic expansion of singleton nodes in the tree.

## Remarks

The value NSTCS2_ALLMASK can be used to mask for the NSTCS2_INTERRUPTNOTIFICATIONS, NSTCS2_SHOWNULLSPACEMENU, and NSTCS2_DISPLAYPADDING values.