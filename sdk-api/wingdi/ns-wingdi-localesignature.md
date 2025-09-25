# LOCALESIGNATURE structure

## Description

Contains extended font signature information, including two code page bitfields (CPBs) that define the default and supported character sets and code pages. This structure is typically used to represent the relationships between font coverage and locales.

## Members

### `lsUsb`

A 128-bit Unicode subset bitfield (USB) identifying up to 122 Unicode subranges. Each bit, except the five most significant bits, represents a single subrange. The most significant bit is always 1; the second most significant is reserved and must be 0. Unicode subsets are numbered in accordance with the [OpenType font specification](https://learn.microsoft.com/windows/desktop/Intl/opentype-font-format). For a list of possible bitfield values, see [Unicode Subset Bitfields](https://learn.microsoft.com/windows/desktop/Intl/unicode-subset-bitfields).

### `lsCsbDefault`

A code page bitfield that indicates the default OEM and ANSI code pages for a locale. The code pages can be identified by separate bits or a single bit representing a common ANSI and OEM code page. For a list of possible bitfield values, see [Code Page Bitfields](https://learn.microsoft.com/windows/desktop/Intl/code-page-bitfields).

### `lsCsbSupported`

A code page bitfield that indicates all the code pages in which the locale can be supported. For a list of possible bitfield values, see [Code Page Bitfields](https://learn.microsoft.com/windows/desktop/Intl/code-page-bitfields).

## See also

[FONTSIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-fontsignature)

[Unicode and Character Set Structures](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-structures)