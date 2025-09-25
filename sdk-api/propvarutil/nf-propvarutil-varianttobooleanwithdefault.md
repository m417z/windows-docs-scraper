# VariantToBooleanWithDefault function

## Description

Extracts a **BOOL** value from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure. If no value exists, then the specified default value is returned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `fDefault` [in]

Type: **BOOL**

The default value for use where no extractable value exists.

## Return value

Type: **BOOL**

Returns the extracted **BOOL** value; otherwise, the default value specified in *fDefault*.

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold a **BOOL** value and wants to use a default value if it does not.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_BOOL, this helper extracts the **BOOL** value.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is not of type VT_BOOL, the function attempts to convert the value in the **VARIANT** into a **BOOL**.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_EMPTY or a conversion is not possible, then [VariantToBooleanWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanwithdefault) returns the default value provided by *fDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToBooleanWithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanwithdefault) to access a **BOOL** value stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

```cpp
// VARIANT var;
// Assume variable var is initialized and valid.
// The application expects var to hold a BOOL value.
// The application treats VT_EMPTY as FALSE.

BOOL fValue = VariantToBooleanWithDefault(var, FALSE);

// fValue is now valid.
```

## See also

[InitVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromboolean)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoboolean)

[VariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoboolean)