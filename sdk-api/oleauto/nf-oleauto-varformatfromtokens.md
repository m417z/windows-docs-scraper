# VarFormatFromTokens function

## Description

Takes a tokenized format string and applies it to a variant to produce a formatted output string.

## Parameters

### `pvarIn` [in]

The variant containing the value to format.

### `pstrFormat` [in, optional]

The original format string.

### `pbTokCur` [in]

The tokenized format string from [VarTokenizeFormatString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vartokenizeformatstring).

### `dwFlags` [in]

The only flags that can be set are VAR_CALENDAR_HIJRI or VAR_FORMAT_NOSUBSTITUTE.

### `pbstrOut` [out]

The formatted output string.

### `lcid` [in]

The locale to use for the formatted output string.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Out of memory. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **DISP_E_TYPEMISMATCH** | The argument could not be coerced to the specified type. |

## Remarks

The locale *lcid* controls the formatted output string.