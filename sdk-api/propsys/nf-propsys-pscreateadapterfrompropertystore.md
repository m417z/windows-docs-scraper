# PSCreateAdapterFromPropertyStore function

## Description

Creates an adapter from an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Parameters

### `pps` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

Pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object that represents the property store.

### `riid` [in]

Type: **REFIID**

Reference to an IID.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The adapter object implements [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage), [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore), [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities), and [IObjectProvider](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iobjectprovider).

Use this function if you need an object that implements [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) with an API that requires an [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface. The object created can also be useful to a namespace extension that wants to provide support for binding to namespace items using **IPropertySetStorage**. Applications must call this object from only one thread at a time.

The adapter property store created by this function retains a reference to the source [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface. Therefore, the calling application is free to release its reference to the source **IPropertyStore** whenever convenient after calling this function.

The adapter property store makes calls to methods on the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface as appropriate. Therefore, if the calling application is writing values to the store, it should call the [IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit) method on only one of the interfaces.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSCreateAdapterFromPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreateadapterfrompropertystore) to use an adapter property store to convert an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface into an [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface.

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
IPropertySetStorage *pSetStorage;

HRESULT hr = PSCreateadapterFromPropertyStore(ppropstore, IID_PPV_ARGS(&pSetStorage));

if (SUCCEEDED(hr))
{
    // pSetStorage is now valid and can be used to access the data in ppropstore.
    pSetStorage->Release();
}
```

## See also

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[PSCreatePropertyStoreFromPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatepropertystorefrompropertysetstorage)