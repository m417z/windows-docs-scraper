# HYPHENATEINFO structure

## Description

Contains information about hyphenation in a Microsoft Rich Edit control.

## Members

### `cbSize`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the **HYPHENATEINFO** structure, in bytes.

### `dxHyphenateZone`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size, in TWIPS (one TWIP is 1/1440 inch), of the area near the margin that excludes hyphenation. If a space character is closer to the margin than this value, do not hyphenate the following word.

### `pfnHyphenate`

Type: **PFNHYPHENATEPROC**

The client-defined [HyphenateProc](https://learn.microsoft.com/windows/win32/api/richedit/nf-richedit-hyphenateproc) callback function.

## Remarks

This structure is used with the [EM_GETHYPHENATEINFO](https://learn.microsoft.com/windows/win32/controls/em-gethyphenateinfo) and [EM_SETHYPHENATEINFO](https://learn.microsoft.com/windows/win32/controls/em-sethyphenateinfo) messages.

## See also

[EM_GETHYPHENATEINFO](https://learn.microsoft.com/windows/win32/controls/em-gethyphenateinfo)

[EM_SETHYPHENATEINFO](https://learn.microsoft.com/windows/win32/controls/em-sethyphenateinfo)

[HyphenateProc](https://learn.microsoft.com/windows/win32/api/richedit/nf-richedit-hyphenateproc)

**Reference**