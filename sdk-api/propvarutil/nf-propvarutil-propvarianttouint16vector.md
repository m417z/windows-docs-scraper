# PropVariantToUInt16Vector function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into an **unsigned short** vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgn` [out]

Type: **USHORT***

Points to a buffer containing *crgn* **unsigned short** values. When this function returns, the buffer has been initialized with *pcElem* **unsigned short** elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

### `crgn` [in]

Type: **ULONG**

Size of the buffer pointed to by *prgn* in elements.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of **unsigned short** values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **TYPE_E_BUFFERTOOSMALL** | The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) contained more than *crgn* values. The buffer pointed to by *prgn*. |
| **E_INVALIDARG** | The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a vector of **unsigned short** values with a fixed number of elements.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_VECTOR** | **VT_UI2** or **VT_ARRAY** | **VT_UI2**, this helper function extracts up to *crgn* **unsigned short** values and places them into the buffer pointed to by *prgn*. If the **PROPVARIANT** contains more elements than will fit into the prgn buffer, this function returns an error and sets *pcElem* to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint16vector) to access an **unsigned short** vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
USHORT rgShorts[4]; // The application is expecting propvar to hold 4 USHORTs in a vector
ULONG cElems;
HRESULT hr = PropVariantToUInt16Vector(propvar, rgShorts, ARRAYSIZE(rgShorts), &cElems);
if (SUCCEEDED(hr))
{
     if (cElems == ARRAYSIZE(rgShorts))
     {
         // The application got 4 USHORTs which are now stored in rgShorts
     }
     else
     {
         // The application got cElems which are stored in the first cElems elements of rgShorts
     }
}
```

## See also

[InitPropVariantFromUInt16Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint16vector)

[PropVariantGetUInt16Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetuint16elem)

[PropVariantToUInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint16)

[PropVariantToUInt16VectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint16vectoralloc)

[VariantToUInt16Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint16array)