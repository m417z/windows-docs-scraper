# PropVariantToDoubleVectorAlloc function

## Description

Extracts data from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure into a newly-allocated double vector.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pprgn` [out]

Type: **DOUBLE****

When this function returns, contains a pointer to a vector of double values extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pcElem` [out]

Type: **ULONG***

When this function returns, contains the count of double elements extracted from the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a double vector value.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_R8 or VT_ARRAY | VT_R8, this function extracts a vector of double values into a newly allocated vector of DOUBLE values. The calling application is responsible for using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the vector pointed to by *pprgn* when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublevector) to access a double vector value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_GPS_DestLongitude, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_GPS_DestLongitude is expected to produce a VT_VECTOR | VT_R8 with three values, or VT_EMPTY
     // PropVariantToDoubleVectorAlloc will return an error for VT_EMPTY
     DOUBLE *rgLongitude;
     ULONG cElem;
     hr = PropVariantToDoubleVectorAlloc(propvar, &rgLongitude, &cElem);
     if (SUCCEEDED(hr))
     {
         if (cElem == 3)
         {
              // rgLongitude contains 3 doubles representing the degrees, minutes, and seconds of longitude
         }
         CoTaskMemFree(rgLongitude);
     }
     else
     {
          // propvar either is VT_EMPTY, or contains something other than a vector of  doubles
     }
     PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdoublevector)

[PropVariantGetDoubleElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetdoubleelem)

[PropVariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodouble)

[PropVariantToDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublevector)

[VariantToDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearray)