# PSCreatePropertyStoreFromObject function

## Description

Accepts the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of an object that supports [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage). If the object supports **IPropertySetStorage**, it is wrapped so that it supports **IPropertyStore**.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an interface that supports either [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage).

### `grfMode` [in]

Type: **DWORD**

Specifies the access mode to use. One of these values:

#### STGM_READ

Open for reading.

#### STGM_READWRITE

Open for reading and writing.

### `riid` [in]

Type: **REFIID**

Reference to the requested IID.

### `ppv` [out]

Type: **void****

When this function returns successfully, contains the address of a pointer to an interface guaranteed to support [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the object pointed to by *punk* already supports [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore), no wrapper is created and the *punk* is returned unaltered.

## See also

[PSCreatePropertyStoreFromPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatepropertystorefrompropertysetstorage)