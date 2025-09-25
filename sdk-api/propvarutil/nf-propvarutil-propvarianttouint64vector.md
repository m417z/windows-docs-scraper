# PropVariantToUInt64Vector function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a **ULONGLONG** vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgn` [out]

Type: **ULONGLONG***

Points to a buffer containing *crgn* **ULONGLONG** values. When this function returns, the buffer has been initialized with *pcElem* **ULONGLONG** elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

### `crgn` [in]

Type: **ULONG**

Size of the buffer pointed to by *prgn*, in elements.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of **ULONGLONG** values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **TYPE_E_BUFFERTOOSMALL** | The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) contained more than *crgn* values. The buffer pointed to by *prgn*. |
| **E_INVALIDARG** | The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a vector of **ULONGLONG** values with a fixed number of elements.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_VECTOR** | **VT_UI8** or **VT_ARRAY** | **VT_UI8**, this helper function extracts up to *crgn* **ULONGLONG** values and places them into the buffer pointed to by *prgn*. If the **PROPVARIANT** contains more elements than will fit into the *prgn* buffer, this function returns an error and sets *pcElem* to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64vector) to access a **ULONGLONG** vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
ULONGLONG rgLongs[4]; // The application is expecting propvar to hold 4 ULONGLONGs in a vector
ULONG cElems;
HRESULT hr = PropVariantToUInt64Vector(propvar, rgLongs, ARRAYSIZE(rgLongs), &cElems);
if (SUCCEEDED(hr))
{
     if (cElems == ARRAYSIZE(rgLongs))
     {
         // The application got 4 ULONGLONGs which are now stored in rgLongs
     }
     else
     {
         // The application got cElems which are stored in the first cElems elements of rgLongs
     }
}
```

## See also

[InitPropVariantFromUInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint64vector)

[PropVariantGetUInt64Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetuint64elem)

[PropVariantToUInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64)

[PropVariantToUInt64VectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64vectoralloc)

[VariantToUInt64Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint64array)