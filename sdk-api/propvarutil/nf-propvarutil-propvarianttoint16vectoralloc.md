# PropVariantToInt16VectorAlloc function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a newly allocated **Int16** vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pprgn` [out]

Type: **SHORT****

When this function returns, contains a pointer to a vector of **Int16** values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pcElem` [out]

Type: **ULONG***

 When this function returns, contains the count of **Int16** elements extracted from source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **E_INVALIDARG** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an **Int16** vector value.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_I2 or VT_ARRAY | VT_I2, this function extracts a vector of **Int16** values into a newly allocated vector of SHORT values. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the vector pointed to by *pprgn* when it is no longer needed.

#### Examples

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an Int16 vector value.

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid. The application is expecting propvar to contain a vector of Int16 values.
SHORT *prgShorts;
ULONG cElems;
HRESULT hr = PropVariantToBooleanVectorAlloc(propvar, & prgShorts, &cElems);
if (SUCCEEDED(hr))
{
     // prgShorts now points to a vector of cElems SHORTs.
     CoTaskMemFree(prgShorts);
}
```

## See also

[InitPropVariantFromInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16vector)

[PropVariantGetInt16Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetint16elem)

[PropVariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16)

[PropVariantToInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16vector)

[VariantToInt16Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint16array)