# VarFormatPercent function

## Description

Formats a variant containing percentages into a string form.

## Parameters

### `pvarIn` [in]

The variant containing the value to format.

### `iNumDig` [in]

The number of digits to pad to after the decimal point. Specify -1 to use the system default value.

### `iIncLead` [in]

Specifies whether to include the leading digit on numbers.

| Value | Meaning |
| --- | --- |
| -2 | Use the system default. |
| -1 | Include the leading digit. |
| 0 | Do not include the leading digit. |

### `iUseParens` [in]

Specifies whether negative numbers should use parentheses.

| Value | Meaning |
| --- | --- |
| -2 | Use the system default. |
| -1 | Use parentheses. |
| 0 | Do not use parentheses. |

### `iGroup` [in]

Specifies whether thousands should be grouped. For example 10,000 versus 10000.

**Note** Regular numbers and currencies have separate system defaults for all the above options.

| Value | Meaning |
| --- | --- |
| -2 | Use the system default. |
| -1 | Group thousands. |
| 0 | Do not group thousands. |

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