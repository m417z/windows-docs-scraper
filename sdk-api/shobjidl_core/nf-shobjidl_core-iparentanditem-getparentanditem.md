# IParentAndItem::GetParentAndItem

## Description

Gets the parent of an item and the parent's child ID.

## Parameters

### `ppidlParent` [out, optional]

Type: **PIDLIST_ABSOLUTE***

When this method returns, contains the address of a PIDL that specifies the parent.

### `ppsf` [out, optional]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)****

When this method returns, contains the address of a pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) that is the parent.

### `ppidlChild` [out, optional]

Type: **PITEMID_CHILD***

When this method returns, contains the address of a child PIDL that identifies the [IParentAndItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iparentanditem) object relative to that specified by *ppsf*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 While [IParentAndItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iparentanditem) is typically implemented on IShellItems, it is not specific to [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).