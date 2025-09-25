# IS_SURROGATE_PAIR macro

## Syntax

```cpp
bool IS_SURROGATE_PAIR(
    WCHAR hs,
    WCHAR ls
);
```

## Return value

Type: **bool**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

Determines if the specified code units form a UTF-16 [surrogate pair](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters).

## Parameters

### `hs`

UTF-16 code unit to test for a high surrogate value. The range for a high UTF-16 code unit is 0xd800 to 0xdbff, inclusive.

### `ls`

UTF-16 code unit to test for a low surrogate value. The range for a low UTF-16 code unit is 0xdc00 to 0xdfff, inclusive.

## Remarks

For this macro to succeed, the *hs* value must be a high UTF-16 code unit, and the *ls* value must be a low UTF-16 code unit.

## See also

[IS_HIGH_SURROGATE](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-is_high_surrogate)

[IS_LOW_SURROGATE](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-is_low_surrogate)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[Surrogates and Supplementary Characters](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters)