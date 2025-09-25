# PropVariantToInt64 function

## Description

Extracts a **LONGLONG** value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pllRet` [out]

Type: **LONGLONG***

When this function returns, contains the extracted property value if one exists; otherwise, 0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an **LONGLONG** value. For instance, an application obtaining values from a property store can use this to safely extract the **LONGLONG** value for Int64 properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_I8**, this helper function extracts the **LONGLONG** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **LONGLONG**. If a conversion is not possible, [PropVariantToInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64) will return a failure code and set *pllRet* to 0. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, **VT_EMPTY** is successfully converted to 0.

#### Examples

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
LONGLONG llValue; // The application is expecting propvar to hold a VT_I8 value
HRESULT hr = PropVariantToInt64(propvar, &llValue);
if (SUCCEEDED(hr))
{
     // llValue is valid
}
else
{
         // the extraction failed
}
```

## See also

[InitPropVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToInt64Vector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64vector)

[VariantToInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint64)