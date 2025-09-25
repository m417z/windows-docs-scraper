# SHCreateDataObject function

## Description

Creates a data object in a parent folder.

## Parameters

### `pidlFolder` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (PIDL) of the parent folder that contains the data object.

### `cidl` [in]

Type: **UINT**

The number of file objects or subfolders specified in the *apidl* parameter.

### `apidl` [in, optional]

Type: **PCUITEMID_CHILD_ARRAY**

An array of pointers to constant [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures, each of which uniquely identifies a file object or subfolder relative to the parent folder. Each item identifier list must contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero.

### `pdtInner` [in, optional]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to interface [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject). This parameter can be **NULL**. Specify *pdtInner* only if the data object created needs to support additional [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) clipboard formats beyond the default formats it is assigned at creation. Alternatively, provide support for populating the created data object using non-default clipboard formats by calling method [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata) and specifying the format in the **FORMATETC** structure passed in parameter *pFormatetc*.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*. This must be IID_IDataObject.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is typically called when implementing method [IShellFolder::GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof). When an interface pointer of interface ID IID_IDataObject is requested (using parameter *riid*), the implementer can return the interface pointer on the object created with **SHCreateDataObject** in response.

This function supports the [CFSTR_SHELLIDLIST](https://learn.microsoft.com/windows/desktop/shell/clipboard) (also known as HIDA) clipboard format and also has generic support for arbitrary clipboard formats through [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata). For more information on clipboard formats, see Shell Clipboard Formats.

The new data object is intended to be used in operations such as drag-and-drop, in which the data is stored in the clipboard with a given format.

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[CIDLData_CreateFromIDArray](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-cidldata_createfromidarray)