# IParentAndItem::SetParentAndItem

## Description

Sets the parent of an item and the parent's child ID.

## Parameters

### `pidlParent` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer of the parent.

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) that is the parent.

### `pidlChild` [in]

Type: **PCUITEMID_CHILD**

A PIDL that is a child relative to *psf*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 While [IParentAndItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iparentanditem) is typically implemented on IShellItems, it is not specific to [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).