# IDefaultFolderMenuInitialize::Initialize

## Description

Sets context menu info for the [IDefaultFolderMenuInitialize](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-idefaultfoldermenuinitialize) object.

## Parameters

### `hwnd` [in]

A handle to the shortcut menu.

### `pcmcb` [in, optional]

Type: **[IContextMenuCB](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-icontextmenucb)***

The address of the object that defines the callback for the shortcut menu.

### `pidlFolder` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

The address of an item identifier list that specifies the folder of the items. If NULL, this is computed from the *psf* parameter.

### `psf` [in, optional]

Type: **[IShellFolder](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

The folder of the items.

### `cidl` [in]

Type: **UINT**

The count of items in the *apidl* parameter.

### `apidl` [in]

Type: **PCUITEMID_CHILD_ARRAY**

A pointer to an array of PIDL structures, each of which is an item to be operated on.

### `punkAssociation` [in, optional]

Type: **IUnknown***

The address of an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) object that specifies where to load extensions from.

### `cKeys` [in]

Type: **UINT**

The count of items in the *aKeys* parameter. May be zero.

### `aKeys` [in, optional]

Type: **const HKEY***

Specifies where to load extensions from.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDefaultFolderMenuInitialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idefaultfoldermenuinitialize)