# PSCreatePropertyStoreFromPropertySetStorage function

## Description

Wraps an [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface in an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface.

## Parameters

### `ppss` [in]

Type: **[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)***

A pointer to an [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface.

### `grfMode` [in]

Type: **DWORD**

Specifies the access mode to enforce. grfMode should match the access mode used to open the [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage). Valid values are as follows:

#### STGM_READ

Calls to [IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue) update an internal cache of properties, and calls to [IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit) call the appropriate [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) methods to write out the changed properties.

#### STGM_WRITE

Not supported.

#### STGM_READWRITE

Not supported.

### `riid` [in]

Type: **REFIID**

Reference to an IID.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer specified in *riid*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function wraps an [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface in an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface. Any value other than **STGM_READ** for *grfMode*, causes calls to [IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue) and [IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit) to fail with **STG_E_ACCESSDENIED.**