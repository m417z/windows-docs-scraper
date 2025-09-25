# VarFormatDateTime function

## Description

Formats a variant containing named date and time information into a string.

## Parameters

### `pvarIn` [in]

The variant containing the value to format.

### `iNamedFormat` [in]

The named date formats are as follows.

| Value | Meaning |
| --- | --- |
| 0 | General date |
| 1 | Long date |
| 2 | Short date |
| 3 | Long time |
| 4 | Short time |

### `dwFlags` [in]

VAR_CALENDAR_HIJRI is the only flag that can be set.

### `pbstrOut` [out]

Receives the formatted string that represents the variant.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |

## Remarks

This function uses the user's default locale while calling [VarTokenizeFormatString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vartokenizeformatstring) and [VarFormatFromTokens](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varformatfromtokens).

## See also

[Formatting Routines](https://learn.microsoft.com/previous-versions/windows/desktop/automat/formatting-functions)

[VarFormatFromTokens](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varformatfromtokens)

[VarTokenizeFormatString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vartokenizeformatstring)