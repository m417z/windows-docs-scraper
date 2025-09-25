# InitVariantFromGUIDAsString function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure based on a **GUID**. The structure is initialized as a **VT_BSTR** type.

## Parameters

### `guid` [in]

Type: **REFGUID**

Reference to the source **GUID**.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_BSTR variant, formatting the GUID in a form similar to `{c200e360-38c5-11ce-ae62-08002b2b79ef}`.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use **InitVariantFromGUIDAsString**.

```cpp
VARIANT var;

HRESULT hr = InitVariantFromGUIDAsString(FMTID_DocSummaryInformation, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_BSTR.
    VariantClear(&var);
}
```

## See also

[InitPropVariantFromCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromclsid)

[InitVariantFromGUIDAsBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromguidasbuffer)

[VariantToGUID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoguid)

[VariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostring)