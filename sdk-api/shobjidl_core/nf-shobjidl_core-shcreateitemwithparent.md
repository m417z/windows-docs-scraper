# SHCreateItemWithParent function

## Description

Create a Shell item, given a parent folder and a child item ID.

## Parameters

### `pidlParent` [in]

Type: **PCIDLIST_ABSOLUTE**

The IDList of the parent folder of the item being created; the IDList of *psfParent*. This parameter can be **NULL**, if *psfParent* is specified.

### `psfParent` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface that specifies the shell data source of the child item specified by the *pidl*.This parameter can be **NULL**, if *pidlParent* is specified.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A child item ID relative to its parent folder specified by *psfParent* or *pidlParent*.

### `riid` [in]

Type: **REFIID**

A reference to an interface ID.

### `ppvItem` [out]

Type: **void****

When this function returns, contains the interface pointer requested in riid. This will typically be [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or
[IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.