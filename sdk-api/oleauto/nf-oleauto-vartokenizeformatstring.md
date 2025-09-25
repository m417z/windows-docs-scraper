# VarTokenizeFormatString function

## Description

Parses the actual format string into a series of tokens which can be used to format variants using [VarFormatFromTokens](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varformatfromtokens).

## Parameters

### `pstrFormat` [in, optional]

The format string. For example "mm-dd-yy".

### `rgbTok` [in, out]

The destination token buffer.

### `cbTok` [in]

The size of the destination token buffer.

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

### `lcid` [in]

The locale to interpret format string in.

### `pcbActual` [in, optional]

Points to the integer which is set to the first generated token. This parameter can be NULL.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **DISP_E_BUFFERTOOSMALL** | The destination token buffer is too small. |

## Remarks

Parsing the format string once and then using it repeatedly is usually faster than calling [VarFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varformat) repeatedly, because the latter routine calls **VarTokenizeFormatString** for each call.

The locale you pass in controls how the format string is interpreted, not how the actual output of [VarFormatFromTokens](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varformatfromtokens) looks.