# INamespaceWalkCB::FoundItem

## Description

Called when an object is found in the namespace during a namespace walk. Use this method as the main action function for the class implementing it. Perform your actions as needed inside this method.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to an [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object representing the folder containing the item.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

The item's PIDL, relative to *psf*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.