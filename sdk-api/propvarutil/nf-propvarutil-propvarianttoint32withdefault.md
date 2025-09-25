# PropVariantToInt32WithDefault function

## Description

Extracts an **Int32** value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value currently exists, then the specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `lDefault` [in]

Type: **LONG**

Specifies a default property value, for use where no value currently exists.

## Return value

Type: **LONG**

Returns extracted **LONG** value, or default.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a **LONG** value and would like to use a default value if it does not. For instance, an application obtaining values from a property store can use this to safely extract the **LONG** value for **Int32** properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_I4**, this helper function extracts the **LONG** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **LONG**. If the source **PROPVARIANT** has type **VT_EMPTY** or a conversion is not possible, then [PropVariantToInt32WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32withdefault) will return the default provided by *lDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToInt32WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32withdefault) to access a **LONG** value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_FlagStatus, &propvar);
if (SUCCEEDED(hr))
{
     // PKEY_FlagStatus is expected to produce a VT_I4 or VT_EMPTY value.
     // The application developer decided to treat VT_EMPTY or invalid values as 0
     LONG iStatus = PropVariantToInt32WithDefault(propvar, 0);
     // iStatus is now valid.
     PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint32)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint32)

[VariantToInt32](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint32)