# InitPropVariantFromGUIDAsBuffer function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a **GUID**. The structure is initialized as VT_VECTOR | VT_UI1.

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

Creates a VT_VECTOR | VT_UI1 propvariant.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use **InitPropVariantFromGUIDAsBuffer**.

```cpp
PROPVARIANT propvar;

HRESULT hr = InitPropVariantFromGUIDAsBuffer(FMTID_DocSummaryInformation, &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_UI1.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromCLSID](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromclsid)

[InitPropVariantFromGUIDAsString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromguidasstring)

[InitVariantFromGUIDAsBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromguidasbuffer)

[PropVariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobuffer)