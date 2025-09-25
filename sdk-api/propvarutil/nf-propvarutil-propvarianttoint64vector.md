# PropVariantToInt64Vector function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into an **Int64** vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgn` [out]

Type: **LONGLONG***

Points to a buffer containing *crgn* **LONGLONG** values. When this function returns, the buffer has been initialized with *pcElem* **LONGLONG** elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

### `crgn` [in]

Type: **ULONG**

Size of the buffer pointed to by *prgn* in elements.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of **LONGLONG** values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **TYPE_E_BUFFERTOOSMALL** | The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) contained more than *crgn* values. The buffer pointed to by *prgn*. |
| **E_INVALIDARG** | The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type |

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a vector of **LONGLONG** values with a fixed number of elements.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_VECTOR** | **VT_I8** or **VT_ARRAY** | **VT_I8**, this helper function extracts up to *crgn* **LONGLONG** values and places them into the buffer pointed to by *prgn*. If the **PROPVARIANT** contains more elements than will fit into the prgn buffer, this function returns an error and sets *pcElem* to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64vector) to access an Int64 vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
LONGLONG rgLongs[4]; // The application is expecting propvar to hold 4 LONGLONGs in a vector
ULONG cElems;
HRESULT hr = PropVariantToInt64Vector(propvar, rgLongs, ARRAYSIZE(rgLongs), &cElems);
if (SUCCEEDED(hr))
{
     if (cElems == ARRAYSIZE(rgLongs))
     {
         // The application got 4 LONGLONGs which are now stored in rgLongs
     }
     else
     {
         // The application got cElems which are stored in the first cElems elements of rgLongs
     }
}
```

## See also

[InitPropVariantFromInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64vector)

[PropVariantGetInt64Elem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetint64elem)

[PropVariantToInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64)

[PropVariantToInt64VectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64vectoralloc)

[VariantToInt64Array](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint64array)