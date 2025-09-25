# InitPropVariantFromGUIDAsString function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a **GUID**. The structure is initialized as VT_LPWSTR.

## Parameters

### `guid` [in]

Type: **REFGUID**

Reference to the source **GUID**.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_LPWSTR [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant), which formats the GUID in a form similar to `{c200e360-38c5-11ce-ae62-08002b2b79ef}`.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use **InitPropVariantFromGUIDAsString**.

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromGUIDAsString(FMTID_DocSummaryInformation, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_LPWSTR.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromclsid)

[InitPropVariantFromGUIDAsBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromguidasbuffer)

[InitVariantFromGUIDAsString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromguidasstring)

[PropVariantToString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostring)