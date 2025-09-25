# PropVariantToUInt64WithDefault function

## Description

Extracts **ULONGLONG** value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value exists, then the specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `ullDefault` [in]

Type: **ULONGLONG**

Specifies a default property value, for use where no value currently exists.

## Return value

Type: **ULONGLONG**

Returns the extracted unsigned **LONGLONG** value, or a default.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a **ULONGLONG** value and would like to use a default value if it does not. For instance, an application obtaining values from a property store can use this to safely extract the **ULONGLONG** value for **UInt64** properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_UI8**, this helper function extracts the **ULONGLONG** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **ULONGLONG**. If the source **PROPVARIANT** has type **VT_EMPTY** or a conversion is not possible, then [PropVariantToUInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64withdefault) will return the default provided by *ullDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToUInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttouint64withdefault) to access a **ULONGLONG** value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_Size, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_Size is expected to produce a VT_UI8 or VT_EMPTY value.
     // The application developer decided to treat VT_EMPTY or invalid values as 0
     ULONGLONG ullSize = PropVariantToUInt64WithDefault(propvar, 0);
     // ullSize is now valid.
     PropVariantClear(&propvar);
}
```