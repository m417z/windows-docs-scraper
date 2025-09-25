# _SVGIO enumeration

## Description

Used with the [IFolderView::Items](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-items), [IFolderView::ItemCount](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-itemcount), and [IShellView::GetItemObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellview-getitemobject) methods to restrict or control the items in their collections.

## Constants

### `SVGIO_BACKGROUND:0`

0x00000000. Refers to the background of the view. It is used with IID_IContextMenu to get a shortcut menu for the view background and with IID_IDispatch to get a dispatch interface that represents the [ShellFolderView](https://learn.microsoft.com/windows/desktop/shell/shellfolderview) object for the view.

### `SVGIO_SELECTION:0x1`

0x00000001. Refers to the currently selected items. Used with IID_IDataObject to retrieve a data object that represents the selected items.

### `SVGIO_ALLVIEW:0x2`

0x00000002. Used in the same way as [SVGIO_SELECTION](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svgio) but refers to all items in the view.

### `SVGIO_CHECKED:0x3`

0x00000003. Used in the same way as [SVGIO_SELECTION](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svgio) but refers to checked items in views where checked mode is supported. For more details on checked mode, see [FOLDERFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderflags).

### `SVGIO_TYPE_MASK:0xf`

0x0000000F. Masks all bits but those corresponding to the [_SVGIO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svgio) flags.

### `SVGIO_FLAG_VIEWORDER:0x80000000`

0x80000000. Returns the items in the order they appear in the view. If this flag is not set, the selected item will be listed first.

## Remarks

The **SVGIO** type used to refer to members of the **_SVGIO** enumeration is defined in Shobjidl.h as shown here.

```
typedef int SVGIO;
```