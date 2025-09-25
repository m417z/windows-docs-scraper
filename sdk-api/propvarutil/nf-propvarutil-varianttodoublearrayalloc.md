# VariantToDoubleArrayAlloc function

## Description

Allocates an array of **DOUBLE** values then extracts data from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure into that array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pprgn` [out]

Type: **DOUBLE****

When this function returns, contains a pointer to an array of **DOUBLE** values extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains a pointer to the count of elements extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold an array of **DOUBLE** values.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_ARRAY | VT_R8, this function extracts an array of **DOUBLE** values into a newly allocated array. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the array pointed to by *pprgn* when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToDoubleArrayAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearrayalloc) to access a **DOUBLE** array value in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant).

```cpp
// VARIANT var;
// Assume variable var is initialized and valid.
// The application expects var to contain an array of DOUBLE values.
DOUBLE *prgDoubles;
ULONG cElems;

HRESULT hr = VariantToDoubleArrayAlloc(var, &prgDoubles, &cElems);

if (SUCCEEDED(hr))
{
     // prgDoubles now points to a vector of cElems DOUBLEs.
     CoTaskMemFree(prgDoubles);
}
```

## See also

[InitVariantFromDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdoublearray)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToDoubleVectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublevectoralloc)

[VariantToDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearray)