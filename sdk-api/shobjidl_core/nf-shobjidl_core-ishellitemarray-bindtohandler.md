# IShellItemArray::BindToHandler

## Description

Binds to an object by means of the specified handler.

## Parameters

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object.

### `bhid` [in]

Type: **REFGUID**

One of the following values, defined in Shlguid.h, that determine the handler.

#### BHID_SFUIObject

Restricts usage to [GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof). Use this handler type only for a flat item array, where all items are in the same folder.

#### BHID_DataObject

**Introduced in Windows Vista**: Gets an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object for use with an item or an array of items. Use this handler type only for flat data objects or item arrays created by [SHCreateShellItemArrayFromDataObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateshellitemarrayfromdataobject).

#### BHID_AssociationArray

**Introduced in Windows Vista**: Gets an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) object for use with an item or an array of items. This only retrieves the association array object for the first item in the [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)

### `riid` [in]

Type: **REFIID**

The IID of the object type to retrieve.

### `ppvOut` [out]

Type: **void****

When this methods returns, contains the object specified in *riid* that is returned by the handler specified by *rbhid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.