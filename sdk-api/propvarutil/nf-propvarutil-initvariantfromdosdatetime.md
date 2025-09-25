# InitVariantFromDosDateTime function

## Description

Initializes a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure with a date and time given in the format used by Microsoft MS-DOS. The date and time values are converted to the format used to store date and time in a **VARIANT**.

## Parameters

### `wDate` [in]

Type: **WORD**

**WORD** value that represents an MS-DOS date. See [DosDateTimeToVariantTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dosdatetimetovarianttime) for more information about this format.

### `wTime` [in]

Type: **WORD**

**WORD** value that represents an MS-DOS time. See [DosDateTimeToVariantTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dosdatetimetovarianttime) for more information about this format.

### `pvar` [out]

Type: **VARIANT***

When this function returns, contains the initialized [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Creates a **VT_DATE** variant.

See [DosDateTimeToVariantTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dosdatetimetovarianttime) for more information about the formats of *wDate*, *wTime*, and of the resulting variant date.

This is an inline function, with its source code provided in the header. It is not included in any .dll or .lib file.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [InitVariantFromDosDateTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromdosdatetime).

```cpp
// WORD wDate, wTime;
// Assume variables wDate and wTime are initialized and valid.
VARIANT var;

HRESULT hr = InitVariantFromDosDateTime(wDate, wTime, &var);

if (SUCCEEDED(hr))
{
    // var now is valid and has type VT_DATE.
    VariantClear(&propvar);
}
```

## See also

[InitPropVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromfiletime)

[InitVariantFromFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromfiletime)

[VariantToDosDateTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttodosdatetime)

[VariantToFileTime](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttofiletime)