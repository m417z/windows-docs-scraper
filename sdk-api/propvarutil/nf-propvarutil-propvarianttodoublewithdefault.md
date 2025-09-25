# PropVariantToDoubleWithDefault function

## Description

Extracts a double property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value exists, then the specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `dblDefault` [in]

Type: **DOUBLE**

Specifies default property value, for use where no value currently exists.

## Return value

Type: **DOUBLE**

Returns extracted **double** value, or default.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a double value and would like to use a default value if it does not. For instance, an application obtaining values from a property store can use this to safely extract the double value for double properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_R8**, this helper function extracts the double value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a double. If the source **PROPVARIANT** has type **VT_EMPTY** or a conversion is not possible, then [PropVariantToDoubleWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublewithdefault) will return the default provided by *dblDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_Image_HorizontalResolution, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_Image_HorizontalResolution is expected to produce a VT_R8 or VT_EMPTY value.
     // The application developer decided to treat VT_EMPTY or invalid values as 72.0
     DOUBLE dblResolution = PropVariantToDoubleWithDefault(propvar, 72.0);
     // dblResolution is now valid.
     PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromdouble)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToDoubleVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodoublevector)

[VariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodouble)