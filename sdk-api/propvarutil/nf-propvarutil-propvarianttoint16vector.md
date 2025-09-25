# PropVariantToInt16Vector function

## Description

Extracts a vector of **Int16** values from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgn` [out]

Type: **SHORT***

 Points to a buffer containing *crgn* SHORT values. When this function returns, the buffer has been initialized with *pcElem* SHORT elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `crgn` [in]

Type: **ULONG**

Size of the buffer pointed to by *prgn* in elements.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of **Int16** elements extracted from source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **TYPE_E_BUFFERTOOSMALL** | The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) contained more than *crgn* values. The buffer pointed to by *prgn*. |
| **E_INVALIDARG** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an **Int16** vector value with a fixed number of elements.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_I2 or VT_ARRAY | VT_I2, this helper function extracts up to *crgn* Int16 values and places them into the buffer pointed to by *prgn*. If the **PROPVARIANT** contains more elements than will fit into the *prgn* buffer, this function returns an error and sets *pcElem* to 0.

#### Examples

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
SHORT rgShorts[4]; // The application is expecting propvar to hold 4 Int16s in a vector
ULONG cElems;
HRESULT hr = PropVariantToInt16Vector(propvar, rgShorts, ARRAYSIZE(rgShorts), &cElems);
if (SUCCEEDED(hr))
{
     if (cElems == ARRAYSIZE(rgShorts))
     {
         // The application got 4 Int16s which are now stored in rgShorts
     }
     else
     {
         // The application got cElems which are stored in the first cElems elements of rgShorts
     }
}
```

## See also

[InitPropVariantFromInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16vector)

[PropVariantGetInt16Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetint16elem)

[PropVariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16)

[PropVariantToInt16VectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16vectoralloc)

[VariantToInt16Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint16array)