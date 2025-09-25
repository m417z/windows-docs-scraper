# StrToIntW function

## Description

Converts a string that represents a decimal value to an integer. The **StrToLong** macro is identical to this function.

## Parameters

### `pszSrc` [in]

Type: **PCTSTR**

A pointer to the null-terminated string to be converted. A valid string representing a decimal value contains only the characters 0-9 and must have the following form to be parsed successfully.

``` syntax
(optional white space)(optional sign)(one or more decimal digits)
```

The optional sign can be the character '-' or '+'; if omitted, the sign is assumed to be positive.

## Return value

Type: **int**

Returns the **int** value represented by *pszSrc*. For instance, the string "123" returns the integer value 123.

## Remarks

If the string pointed to by *pszSrc* contains an invalid character, that character is considered the end of the string to be converted and the remainder is ignored. For instance, given the invalid decimal string "12b34", **StrToInt** only recognizes "12" and returns that integer value.

> [!NOTE]
> The shlwapi.h header defines StrToInt as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StrToIntEx](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strtointexa)