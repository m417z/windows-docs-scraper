# PropVariantToBooleanVectorAlloc function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a newly allocated Boolean vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pprgf` [out]

Type: **BOOL****

When this function returns, contains a pointer to a vector of Boolean values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of Boolean elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **E_INVALIDARG** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a Boolean vector value.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_BOOL or VT_ARRAY | VT_BOOL, this function extracts a vector of Boolean values into a newly allocated vector of **BOOL** values. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the vector pointed to by *pprgf* when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToBooleanVectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanvectoralloc) to access a Boolean vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid. The application is
// expecting propvar to contain a vector of Boolean values.
BOOL *prgFlags;
ULONG cFlags;
HRESULT hr = PropVariantToBooleanVectorAlloc(propvar, &prgFlags, &cFlags);

if (SUCCEEDED(hr))
{
     // The prgFlags variable now points to a vector that contains a count
     // of cFlags flags.
     CoTaskMemFree(prgFlags);
}
```

## See also

[InitPropVariantFromBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrombooleanvector)

[IsPropVariantVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-ispropvariantvector)

[PropVariantGetBooleanElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetbooleanelem)

[PropVariantToBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanvector)