# INamespaceWalkCB::LeaveFolder

## Description

Called after a namespace walk through a folder. Use this method to perform any necessary cleanup following the actions performed by [INamespaceWalkCB::EnterFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacewalkcb-enterfolder) or [INamespaceWalkCB::FoundItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inamespacewalkcb-founditem).

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to an [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object representing the parent of the folder designated by *pidl*.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A PIDL, relative to *psf*, of the folder being exited.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.