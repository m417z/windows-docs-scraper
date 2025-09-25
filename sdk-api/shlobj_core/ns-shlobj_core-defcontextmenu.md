# DEFCONTEXTMENU structure

## Description

Contains context menu information used by [SHCreateDefaultContextMenu](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedefaultcontextmenu).

## Members

### `hwnd`

Type: **HWND**

A handle to the context menu. Set this member to the handle returned from [CreateMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createmenu).

### `pcmcb`

Type: **[IContextMenuCB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenucb)***

A pointer to the [IContextMenuCB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenucb) interface supported by the callback object. This value is optional and can be **NULL**.

### `pidlFolder`

Type: **PCIDLIST_ABSOLUTE**

The PIDL of the folder that contains the selected file object(s) or the folder of the context menu if no file objects are selected. This value is optional and can be **NULL**, in which case the PIDL is computed from the **psf** member.

### `psf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface of the folder object that contains the selected file objects, or the folder that contains the context menu if no file objects are selected.

### `cidl`

Type: **UINT**

The count of items in member **apidl**.

### `apidl`

Type: **PCUITEMID_CHILD_ARRAY**

A pointer to a constant array of [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures. Each entry in the array describes a child item to which the context menu applies, for instance, a selected file the user wants to **Open**.

### `punkAssociationInfo`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface on the object from which to load extensions. This parameter is optional and thus can be **NULL**. If this value is **NULL** and members **aKeys** and **cKeys** are also **NULL** (see Remarks), **punkAssociationInfo** is computed from the **apidl** member and **cidl** via a request for **IQueryAssociations** through [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof).

If [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof) returns **E_NOTIMPL**, a default implementation is provided based on the *SFGAO_FOLDER* and *SFGAO_FILESYSTEM* attributes returned from [IShellFolder::GetAttributesOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof).

### `cKeys`

Type: **UINT**

The count of items in member **aKeys**. This value can be zero. If the value is zero, the extensions are loaded based on the object that supports interface [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) as specified by member **punkAssociationInfo**. If the value is non-NULL, the extensions are loaded based only on member **aKeys** and not member **punkAssociationInfo**.

**Note** The maximum number of keys is 16. Callers must enforce this limit as the API does not. Failing to do so can result in memory corruption.

### `aKeys`

Type: **const HKEY***

A pointer to an HKEY that specifies the registry key from which to load extensions. This parameter is optional and can be **NULL**. If the value is **NULL**, the extensions are loaded based on the object that supports interface [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) as specified in **punkAssociationInfo**.

## Remarks

If the **aKeys** and **cKeys** members are valid and member **punkAssociationInfo** is also valid (not **NULL**), the system constructs the menu using the values of **aKeys** and **cKeys**, and ignores member **punkAssociationInfo** ([IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations)).

Members **apidl** and **cidl** can be used as parameters to method [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof) to retrieve [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject).