# IS_LOW_SURROGATE macro

## Syntax

```cpp
bool IS_LOW_SURROGATE(
    WCHAR wch
);
```

## Return value

Type: **bool**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

Determines if a character is a UTF-16 low [surrogate](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters) code point, ranging from 0xdc00 to 0xdfff, inclusive.

## Parameters

### `wch`

Character to test.

## See also

[IS_HIGH_SURROGATE](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-is_high_surrogate)

[IS_SURROGATE_PAIR](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-is_surrogate_pair)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Macros](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-macros)

[Surrogates and Supplementary Characters](https://learn.microsoft.com/windows/desktop/Intl/surrogates-and-supplementary-characters)