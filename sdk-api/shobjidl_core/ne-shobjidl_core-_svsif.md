# _SVSIF enumeration

## Description

Indicates flags used by [IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview), [IFolderView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview2), [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) and [IShellView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview2) to specify a type of selection to apply.

## Constants

### `SVSI_DESELECT:0`

0x00000000. Deselect the item.

### `SVSI_SELECT:0x1`

0x00000001. Select the item.

### `SVSI_EDIT:0x3`

0x00000003. Put the name of the item into rename mode. This value includes SVSI_SELECT.

### `SVSI_DESELECTOTHERS:0x4`

0x00000004. Deselect all but the selected item. If the item parameter is **NULL**, deselect all items.

### `SVSI_ENSUREVISIBLE:0x8`

0x00000008. In the case of a folder that cannot display all of its contents on one screen, display the portion that contains the selected item.

### `SVSI_FOCUSED:0x10`

0x00000010. Give the selected item the focus when multiple items are selected, placing the item first in any list of the collection returned by a method.

### `SVSI_TRANSLATEPT:0x20`

0x00000020. Convert the input point from screen coordinates to the list-view client coordinates.

### `SVSI_SELECTIONMARK:0x40`

0x00000040. Mark the item so that it can be queried using [IFolderView::GetSelectionMarkedItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-getselectionmarkeditem).

### `SVSI_POSITIONITEM:0x80`

0x00000080. Allows the window's default view to position the item. In most cases, this will place the item in the first available position. However, if the call comes during the processing of a mouse-positioned context menu, the position of the context menu is used to position the item.

### `SVSI_CHECK:0x100`

0x00000100. The item should be checked. This flag is used with items in views where the checked mode is supported.

### `SVSI_CHECK2:0x200`

0x00000200. The second check state when the view is in tri-check mode, in which there are three values for the checked state. You can indicate tri-check mode by specifying FWF_TRICHECKSELECT in [IFolderView2::SetCurrentFolderFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview2-setcurrentfolderflags). The 3 states for FWF_TRICHECKSELECT are unchecked, SVSI_CHECK and SVSI_CHECK2.

### `SVSI_KEYBOARDSELECT:0x401`

0x00000401. Selects the item and marks it as selected by the keyboard. This value includes SVSI_SELECT.

### `SVSI_NOTAKEFOCUS:0x40000000`

0x40000000. An operation to select or focus an item should not also set focus on the view itself.

## Remarks

An additional value SVSI_NOSTATECHANGE is also defined outside of the enumeration. This value indicates that an operation to edit or position an item should not affect the item's focus or selected state. Its numeric value is (UINT)0x80000000.

The **SVSIF** type used to refer to members of the **_SVSIF** enumeration is defined in Shobjidl.h as shown here.

```
typedef UINT SVSIF;
```