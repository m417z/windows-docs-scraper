# PropVariantToDouble function

## Description

Extracts double value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pdblRet` [out]

Type: **DOUBLE***

When this function returns, contains the extracted property value if one exists; otherwise, contains 0.0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a single double floating point value. For instance, an application obtaining values from a property store can use this to safely extract a double value for double properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_R8**, this helper function extracts the double value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a double. If a conversion is not possible, [PropVariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodouble) will return a failure code and set *pdblRet* to 0.0. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to 0.0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use PropVariantToDouble to access a double value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_Image_HorizontalResolution, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_Image_HorizontalResolution is expected to produce a VT_R8 or VT_EMPTY value.
     // PropVariantToDouble will successfully convert VT_EMPTY to a 0.0.
     DOUBLE dblHorzResolution;
     hr = PropVariantToDouble(propvar, &dblHorzResolution);
     if (SUCCEEDED(hr))
     {
        // dblHorzResolution is now valid
     }
     else
     {
        // dblHorzResolution contains 0.0
     }
     PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdouble)

[PropVariantGetDoubleElem](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantgetdoubleelem)

[PropVariantToDoubleWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublewithdefault)

[VariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodouble)