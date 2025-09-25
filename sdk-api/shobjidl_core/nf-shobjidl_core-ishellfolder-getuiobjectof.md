# IShellFolder::GetUIObjectOf

## Description

Gets an object that can be used to carry out actions on the specified file objects or folders.

## Parameters

### `hwndOwner` [in]

Type: **HWND**

A handle to the owner window that the client should specify if it displays a dialog box or message box.

### `cidl` [in]

Type: **UINT**

The number of file objects or subfolders specified in the *apidl* parameter.

### `apidl` [in]

Type: **PCUITEMID_CHILD_ARRAY**

The address of an array of pointers to [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures, each of which uniquely identifies a file object or subfolder relative to the parent folder. Each item identifier list must contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*. This can be any valid interface identifier that can be created for an item. The most common identifiers used by the Shell are listed in the comments at the end of this reference.

### `rgfReserved` [in, out]

Type: **UINT***

Reserved.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *cidl* is greater than one, the **IShellFolder::GetUIObjectOf** implementation should only succeed if it can create one object for all items specified in *apidl*. If the implementation cannot create one object for all items, this method will fail.

The following are the most common interface identifiers the Shell uses when requesting an interface from this method. The list also indicates if *cidl* can be greater than one for the requested interface.

| Interface Identifier | Allowed *cidl* Value |
| --- | --- |
| [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) | The *cidl* parameter can be greater than or equal to one. |
| [IContextMenu2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu2) | The *cidl* parameter can be greater than or equal to one. |
| [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) | The *cidl* parameter can be greater than or equal to one. |
| [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) | The *cidl* parameter can only be one. |
| [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) | The *cidl* parameter can only be one. |
| [IQueryInfo](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iqueryinfo) | The *cidl* parameter can only be one. |

We recommend that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)