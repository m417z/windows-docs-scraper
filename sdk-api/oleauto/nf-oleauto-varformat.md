# VarFormat function

## Description

Formats a variant into string form by parsing a format string.

## Parameters

### `pvarIn` [in]

The variant.

### `pstrFormat` [in, optional]

The format string. For example "mm-dd-yy".

### `iFirstDay` [in]

First day of the week.

| Value | Meaning |
| --- | --- |
| 0 | The system default |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |
| 7 | Sunday |

### `iFirstWeek` [in]

First week of the year.

| Value | Meaning |
| --- | --- |
| 0 | The system default. |
| 1 | The first week contains January 1st. |
| 2 | The larger half (four days) of the first week is in the current year. |
| 3 | The first week has seven days. |

### `dwFlags` [in]

Flags that control the formatting process. The only flags that can be set are VAR_CALENDAR_HIJRI or VAR_FORMAT_NOSUBSTITUTE.

### `pbstrOut` [out]

The formatted string that represents the variant.

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