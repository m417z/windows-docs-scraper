# VariantToBoolean function

## Description

Extracts the value of a Boolean property from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pfRet` [out]

Type: **BOOL***

When this function returns, contains the extracted value if one exists; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold a Boolean value. For instance, an application that obtains values from a Shell folder can use this function to safely extract the value from one of the folder's Boolean properties.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_BOOL, this function extracts the **BOOL** value.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is not of type VT_BOOL, this function attempts to convert the value in the **VARIANT** structure into a **BOOL**. If a conversion is not possible, [VariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoboolean) returns a failure code and sets *pfRet* to **FALSE**. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, VT_EMPTY is successfully converted to **FALSE**.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoboolean) to access a **BOOL** value in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant).

```cpp
// VARIANT var;
// Assume variable var is initialize and valid.
// The application expects it to hold a VT_BOOL value.
BOOL fValue;

HRESULT hr = VariantToBoolean(var, &fValue);

if (SUCCEEDED(hr))
{
    // fValue is now valid.
}
else
{
    // fValue is always FALSE.
}
```

## See also

[InitVariantFromBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromboolean)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToBoolean](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoboolean)

[VariantToBooleanArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobooleanarray)