# VariantToDouble function

## Description

Extracts a **DOUBLE** value from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure. If no value can be extracted, then a default value is assigned.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pdblRet` [out]

Type: **DOUBLE***

When this function returns, contains the extracted value if one exists; otherwise, 0.0.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold a **DOUBLE** value. For instance, an application that obtains values from a Shell folder can use this function to safely extract the value from one of the folder's properties whose value is stored as a **DOUBLE**.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type VT_R8, this function extracts the **DOUBLE** value.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is not of type VT_R8, the function attempts to convert the value stored in the **VARIANT** structure into a **DOUBLE**. If a conversion is not possible, [VariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodouble) returns a failure code and sets *pdblRet* to `0.0`. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions. Of note, VT_EMPTY is successfully converted to 0.0.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodouble) to access a **DOUBLE** value stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

```cpp
// VARIANT var;
// Assume variable var is initialize and valid.
// The application expects var to hold a VT_R8 value.
DOUBLE dblValue;

HRESULT hr = VariantToDouble(var, & dblValue);

if (SUCCEEDED(hr))
{
    // dblValue is now valid.
}
else
{
    // dblValue is always FALSE.
}
```

## See also

[InitVariantFromDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdouble)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToDouble](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttodouble)

[VariantToDoubleArray](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodoublearray)