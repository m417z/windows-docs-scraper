# PSCreateDelayedMultiplexPropertyStore function

## Description

Creates a read-only, delayed-binding property store that contains multiple property stores.

## Parameters

### `flags`

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

One or more [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) values. These values specify details of the created property store object.

### `pdpsf`

Type: **[IDelayedPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-idelayedpropertystorefactory)***

Interface pointer to an instance of [IDelayedPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-idelayedpropertystorefactory).

### `rgStoreIds` [in]

Type: **const DWORD***

Pointer to an array of property store IDs. This array does not need to be initialized.

### `cStores` [in]

Type: **DWORD**

The number of elements in the array pointed to by *rgStoreIds*.

### `riid` [in]

Type: **REFIID**

Reference to the requested IID of the interface that will represent the created property store.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a Component Object Model (COM) object that implements [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore),
[INamedPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-inamedpropertystore), [IObjectProvider](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iobjectprovider), and [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities).

Applications must call this object from only one thread at a time.

You must initialize COM with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before you call [PSCreateDelayedMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatedelayedmultiplexpropertystore). COM must remain initialized for the lifetime of this object.

[PSCreateDelayedMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatedelayedmultiplexpropertystore) is designed as an alternative to [PSCreateMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatemultiplexpropertystore), which requires that the array of property stores be initialized before it creates the multiplex property store.

The delayed binding mechanism is designed as a performance enhancement for calls to [IPropertyStore::GetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getvalue) on a multiplex property store. When asked for the value of a property, the delayed multiplex property store checks each of the property stores for the value. After the value is found, there is no need to create and initialize subsequent stores. The delayed multiplex property store stops searching for a value when one of the property stores returns a success code and a non-VT_EMPTY value.

When the delayed multiplex property store needs to access a particular property store, it first checks to see if it has already obtained an interface to that property store. If not, it calls [IDelayedPropertyStoreFactory::GetDelayedPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-idelayedpropertystorefactory-getdelayedpropertystore) with the appropriate property store ID to obtain the property store. It always uses the property store IDs in the order in which they are provided by the application. It is possible that not all IDs will be used.

If the call to [IDelayedPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-idelayedpropertystorefactory) fails with E_NOTIMPL or E_ACCESSDENIED for a particular property store ID, or if the application specified [GPS_BESTEFFORT](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags), then the failure is ignored and the delayed multiplex property store moves on to the next property store.

In some cases, it might be beneficial to use [PSCreateDelayedMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatedelayedmultiplexpropertystore) in place of [PSCreateMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatemultiplexpropertystore). For example, if an application needs to multiplex two property stores and the first property store is not memory-intensive to initialize and provides PKEY_Size information. Often, calling applications ask for a multiplex property store and then ask for only PKEY_Size before they release the object. In such a case, the application could avoid the cost of initializing the second property store by calling **PSCreateDelayedMultiplexPropertyStore** and implementing [IDelayedPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-idelayedpropertystorefactory).

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSCreateDelayedMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatedelayedmultiplexpropertystore) in an implementation of [IPropertyStoreFactory::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystorefactory-getpropertystore).

```cpp
// CMyFactory is a reference-counted COM object that implements both IPropertyStoreFactory and IDelayedPropertyStoreFactory.

// CMyFactory is assumed to be fully implemented, but for the sake of brevity,
// many functions are not shown here.

// Private functions are indicated with an underscore prefix.

// The hope is that the fastest property store satisfies the caller's queries
// so that the slower property stores are never created.

// CMyFactory implementation for IPropertyStoreFactory::GetPropertyStore
HRESULT CMyFactory::GetPropertyStore( __in GETPROPERTYSTOREFLAGS flags,
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

        // This application always creates its stores in-process, so it
        // ignores the pUnkFactory value.

        DWORD rgStoreIds[] = {0, 1, 2};

        hr = PSCreateDelayedMultiplexPropertyStore(flags, this, rgStoreIds, ARRAYSIZE(rgStoreIds), riid, ppv);
    }

    return hr;
}

// CMyFactory implementation of IDelayedPropertyStoreFactory::GetDelayedPropertyStore
HRESULT CMyFactory::GetDelayedPropertyStore(GETPROPERTYSTOREFLAGS flags,
                                            DWORD dwStoreId,
                                            REFIID riid,
                                            void **ppv)
{
    *ppv = NULL;
    HRESULT hr;

    // Note: The IDs here match the IDs in rgStoreIds above.

    if (dwStoreId == 0)
    {
        // This store is the fastest at returning properties.

        hr = _CreateFastestPropertyStore(flags, riid, ppv);
    }
    else if (dwStoreId == 1)
    {
        // This store is slower at returning properties.
        hr = _CreateSlowerPropertyStore(flags, riid, ppv);
    }
    else if (dwStoreId == 2)
    {
        // This store is very slow at returning properties.
        hr = _CreateSlowestPropertyStore(flags, riid, ppv);
    }
    else
    {
        // This should never happen.
        hr = E_UNEXPECTED;
    }

    return hr;
}
```

## See also

[IPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorefactory)

[PSCreateMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatemultiplexpropertystore)