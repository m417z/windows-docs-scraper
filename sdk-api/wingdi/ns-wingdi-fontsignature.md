# FONTSIGNATURE structure

## Description

Contains information identifying the code pages and Unicode subranges for which a given font provides glyphs.

## Members

### `fsUsb`

A 128-bit Unicode subset bitfield (USB) identifying up to 126 Unicode subranges. Each bit, except the two most significant bits, represents a single subrange. The most significant bit is always 1 and identifies the bitfield as a font signature; the second most significant bit is reserved and must be 0. Unicode subranges are numbered in accordance with the ISO 10646 standard. For more information, see [Unicode Subset Bitfields](https://learn.microsoft.com/windows/desktop/Intl/unicode-subset-bitfields).

### `fsCsb`

A 64-bit, code-page bitfield (CPB) that identifies a specific character set or code page. Code pages are in the lower 32 bits of this bitfield. The high 32 are used for non-Windows code pages. For more information, see [Code Page Bitfields](https://learn.microsoft.com/windows/desktop/Intl/code-page-bitfields).

## Remarks

GDI relies on Windows code pages fitting within a 32-bit value. Furthermore, the highest 2 bits within this value are reserved for GDI internal use and may not be assigned to code pages.

## See also

[LOCALESIGNATURE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-localesignature)

[Unicode and Character Set Structures](https://learn.microsoft.com/windows/desktop/Intl/unicode-and-character-set-structures)