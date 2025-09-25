# InitVariantFromStrRet function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a string stored in a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure.

## Parameters

### `pstrret` [in]

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)***

Pointer to a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

PIDL of the item whose details are being retrieved.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_BSTR variant.

**Note** This function frees the resources used for the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) contents.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromStrRet](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstrret).

```cpp
// STRRET strret;
// PCUITEMID_CHILD pidl;
// Assume variables strret and pidl are initialized and valid.
VARIANT var;

HRESULT hr = InitVariantFromStrRet(strret, pidl, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_BSTR.
    VariantClear(&var);
}
```

## See also

[InitVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstring)

[VariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostring)

[VariantToStringWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttostringwithdefault)