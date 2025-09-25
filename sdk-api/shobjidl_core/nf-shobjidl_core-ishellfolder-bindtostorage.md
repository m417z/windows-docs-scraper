# IShellFolder::BindToStorage

## Description

Requests a pointer to an object's storage interface.

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

The address of an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that identifies the subfolder relative to its parent folder. The structure must contain exactly one [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structure followed by a terminating zero.

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

The optional address of an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object to be used during this operation. If this parameter is not used, set it to **NULL**. Because support for *pbc* is optional for folder object implementations, some folders may not support the use of bind contexts.

### `riid` [in]

Type: **REFIID**

The IID of the requested storage interface. To retrieve an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream), [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage), or [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface pointer, set *riid* to **IID_IStream**, **IID_IStorage**, or **IID_IPropertySetStorage**, respectively.

### `ppv` [out]

Type: **void****

The address that receives the interface pointer specified by *riid*. If an error occurs, a **NULL** pointer is returned in this address.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Namespace extensions have the option of allowing applications to bind to an object that represents an item's storage. If this option is supported, **IShellFolder::BindToStorage** returns a specified interface pointer that can then be used to access the contents of object. See the [IMoniker::BindToStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtostorage) reference for further discussion.