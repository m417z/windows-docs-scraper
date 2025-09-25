# VarBstrFromDec function

## Description

Converts a decimal value to a BSTR value.

## Parameters

### `pdecIn` [in]

The value to convert.

### `lcid` [in]

The locale identifier.

### `dwFlags` [in]

One or more of the following flags.

| Value | Meaning |
| --- | --- |
| **LOCALE_NOUSEROVERRIDE** | Uses the system default locale settings, rather than custom locale settings. |
| **VAR_TIMEVALUEONLY** | Omits the date portion of a VT_DATE and returns only the time. Applies to conversions to or from dates. Not used for [VariantChangeType](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantchangetype) and [VariantChangeTypeEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantchangetypeex). |
| **VAR_DATEVALUEONLY** | Omits the time portion of a VT_DATE and returns only the date. Applies to conversions to or from dates. Not used for [VariantChangeType](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantchangetype) and [VariantChangeTypeEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantchangetypeex). |

### `pbstrOut` [out]

The resulting value.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADVARTYPE** | The input parameter is not a valid type of variant. |
| **DISP_E_OVERFLOW** | The data pointed to by the output parameter does not fit in the destination type. |
| **DISP_E_TYPEMISMATCH** | The argument could not be coerced to the specified type. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |