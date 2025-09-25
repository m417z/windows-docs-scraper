# InitPropVariantFromBooleanVector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure from a specified Boolean vector.

## Parameters

### `prgf` [in, optional]

Type: **const BOOL***

Pointer to the Boolean vector used to initialize the structure. If this parameter is **NULL**, the elements pointed to by the **cabool.pElems** structure member are initialized with VARIANT_FALSE.

### `cElems` [in]

Type: **ULONG**

The number of vector elements.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This creates a **VT_BOOL** | **VT_VECTOR** propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrombooleanvector)

```cpp
PROPVARIANT propvar;
BOOL rgBool[2] = {TRUE, FALSE};

HRESULT hr = InitPropVariantFromBooleanVector(rgBool, ARRAYSIZE(rgBool), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_BOOL.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromboolean)

[InitVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromboolean)

[PropVariantToBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanvector)