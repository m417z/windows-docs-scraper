# StrToIntExA function

## Description

Converts a string representing a decimal or hexadecimal number to an integer.

## Parameters

### `pszString` [in]

Type: **PCTSTR**

A pointer to the null-terminated string to be converted. For further details concerning the valid forms of the string, see the Remarks section.

### `dwFlags`

Type: **STIF_FLAGS**

One of the following values that specify how *pszString* should be parsed for its conversion to an integer.

#### STIF_DEFAULT

The string at *pszString* contains the representation of a decimal value.

#### STIF_SUPPORT_HEX

The string at *pszString* contains the representation of either a decimal or hexadecimal value. Note that in hexadecimal representations, the characters A-F are case-insensitive.

### `piRet` [out]

Type: **int***

A pointer to an **int** that receives the converted string. For instance, in the case of the string "123", the integer pointed to by this value receives the integer value 123.

If this function returns **FALSE**, this value is undefined.

If the value returned is too large to be contained in a variable of type **int**, this parameter contains the 32 low-order bits of the value. Any high-order bits beyond that are lost.

## Return value

Type: **BOOL**

Returns **TRUE** if the string is converted; otherwise **FALSE**.

## Remarks

The string pointed to by the *pszString* parameter must have one of the following forms to be parsed successfully.

* This form is accepted as a decimal value under either flag.
  ``` syntax
  (optional white space)(optional sign)(one or more decimal digits)
  ```
* These forms are required for hexadecimal values when the STIF_SUPPORT_HEX flag is passed.
  ``` syntax
  (optional white space)(optional sign)0x(one or more hexadecimal digits)
  ```

  ``` syntax
  (optional white space)(optional sign)0X(one or more hexadecimal digits)
  ```

The optional sign can be the character '-' or '+'; if omitted, the sign is assumed to be positive.

**Note** If the value is parsed as hexadecimal, the optional sign is ignored, even if it is a '-' character. For example, the string "-0x1" is parsed as 1 instead of -1.

If the string pointed to by *pszString* contains an invalid character, that character is considered the end of the string to be converted and the remainder is ignored. For instance, given the invalid hexadecimal string "0x00am123", **StrToIntEx** only recognizes "0x00a", converts it to the integer value 10, and returns **TRUE**.

> [!NOTE]
> The shlwapi.h header defines StrToIntEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).