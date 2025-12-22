# _NSTCSTYLE enumeration

## Description

Describes the characteristics of a given namespace tree control.

## Constants

### `NSTCS_HASEXPANDOS:0x1`

The control displays a triangle—known as an expando—on the leftmost edge of those items that have child items. Clicking on the expando expands the item to reveal the children of the item. Has no effect when combined with NSTCS_SHOWTABSBUTTON, NSTCS_SHOWDELETEBUTTON, or NSTCS_SHOWREFRESHBUTTON.

Maps to the [TVS_HASBUTTONS](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_HASLINES:0x2`

The control draws lines to the left of the tree items that lead to their individual parent items. Has no effect when combined with NSTCS_SHOWTABSBUTTON, NSTCS_SHOWDELETEBUTTON, or NSTCS_SHOWREFRESHBUTTON.

Maps to the [TVS_HASLINES](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_SINGLECLICKEXPAND:0x4`

An item expands to show its child items in response to a single mouse click.

Maps to the [TVS_SINGLEEXPAND](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_FULLROWSELECT:0x8`

The selection of an item fills the row with inverse text to the end of the window area, regardless of the length of the text. When this option is not declared, only the area behind text is inverted. This value cannot be combined with NSTCS_HASLINES.

Maps to the [TVS_FULLROWSELECT](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_SPRINGEXPAND:0x10`

When one item is selected and expanded and you select a second item, the first selection automatically collapses.

This is the opposite of the [TVS_EX_NOSINGLECOLLAPSE](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

### `NSTCS_HORIZONTALSCROLL:0x20`

The area of the window that contains the tree of namespace items has a horizontal scroll bar.

Maps to the [WS_HSCROLL](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) Windows style.

### `NSTCS_ROOTHASEXPANDO:0x40`

The root item is preceded by an expando that allows expansion of the root item.

Maps to the [TVS_LINESATROOT](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_SHOWSELECTIONALWAYS:0x80`

The node of an item is outlined when the control does not have the focus.

Maps to the [TVS_SHOWSELALWAYS](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_NOINFOTIP:0x200`

Do not display infotips when the mouse cursor is over an item.

This is the opposite of the [TVS_INFOTIP](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_EVENHEIGHT:0x400`

Sets the height of the items to an even height. By default, the height of items can be even or odd.

This is the opposite of the [TVS_NONEVENHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_NOREPLACEOPEN:0x800`

Do not replace the **Open** command in the shortcut menu with a user-defined function.

### `NSTCS_DISABLEDRAGDROP:0x1000`

Do not allow drag-and-drop operations within the control. Note that you can still drag an item from outside of the control and drop it onto the control.

Maps to the [TVS_DISABLEDRAGDROP](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_NOORDERSTREAM:0x2000`

Do not persist reordering changes. Used with NSTCS_FAVORITESMODE. If favorites mode is not specified, this flag has no effect.

### `NSTCS_RICHTOOLTIP:0x4000`

Use a rich tooltip. Rich tooltips display the item's icon in addition to the item's text. A standard tooltip displays only the item's text. The tree view displays tooltips only for items in the tree that are partially visible.

Maps to the [TVS_EX_RICHTOOLTIP](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

NSTCS_RICHTOOLTIP has no effect unless it is combined with NSTCS_NOINFOTIP and/or NSTCS_FAVORITESMODE. If NSTCS_NOINFOTIP is not specified, the tree view displays an infotip instead of a tooltip. If NSTCS_FAVORITESMODE is not specified, the namespace tree control always sets the [TVS_EX_RICHTOOLTIP](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) style.

### `NSTCS_BORDER:0x8000`

Draw a thin border around the control. Corresponds to [WS_BORDER](https://learn.microsoft.com/windows/desktop/winmsg/window-styles).

### `NSTCS_NOEDITLABELS:0x10000`

Do not allow creation of an in-place edit box, which would allow the user to rename the given item.

This is the opposite of the [TVS_EDITLABELS](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_TABSTOP:0x20000`

If the control is hosted, you can tabstop into the control. Corresponds to [WS_EX_CONTROLPARENT](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

### `NSTCS_FAVORITESMODE:0x80000`

The control has the appearance of the favorites band in Windows XP.

### `NSTCS_AUTOHSCROLL:0x100000`

When you hover the mouse pointer over an item that extends past the end of the control window, the control automatically scrolls horizontally so that the item appears more fully in the window area.

Maps to the [TVS_EX_AUTOHSCROLL](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

### `NSTCS_FADEINOUTEXPANDOS:0x200000`

If the control does not have the focus and there are items that are preceded by expandos, then these expandos are visible only when the mouse pointer is near to the control.

Maps to the [TVS_EX_FADEINOUTEXPANDOS](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

### `NSTCS_EMPTYTEXT:0x400000`

If an item has no children and is not expanded, then that item contains a line of text at the child level that says "empty".

### `NSTCS_CHECKBOXES:0x800000`

Items have check boxes on their leftmost side. These check boxes can be of types partial, exclusion or dimmed, which correspond to the flags NSTCS_PARTIALCHECKBOXES, NSTCS_EXCLUSIONCHECKBOXES, and NSTCS_DIMMEDCHECKBOXES.

Maps to the [TVS_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) tree view control style.

### `NSTCS_PARTIALCHECKBOXES:0x1000000`

Adds a checkbox icon on the leftmost side of a given item with a square in the center, that indicates that the node is partially selected. Must be combined with NSTCS_CHECKBOXES.

Maps to the [TVS_EX_PARTIALCHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

### `NSTCS_EXCLUSIONCHECKBOXES:0x2000000`

Adds a checkbox icon on the leftmost side of a given item that contains a red **X**, which indicates that the item is excluded from the current selection. Without this exclusion icon, selection of a parent item includes selection of its child items. Must be combined with NSTCS_CHECKBOXES.

Maps to the [TVS_EX_EXCLUSIONCHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

### `NSTCS_DIMMEDCHECKBOXES:0x4000000`

Adds a checkbox on the leftmost side of a given item that contains an icon of a dimmed check mark, that indicates that a node is selected because its parent is selected. Must be combined with NSTCS_CHECKBOXES.

Maps to the [TVS_EX_DIMMEDCHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

### `NSTCS_NOINDENTCHECKS:0x8000000`

Check boxes are located at the far left edge of the window area instead of being indented.

Maps to the [TVS_EX_NOINDENTSTATE](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-extended-styles) tree view control style.

### `NSTCS_ALLOWJUNCTIONS:0x10000000`

Allow junctions. A junction point, or just junction, is a root of a namespace extension that is normally displayed by Windows Explorer as a folder in both tree and folder views. For Windows Explorer to display your extension's files and subfolders, you must specify where the root folder is located in the Shell namespace hierarchy.

Junctions exist in the file system as files, but are not treated as files. An example is a compressed file with a .zip file name extension, which to the file system is just a file. However, if this file is treated as a junction, it can represent an entire namespace. This allows the namespace tree control to treat compressed files and similar junctions as folders rather than as files.

### `NSTCS_SHOWTABSBUTTON:0x20000000`

Displays an arrow on the right side of an item if the item is a folder. The action associated with the arrow is implementation specific. Cannot be combined with NSTCS_SHOWDELETEBUTTON or NSTCS_SHOWREFRESHBUTTON.

### `NSTCS_SHOWDELETEBUTTON:0x40000000`

Displays a red **X** on the right side of an item. The action associated with the **X** is implementation specific. Cannot be combined with NSTCS_SHOWTABSBUTTON or NSTCS_SHOWREFRESHBUTTON.

### `NSTCS_SHOWREFRESHBUTTON`

Displays a refresh button on the right side of an item. The action associated with the button is implementation specific. Cannot be combined with NSTCS_SHOWTABSBUTTON or NSTCS_SHOWDELETEBUTTON.

## Remarks

Three values have effect only in conjunction with NSTCS_CHECKBOXES: NSTCS_PARTIALCHECKBOXES, NSTCS_EXCLUSIONCHECKBOXES, and NSTCS_DIMMEDCHECKBOXES. The icons associated with these states are inserted into the state image list as follows:

| Image Slot | Image | Associated Flags |
| --- | --- | --- |
| 0 | Blank | NSTCS_CHECKBOXES |
| 1 | Unchecked | NSTCS_CHECKBOXES |
| 2 | Checked | NSTCS_CHECKBOXES |
| 3 | Partial | NSTCS_CHECKBOXES \| NSTCS_PARTIALCHECKBOXES |
| 4 | Exclusion (red X) | NSTCS_CHECKBOXES \| NSTCS_EXCLUSIONCHECKBOXES |

## See also

[INameSpaceTreeControl2::GetControlStyle](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-getcontrolstyle)

[INameSpaceTreeControl2::SetControlStyle](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-inamespacetreecontrol2-setcontrolstyle)

[INameSpaceTreeControl::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacetreecontrol-initialize)