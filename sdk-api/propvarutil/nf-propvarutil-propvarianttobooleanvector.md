# PropVariantToBooleanVector function

## Description

Extracts a Boolean vector from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgf` [out]

Type: **BOOL***

Points to a buffer that contains *crgf* **BOOL** values. When this function returns, the buffer has been initialized with *pcElem* Boolean elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `crgf` [in]

Type: **ULONG**

Number of elements in the buffer pointed to by *prgf*.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of Boolean elements extracted from source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Returns **S_OK** if successful, or an error value otherwise. |
| **TYPE_E_BUFFERTOOSMALL** | The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) contained more than *crgf* values. The buffer pointed to by *prgf*. |
| **E_INVALIDARG** | The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was not of the appropriate type. |

## Remarks

This helper function is used when the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a Boolean vector value with a fixed number of elements.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_BOOL or VT_ARRAY | VT_BOOL, this helper function extracts up to *crgf* Boolean values and places them into the buffer pointed to by *prgf*. If the **PROPVARIANT** contains more elements than will fit into the *prgf* buffer, this function returns an error and sets *pcElem* to 0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToBooleanVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobooleanvector) to access a Boolean vector stored in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid.

// The application is expecting the propvar variable to hold 4 Booleans
// in a vector.
BOOL rgFlags[4];
ULONG cFlags;
HRESULT hr = PropVariantToBooleanVector(propvar, rgFlags, ARRAYSIZE(rgFlags), &cFlags);

if (SUCCEEDED(hr))
{
     if (cFlags == ARRAYSIZE(rgFlags))
     {
         // The application received 4 flags which are now stored in rgFlags.
     }
     else
     {
         // The application received cFlags flags which are now stored in the
         // first cFlags elements of rgFlags.
     }
}
```