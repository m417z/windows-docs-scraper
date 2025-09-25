# SHCreateShellItem function

## Description

Creates an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object.

**Note** It is recommended that you use [SHCreateItemWithParent](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemwithparent) or [SHCreateItemFromIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromidlist) instead of this function.

## Parameters

### `pidlParent` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

A PIDL to the parent. This value can be **NULL**.

### `psfParent` [in, optional]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the parent [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder). This value can be **NULL**.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A PIDL to the requested item. If parent information is not included in *pidlParent* or *psfParent*, this must be an absolute PIDL.

### `ppsi` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

When this method returns, contains the interface pointer to the new [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SHCreateShellItem** creates an object that represents a Shell namespace item. The caller must provide parent information in *pidlParent* or *psfParent*; alternatively, the caller can provide an absolute IDList in the *pidl* parameter.

There are three valid calling patterns for this function:

1. The parent folder is identified by an absolute IDList *pidlParent*. The *pidl* parameter points to a child IDList that identifies the item within the folder identified by *pidlParent*.

   ```cpp
   IShellItem *psi;
   SHCreateShellItem(pidlParent, NULL, pidlChild, &psi);

   ```
2. The parent folder is identified by *psfParent*. The *pidl* parameter points to a child IDList that identifies the item within the folder identified by *psfParent*.

   ```cpp
   IShellItem *psi;
   SHCreateShellItem(NULL, psfParent, pidlChild, &psi);

   ```
3. The item is identified by an absolute IDList passed to the *pidl* parameter.

   ```cpp
   IShellItem *psi;
   SHCreateShellItem(NULL, NULL, pidlFull, &psi);

   ```