# VariantToDoubleWithDefault function

## Description

Extracts a **DOUBLE** value from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure. If no value exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `dblDefault` [in]

Type: **DOUBLE**

The default value for use where no extractable value exists.

## Return value

Type: **DOUBLE**

Returns the extracted **double** value; otherwise, the default value specified in *dblDefault*.

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold a **DOUBLE** value and wants to use a default value if it does not.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_R8, this helper extracts the **DOUBLE** value.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is not of type VT_R8, the function attempts to convert the value in the **VARIANT** into a **DOUBLE**.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_EMPTY or a conversion is not possible, then [VariantToDoubleWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublewithdefault) returns the default value provided by *dblDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToDoubleWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublewithdefault) to access a **DOUBLE** value stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

```cpp
// VARIANT var;
// Assume variable var is initialized and valid.
// The application expects var to hold a DOUBLE value.

// The application wants to treat VT_EMPTY as 3.1415.
DOUBLE dblValue = VariantToDoubleWithDefault(var, 3.1415);

// dblValue is now valid.
```

## See also

[InitVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdouble)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodouble)

[VariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodouble)