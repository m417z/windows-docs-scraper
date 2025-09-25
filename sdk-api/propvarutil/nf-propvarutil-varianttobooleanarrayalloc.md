# VariantToBooleanArrayAlloc function

## Description

Allocates an array of **BOOL** values then extracts data from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure into that array.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pprgf` [out]

Type: **BOOL****

When this function returns, contains a pointer to an array of **BOOL** values extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains a pointer to the count of elements extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold an array of **BOOL** values.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_ARRAY | VT_BOOL, this function extracts an array of **BOOL** values into a newly allocated array. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the array pointed to by *pprgf* when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToBooleanArrayAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanarrayalloc) to access an array of **BOOL** values stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

```cpp
// VARIANT var;
// Assume variable var is initialized and valid.
// The application expects var to contain an array of BOOL values.
BOOL *prgFlags;
ULONG cElems;

HRESULT hr = VariantToBooleanArrayAlloc(var, &prgFlags, &cElems);

if (SUCCEEDED(hr))
{
     // prgFlags now points to a vector of cElems BOOLs.
     CoTaskMemFree(prgFlags);
}
```

## See also

[InitVariantFromBooleanArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfrombooleanarray)

[PropVariantToBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanvector)

[VariantToBooleanArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanarray)