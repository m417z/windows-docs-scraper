# HYPHRESULT structure

## Description

Contains information about the result of hyphenation in a Microsoft Rich Edit control.

## Members

### `khyph`

Type: **[KHYPH](https://learn.microsoft.com/windows/win32/api/richedit/ne-richedit-khyph)**

The type of hyphenation.

### `ichHyph`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the WCHAR in the passed string where hyphenation occurred.

### `chHyph`

Type: **[WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The character used when hyphenation requires a replacement or an addition or a change. If no new character is needed, the value is zero.

## Remarks

This structure is used with the [HYPHENATEINFO](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphenateinfo) structure.

## See also

[HYPHENATEINFO](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphenateinfo)

[KHYPH](https://learn.microsoft.com/windows/win32/api/richedit/ne-richedit-khyph)

**Reference**