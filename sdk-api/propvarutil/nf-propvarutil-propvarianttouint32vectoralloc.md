# PropVariantToUInt32VectorAlloc function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a newly-allocated **ULONG** vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pprgn` [out]

Type: **ULONG****

When this function returns, contains a pointer to a vector of **ULONG** values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of **ULONG** values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **E_INVALIDARG** | The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a vector of **ULONG** values.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_VECTOR** | **VT_UI4** or **VT_ARRAY** | **VT_UI4**, this function extracts a vector of **ULONG** values into a newly allocated vector. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the vector pointed to by *pprgn* when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt32VectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32vectoralloc) to access a **ULONG** vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid. The application is expecting propvar to contain a vector of ULONG values.
ULONG *prgLongs;
ULONG cElems;
HRESULT hr = PropVariantToUInt32VectorAlloc(propvar, &prgLongs, &cElems);
if (SUCCEEDED(hr))
{
     // prgLongs now points to a vector of cElems ULONG.
     CoTaskMemFree(prgLongs);
}
```

## See also

[InitPropVariantFromUInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint32vector)

[PropVariantGetUInt32Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetuint32elem)

[PropVariantToUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32)

[PropVariantToUInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32vector)

[VariantToUInt32Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint32array)