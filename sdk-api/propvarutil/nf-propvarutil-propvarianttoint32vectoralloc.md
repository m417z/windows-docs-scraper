# PropVariantToInt32VectorAlloc function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a newly-allocated **Int32** vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pprgn` [out]

Type: **LONG****

When this function returns, contains a pointer to a vector of **LONG** values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of **LONG** elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **E_INVALIDARG** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an Int32 vector value.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_VECTOR** | **VT_I4** or **VT_ARRAY** | **VT_I4**, this function extracts a vector of **LONG** values into a newly allocated vector. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the vector pointed to by *pprgn* when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToInt32VectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32vectoralloc) to access an **LONG** vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid. The application is expecting propvar to contain a vector of LONG values.
LONG *prgLongs;
ULONG cElems;
HRESULT hr = PropVariantToInt32VectorAlloc(propvar, &prgLongs, &cElems);
if (SUCCEEDED(hr))
{
     // prgLongs now points to a vector of cElems LONGs.
     CoTaskMemFree(prgLongs);
}
```

## See also

[InitPropVariantFromInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32vector)

[PropVariantGetInt32Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetint32elem)

[PropVariantToInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32)

[PropVariantToInt32Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32vector)

[VariantToInt32Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint32array)