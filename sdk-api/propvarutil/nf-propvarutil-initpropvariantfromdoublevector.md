# InitPropVariantFromDoubleVector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure based on a specified vector of **double** values.

## Parameters

### `prgn` [in, optional]

Type: **const DOUBLE***

Pointer to a **double** vector. If this value is **NULL**, the elements pointed to by the **cadbl.pElems** structure member are initialized with 0.0.

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

Creates a VT_VECTOR | VT_R8 propvariant.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitPropVariantFromDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdoublevector).

```cpp
PROPVARIANT propvar;
DOUBLE rgDouble[] = {3.1415, 42.7};

HRESULT hr = InitPropVariantFromDoubleVector(rgDouble, ARRAYSIZE(rgDouble), &propvar);

if (SUCCEEDED(hr))
{
    // propvar now is valid and has type VT_VECTOR | VT_R8.

    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdouble)

[InitVariantFromDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdoublearray)

[PropVariantToDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublevector)