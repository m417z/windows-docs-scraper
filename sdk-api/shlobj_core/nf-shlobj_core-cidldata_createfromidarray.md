# CIDLData_CreateFromIDArray function

## Description

[**CIDLData_CreateFromIDArray** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a data object with the default vtable pointer.

## Parameters

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

A fully qualified IDLIST for the root of the items specified in *apidl*.

### `cidl` [in]

Type: **UINT**

The number of entries in the *apidl* array.

### `apidl` [in]

Type: **PCUIDLIST_RELATIVE_ARRAY**

The array of item IDs relative to *pidlFolder*. Typically, *apidl* is an array of child IDs and *pidlFolder* is a full PIDL for those items. However, *pidlFolder* can be a null PIDL (desktop IDLISTs). In that case, *apidl* can contain fully qualified ID lists.

### `ppdtobj` [out]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)****

The address to a pointer to the object that implements [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The data object created by this function offers the Shell clipboard format identifier [CFSTR_SHELLIDLIST](https://learn.microsoft.com/windows/desktop/shell/clipboard). This data object also supports [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata) calls to pick up other clipboard formats.

## See also

[SHCreateDataObject](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedataobject)