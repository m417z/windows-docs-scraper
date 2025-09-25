# InitVariantFromGUIDAsBuffer function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure based on a **GUID**. The structure is initialized as VT_ARRAY | VT_UI1.

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

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromGUIDAsBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromguidasbuffer).

```cpp
VARIANT var;

HRESULT hr = InitVariantFromGUIDAsBuffer(FMTID_DocSummaryInformation, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_ARRAY | VT_UI1.
    VariantClear(&var);
}
```

## See also

[InitPropVariantFromCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromclsid)

[InitVariantFromGUIDAsString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromguidasstring)

[VariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobuffer)