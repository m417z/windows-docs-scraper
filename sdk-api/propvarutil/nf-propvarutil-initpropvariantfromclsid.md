# InitPropVariantFromCLSID function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a class identifier (CLSID).

## Parameters

### `clsid` [in]

Type: **REFCLSID**

Reference to the CLSID.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a VT_CLSID propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromclsid).

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromCLSID(CLSID_PropertySystem, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_CLSID.

    PropVariantClear(&propvar);
}
```

## See also

[InitVariantFromGUIDAsBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromguidasbuffer)

[InitVariantFromGUIDAsString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromguidasstring)

[PropVariantToCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoclsid)