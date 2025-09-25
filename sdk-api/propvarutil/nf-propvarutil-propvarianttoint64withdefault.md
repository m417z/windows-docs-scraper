# PropVariantToInt64WithDefault function

## Description

Extracts the **Int64** property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value exists, then specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `llDefault` [in]

Type: **LONGLONG**

Specifies a default property value, for use where no value currently exists.

## Return value

Type: **LONGLONG**

Returns the extracted **LONGLONG** value, or default.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a **LONGLONG** value and would like to use a default value if it does not. For instance, an application obtaining values from a property store can use this to safely extract the **LONGLONG** value for Int64 properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_I8**, this helper function extracts the **LONGLONG** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **LONGLONG**. If the source **PROPVARIANT** has type **VT_EMPTY** or a conversion is not possible, then [PropVariantToInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64withdefault) will return the default provided by *llDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PropVariantToInt64WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64withdefault) to access a **LONGLONG** value in a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

```cpp
// PROPVARIANT propvar;
// Assume the variable propvar is initialized and valid
// The application is expecting propvar to hold a VT_I8 value, but wishes to treat VT_EMPTY as -1.
LONGLONG llValue = PropVariantToInt64WithDefault(propvar, -1);
// llValue is valid
```

## See also

[InitPropVariantFromInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint64)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint64)

[VariantToInt64](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint64)