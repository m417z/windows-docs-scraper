# VariantToDoubleArray function

## Description

Extracts an array of **DOUBLE** values from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `prgn` [out]

Type: **DOUBLE***

Pointer to a buffer that contains *crgn* **DOUBLE** values. When this function returns, the buffer has been initialized with **pcElem* **DOUBLE** elements extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `crgn` [in]

Type: **ULONG**

The number of elements in the buffer pointed to by *prgn*.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of **DOUBLE** elements extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **TYPE_E_BUFFERTOOSMALL** | The source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) contained more than *crgn* values. |
| **E_INVALIDARG** | The [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) was not of the appropriate type. |

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold an array that consists of a fixed number of **DOUBLE** values.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) has type VT_ARRAY | VT_DOUBLE, this function extracts up to *crgn* **DOUBLE** values and places them into the buffer pointed to by *prgn*.

If the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) contains more elements than will fit into the *prgn* buffer, this function returns an error and sets **pcElem* to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearray) to access a **DOUBLE** array stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant).

```cpp
// VARIANT var;
// Assume variable var is initialized and valid.
DOUBLE rgDoubles[4]; // The application expects var to hold 4 DOUBLEs in an array.
ULONG cDoubles;

HRESULT hr = VariantToDoubleArray(var, rgDoubles, ARRAYSIZE(rgDoubles), &cFlags);

if (SUCCEEDED(hr))
{
    if (cFlags == ARRAYSIZE(rgDoubles))
    {
        // The application got 4 DOUBLEs which are now stored in rgDoubles.
    }
    else
    {
        // The application got *pcElem DOUBLEs which are stored in the first
        // *pcElem elements of rgDoubles.
    }
}
```

## See also

[InitVariantFromDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdoublearray)

[PropVariantToDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublevector)

[VariantGetDoubleElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-variantgetdoubleelem)

[VariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodouble)

[VariantToDoubleArrayAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearrayalloc)