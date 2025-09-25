# CDefFolderMenu_Create2 function

## Description

Creates a context menu for a selected group of file folder objects.

## Parameters

### `pidlFolder` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

An [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure for the parent folder. This value can be **NULL**.

### `hwnd` [in, optional]

Type: **HWND**

A handle to the parent window. This value can be **NULL**.

### `cidl`

Type: **UINT**

The number of [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures in the array pointed to by *apidl*.

### `apidl` [in, optional]

Type: **PCUITEMID_CHILD_ARRAY***

A pointer to an array of [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures, one for each item that is selected.

### `psf` [in, optional]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the parent folder's [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface. This **IShellFolder** must support the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface. If it does not, **CDefFolderMenu_Create2** fails and returns E_NOINTERFACE. This value can be **NULL**.

### `pfn` [in, optional]

Type: **[LPFNDFMCALLBACK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-lpfndfmcallback)**

The [LPFNDFMCALLBACK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-lpfndfmcallback) callback object. This value can be **NULL** if the callback object is not needed.

### `nKeys`

Type: **UINT**

The number of registry keys in the array pointed to by *ahkeys*.

**Note** The maximum number of registry keys is 16. Callers must enforce this limit as the API does not. Failing to do so can result in memory corruption.

### `ahkeys` [in, optional]

Type: **const HKEY***

A pointer to an array of registry keys that specify the context menu handlers used with the menu's entries. For more information on context menu handlers, see [Creating Context Menu Handlers](https://learn.microsoft.com/windows/desktop/shell/context-menu-handlers). This array can contain a maximum of 16 registry keys.

### `ppcm` [out]

Type: **[IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu)****

The address of an [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) interface pointer that, when this function returns successfully, points to the **IContextMenu** object that represents the context menu.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[SHCreateDefaultContextMenu](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedefaultcontextmenu)