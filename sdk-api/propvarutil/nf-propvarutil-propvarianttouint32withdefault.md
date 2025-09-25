# PropVariantToUInt32WithDefault function

## Description

Extracts a **ULONG** value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value exists, then a specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `ulDefault` [in]

Type: **ULONG**

Specifies a default property value, for use where no value currently exists.

## Return value

Type: **ULONG**

Returns extracted **ULONG** value, or default.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a **ULONG** value and would like to use a default value if it does not. For instance, an application obtaining values from a property store can use this to safely extract the **ULONG** value for **UInt32** properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_UI4**, this helper function extracts the **ULONG** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **ULONG**. If the source **PROPVARIANT** has type **VT_EMPTY** or a conversion is not possible, then [PropVariantToUInt32WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32withdefault) will return the default provided by *ulDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt32WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32withdefault) to access a **ULONG** value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_Rating, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_Rating is expected to produce a VT_UI4 or VT_EMPTY value.
     // The application developer decided to treat VT_EMPTY or invalid values as 0
     ULONG uRating = PropVariantToUInt32WithDefault(propvar, 0);
     // uRating is now valid.
     PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromuint32)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint32)

[VariantToUInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttouint32)