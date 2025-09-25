# PropVariantToCLSID function

## Description

Extracts class identifier (CLSID) property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pclsid` [out]

Type: **CLSID***

When this function returns, contains the extracted property value if one exists.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function works for[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures of the following types:

* VT_CLSID
* VT_BSTR
* VT_LPWSTR
* VT_ARRAY | VT_UI1

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

[PropVariantToCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoclsid) is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a single CLSID or GUID value. For instance, an application obtaining values from a property store can use this to safely extract the CLSID value for GUID properties.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoclsid) to access a CLSID value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};

HRESULT hr = ppropstore->GetValue(PKEY_Sync_HandlerCollectionID, &propvar);
if (SUCCEEDED(hr))
{
        // PKEY_Sync_HandlerCollectionID is expected to produce a VT_CLSID or VT_EMPTY value.
        // PropVariantToCLSID will convert VT_EMPTY to a failure code.
        CLSID clsidCollectionID;

        hr = PropVariantToCLSID(propvar, &clsidCollectionID);
        if (SUCCEEDED(hr))
        {
             // clsidCollectionID is now valid
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

[PropVariantToGUID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoguid)

[VariantToGUID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoguid)