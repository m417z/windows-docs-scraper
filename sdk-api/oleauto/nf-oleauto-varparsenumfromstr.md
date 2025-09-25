# VarParseNumFromStr function

## Description

Parses a string, and creates a type-independent description of the number it represents.

## Parameters

### `strIn` [in]

The input string to convert.

### `lcid` [in]

The locale identifier.

### `dwFlags` [in]

Enables the caller to control parsing, therefore defining the acceptable syntax of a number. If this field is set to zero, the input string must contain nothing but decimal digits. Setting each defined flag bit enables parsing of that syntactic feature. Standard Automation parsing (for example, as used by [VarI2FromStr](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-vari2fromstr)) has all flags set (NUMPRS_STD).

### `pnumprs` [out]

The parsed results.

### `rgbDig` [out]

The values for the digits in the range 0–7, 0–9, or 0–15, depending on whether the number is octal, decimal, or hexadecimal. All leading zeros have been stripped off. For decimal numbers, trailing zeros are also stripped off, unless the number is zero, in which case a single zero digit will be present.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Internal memory allocation failed. (Used for DBCS only to create a copy with all wide characters mapped narrow.) |
| **DISP_E_TYPEMISMATCH** | There is no valid number in the string, or there is no closing parenthesis to match an opening one. In the former case, cDig and cchUsed in the NUMPARSE structure will be zero. In the latter, the NUMPARSE structure and digit array are fully updated, as if the closing parenthesis was present. |
| **DISP_E_OVERFLOW** | For hexadecimal and octal digits, there are more digits than will fit into the array. For decimal, the exponent exceeds the maximum possible. In both cases, the NUMPARSE structure and digit array are fully updated (for decimal, the cchUsed field excludes the entire exponent). |