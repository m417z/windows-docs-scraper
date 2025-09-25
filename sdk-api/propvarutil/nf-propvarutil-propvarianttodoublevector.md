# PropVariantToDoubleVector function

## Description

Extracts a vector of doubles from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `prgn` [out]

Type: **DOUBLE***

Points to a buffer containing *crgn* DOUBLE values. When this function returns, the buffer has been initialized with *pcElem* double elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `crgn` [in]

Type: **ULONG**

Size in elements of the buffer pointed to by *prgn*.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of double elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a double vector value with a fixed number of elements.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_R8 or VT_ARRAY | VT_R8, this helper function extracts up to *crgn* double values and places them into the buffer pointed to by *prgn*. If the **PROPVARIANT** contains more elements than will fit into the *prgn* buffer, this function returns an error and sets *pcElem* to 0.

#### Examples

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_GPS_DestLongitude, &propvar);
if (SUCCEEDED(hr))
{
         // PKEY_GPS_DestLongitude is expected to produce a VT_VECTOR | VT_R8 with three values, or VT_EMPTY
         // PropVariantToDoubleVector will return an error for VT_EMPTY
         DOUBLE rgLongitude[3];
         ULONG cElem;
         hr = PropVariantToDoubleVector(propvar, &rgLongitude, ARRAYSIZE(rgLongitude), &cElem);
         if (SUCCEEDED(hr))
         {
                 if (cElem == ARRAYSIZE(rgLongitude))
                 {
                          // rgLongitude contains 3 doubles representing the degrees, minutes, and seconds of longitude
                 }
                 else
                 {
                          // The first cElem doubles from propvar are stored in the first 3 elements of rgLongitude
         }
         else
         {
                 // propvar either is VT_EMPTY, or contains something other than a vector of 3 doubles
         }
         PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdoublevector)

[PropVariantGetDoubleElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetdoubleelem)

[PropVariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodouble)

[PropVariantToDoubleVectorAlloc](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublevectoralloc)

[VariantToDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearray)