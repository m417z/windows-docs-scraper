# INamespaceWalkCB::EnterFolder

## Description

Called when a folder is about to be entered during a namespace walk. Use this method for any initialization of the retrieved item.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to an [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object representing the parent of the folder designated by *pidl*.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

The PIDL, relative to *psf*, of the folder being entered.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.