# StgCreatePropSetStg function

## Description

The **StgCreatePropSetStg** function creates a property set storage object from a specified storage object. The property set storage object supplies the system-provided, stand-alone implementation of the
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface.

## Parameters

### `pStorage` [in]

A pointer to the storage object that contains or will contain one or more property sets.

### `dwReserved`

Reserved for future use; must be zero.

### `ppPropSetStg` [out]

A pointer to
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)* pointer variable that receives the interface pointer to the property-set storage object.

## Return value

This function supports the standard return value **E_INVALIDARG** as well as the following:

## Remarks

The
**StgCreatePropSetStg** function creates an
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface that will act on the given
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface specified by the *pStorage* parameter. This function does not modify this
**IStorage** by itself, although subsequent calls to the
**IPropertySetStorage** interface might.

**StgCreatePropSetStg** calls [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the storage object specified by *pStorage*. The caller must release the object when it is no longer required by calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

#### Examples

The following example code shows how this function creates a property set within a storage object.

```cpp
IPropertyStorage*
CreatePropertySetInStorage( IStorage *pStg, const FMTID &fmtid )
{
    HRESULT hr = S_OK;
    IPropertySetStorage *pPropSetStg = NULL;
    IPropertyStorage *pPropStg = NULL;

    try
    {
        hr = StgCreatePropSetStg( pStg, 0, &pPropSetStg );
        if( FAILED(hr) ) throw L"Failed StgCreatePropSetStg (%08x)";

        hr = pPropSetStg->Create( fmtid, NULL,
            PROPSETFLAG_DEFAULT,
            STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE,
            &pPropStg );
        if( FAILED(hr) )
            throw L"Failed IPropertySetStorage::Create (%08x)";

        // Success. The caller must now call Release on both
        // pPropSetStg and pStg.

    }
    catch( const WCHAR *pwszError )
    {
        wprintf( L"Error: %s (%08x)\n", pwszError, hr );
    }

    if( NULL != pPropSetStg )
        pPropSetStg->Release();

    return( pPropStg );
}
```

## See also

[IPropertySetStorage-Stand-alone Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-stand-alone-implementation)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)

[StgCreatePropSetStg Sample](https://learn.microsoft.com/windows/desktop/Stg/stgcreatepropsetstg-sample)