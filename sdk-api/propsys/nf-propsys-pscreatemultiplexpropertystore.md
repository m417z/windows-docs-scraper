# PSCreateMultiplexPropertyStore function

## Description

Creates a read-only property store that contains multiple property stores, each of which must support either [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage).

## Parameters

### `prgpunkStores` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Address of a pointer to an array of property stores that implement either [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage).

### `cStores` [in]

Type: **DWORD**

The number of elements in the array referenced in *prgpunkStores*.

### `riid` [in]

Type: **REFIID**

Reference to the requested IID.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a Component Object Model (COM) object that implements [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore), [INamedPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-inamedpropertystore), [IObjectProvider](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iobjectprovider), and [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities). The multiplex property store object aggregates the properties exposed from multiple property stores.

This object can be useful for aggregating the properties from multiple existing property store implementations in a Shell namespace extension, or for reusing an existing property store and providing additional read-only properties.

Applications must call this object from only one thread at a time.

You must initialize COM with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before you call [PSCreateDelayedMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatedelayedmultiplexpropertystore). COM must remain initialized for the lifetime of this object.

Each of the objects in the array *prgpunkStores* must implement either [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage). If an object implements **IPropertySetStorage**, it is wrapped using [PSCreatePropertyStoreFromPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatepropertystorefrompropertysetstorage) for use in the multiplex property store.

The multiplex property store implementation of [IPropertyStore::GetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getvalue) asks each of the provided property stores for the value. The multiplex property store stops searching when one of the property stores returns a success code and a non-VT_EMPTY value. Failure codes cause the search to end and are passed back to the calling application.

The multiplex property store implementation of [IPropertyStoreCapabilities::IsPropertyWritable](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystorecapabilities-ispropertywritable) delegates the call to the first store that implements [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities). If multiple stores implement **IPropertyStoreCapabilities**, the subsequent ones are ignored. If no store implements **IPropertyStoreCapabilities**, this method returns **S_OK**.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSCreateMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatemultiplexpropertystore) in an implementation of [IPropertyStoreFactory::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystorefactory-getpropertystore).

```cpp
// CMyFactory is a reference counted COM object that implements
// both IPropertyStoreFactory.

// CMyFactory is assumed to be fully implemented, but for the sake of brevity,
// many functions are not shown here.

// Private functions are prefixed with an underscore.

// CMyFactory implementation for IPropertyStoreFactory::GetPropertyStore.
HRESULT CMyFactory::GetPropertyStore(__in GETPROPERTYSTOREFLAGS flags,
                                     __in_opt IUnknown *pUnkFactory,
                                     __in REFIID riid,
                                     __deref_out void **ppv)
{
    *ppv = NULL;
    HRESULT hr;

    // This application creates only read-only stores.
    if (flags & GPS_READWRITE)
    {
        hr = STG_E_ACCESSDENIED;
    }
    else
    {
        // More advanced applications would check other GETPROPERTYSTOREFLAGS
        // flags and respond appropriately.

        // CMyFactory multiplexes two property stores.
        IPropertyStore *ppsFirst;

        hr = _CreateFirstStore(IID_PPV_ARGS(&ppsFirst));

        if (SUCCEEDED(hr))
        {
            IPropertyStore *ppsSecond;

            hr = _CreateSecondStore(IID_PPV_ARGS(&ppsSecond));

            if (SUCCEEDED(hr))
            {
                IUnknown *rgStores[] = {ppsFirst, ppsSecond};

                hr = PSCreateMultiplexPropertyStore(rgStores, ARRAYSIZE(rgStores), riid, ppv);

                ppsSecond->Release();
            }
            ppsFirst->Release();
        }
    }
    return hr;
}
```

## See also

[IPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorefactory)

[PSCreateDelayedMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatedelayedmultiplexpropertystore)