# VariantToDosDateTime function

## Description

Extracts a date and time value in Microsoft MS-DOS format from a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pwDate` [out]

Type: **WORD***

When this function returns, contains the extracted **WORD** that represents a MS-DOS date.

### `pwTime` [out]

Type: **WORD***

When this function returns, contains the extracted contains the extracted **WORD** that represents a MS-DOS time.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold a datetime value.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is of type **VT_DATE**, this function extracts the datetime value.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) is not of type **VT_DATE**, the function attempts to convert the value in the **VARIANT** structure into the right format. If a conversion is not possible, [VariantToDosDateTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodosdatetime) returns a failure code. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

See [DosDateTimeToVariantTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dosdatetimetovarianttime) for more information about the formats of *pwDate*, *pwTime*, and the source datetime value.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToDosDateTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodosdatetime) to access a datetime value in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant).

```cpp
// VARIANT var;
// Assume variable var is initialize and valid.
// The application expects var to hold a VT_DATE value.

WORD wDate;
WORD wTime;

HRESULT hr = VariantToDosDateTime(var, &wDate, &wTime);

if (SUCCEEDED(hr))
{
    // wDate and wTime are now valid.
}
```

## See also

[InitVariantFromDosDateTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdosdatetime)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttofiletime)

[VariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttofiletime)