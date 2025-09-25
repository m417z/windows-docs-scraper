# PropVariantToGUID function

## Description

Extracts a GUID value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pguid` [out]

Type: **GUID***

When this function returns, contains the extracted property value if one exists.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function works for[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures of the following types:

* VT_GUID
* VT_BSTR
* VT_LPWSTR
* VT_ARRAY | VT_UI1

[PropVariantToGUID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoguid) is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a single **GUID** or **GUID** value. For instance, an application obtaining values from a property store can use this to safely extract the **GUID** value for **GUID** properties.

#### Examples

```cpp
// IPropertyStore *ppropstore;

// Assume variable ppropstore is initialized and valid

PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Sync_HandlerCollectionID, &propvar);

if (SUCCEEDED(hr))

{

        // PKEY_Sync_HandlerCollectionID is expected to produce a VT_CLSID or VT_EMPTY value.

        // PropVariantToGUID will convert VT_EMPTY to a failure code.

        GUID guidCollectionID;

        hr = PropVariantToGUID(propvar, &guidCollectionID);

        if (SUCCEEDED(hr))

        {

             // guidCollectionID is now valid

        }

        else

        {

            // the extraction failed

        }

        PropVariantClear(&propvar);

}
```

## See also

[InitPropVariantFromCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromclsid)

[PropVariantToCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoclsid)

[VariantToGUID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoguid)