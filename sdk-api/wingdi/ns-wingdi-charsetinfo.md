# CHARSETINFO structure

## Description

Contains information about a character set.

## Members

### `ciCharset`

Character set value. For a list of possible values, see *lfCharSet* field of the [LOGFONT structure](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfontw).

### `ciACP`

Windows ANSI code page identifier. For a list of identifiers, see [Code Page Identifiers](https://learn.microsoft.com/windows/desktop/Intl/code-page-identifiers).

### `fs`

A [FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature) structure that identifies the Unicode subrange and the specific Windows ANSI character set/code page. Only one code page will be set when this structure is set by the function.

## See also

[Code Pages](https://learn.microsoft.com/windows/desktop/Intl/code-pages)

[FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfontw)

[TranslateCharsetInfo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-translatecharsetinfo)

[Unicode and Character Set Structures](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-structures)