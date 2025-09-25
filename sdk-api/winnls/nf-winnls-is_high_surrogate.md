# IS_HIGH_SURROGATE macro

## Syntax

```cpp
bool IS_HIGH_SURROGATE(
    WCHAR wch
);
```

## Return value

Type: **bool**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

Determines if a character is a UTF-16 high [surrogate](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters) code point, ranging from 0xd800 to 0xdbff, inclusive.

## Parameters

### `wch`

Character to test.

## See also

[IS_LOW_SURROGATE](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-is_low_surrogate)

[IS_SURROGATE_PAIR](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-is_surrogate_pair)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[Surrogates and Supplementary Characters](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters)