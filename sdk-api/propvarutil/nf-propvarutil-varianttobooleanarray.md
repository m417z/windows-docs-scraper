# VariantToBooleanArray function

## Description

Extracts an array of Boolean values from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Parameters

### `var` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `prgf` [out]

Type: **BOOL***

Pointer to a buffer that contains *crgn* Boolean values. When this function returns, the buffer has been initialized with **pcElem* **BOOL** elements extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `crgn` [in]

Type: **ULONG**

The number of elements in the buffer pointed to by *prgf*.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains a pointer to the count of **BOOL** elements extracted from the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **TYPE_E_BUFFERTOOSMALL** | The source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) contained more than *crgn* values. |
| **E_INVALIDARG** | The [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) was not of the appropriate type. |

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold an array that consists of a fixed number of Boolean values.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_ARRAY | VT_BOOL, this function extracts up to *crgn* **BOOL** values and places them into the buffer pointed to by *prgf*. If the **VARIANT** contains more elements than will fit into the *prgf* buffer, this function returns an error and sets **pcElem* to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToBooleanArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanarray) to access an array of **BOOL** values stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

```cpp
// VARIANT var;
// Assume variable var is initialized and valid
BOOL rgFlags[4]; // The application is expecting var to hold 4 BOOLs in an array.
ULONG cFlags;

HRESULT hr = VariantToBooleanArray(var, rgFlags, ARRAYSIZE(rgFlags), &cFlags);

if (SUCCEEDED(hr))
{
    if (cFlags == ARRAYSIZE(rgFlags))
    {
        // The application got 4 flag values which are now stored in rgFlags.
    }
    else
    {
        // The application got cFlags which are stored in the first cFlags
        // elements of rgFlags.
    }
}
```

## See also

[InitVariantFromBooleanArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfrombooleanarray)

[PropVariantToBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanvector)

[VariantGetBooleanElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-variantgetbooleanelem)

[VariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoboolean)

[VariantToBooleanArrayAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanarrayalloc)