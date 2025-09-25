# TEXT macro

## Syntax

```cpp
void TEXT(
    LPTSTR quote
);
```

## Description

Identifies a string as Unicode when UNICODE is defined by a preprocessor directive during compilation. Otherwise, the macro identifies a string as an ANSI string.

## Parameters

### `quote`

Pointer to the string to interpret as UTF-16 or ANSI.

## Remarks

This macro interprets an ANSI string at runtime according to the current Windows ANSI code page. Literal ANSI strings that are not strictly ASCII are interpreted differently when processed with different Windows ANSI code pages. For example, "\0xC4" in code page 1252 (Latin-1) represents Upper Case A with Dieresis (Ä). However, in code page 1253 (Greek), the string represents Upper Case Delta (Δ). These different interpretations lead to development and maintenance issues. For example, a developer might correct a string when using a different system code page from the page used by the original developer; or a build computer might use a different code page. The different interpretations also pose runtime issues, for example, when the end user computer uses a different code page to interpret a string from that used by the build computer.

## See also

[Unicode and Character Set Macros](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-macros)

[Unicode and Character Sets](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-sets)