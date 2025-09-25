# DWRITE_MAKE_OPENTYPE_TAG macro

## Syntax

```cpp
DWORD DWRITE_MAKE_OPENTYPE_TAG(
    char a,
    char b,
    char c,
    char d
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

An OpenType tag as a 32-bit integer.

## Description

Creates an OpenType tag as a 32-bit integer, such that the first character in the tag is the lowest byte (least significant on little-endian architectures), which can be used to compare with tags in the font file. This macro is compatible with [DWRITE_FONT_FEATURE_TAG](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_font_feature_tag).

## Parameters

### `a`

Type: **[CHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The first character in the tag.

### `b`

Type: **[CHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The second character in the tag.

### `c`

Type: **[CHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The third character in the tag.

### `d`

Type: **[CHAR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The fourth character in the tag.

## Remarks

The OpenType language (such as "ROM ", "URD ", and "FAR " for Romanian, Urdu, and Persian) are determined from the locale, and the script ("latn" and "arab" for Latin and Arabic) is determined from the script analyzer. That's why these are not listed under OpenType tags; only the feature tags.

## Examples

```cpp
DWRITE_MAKE_OPENTYPE_TAG('c','c','m','p');
// Result: DWORD 0x706D6363
```