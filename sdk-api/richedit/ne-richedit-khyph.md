# KHYPH enumeration

## Description

Contains values used to specify how to do hyphenation in a rich edit control. The [HyphenateProc](https://learn.microsoft.com/windows/win32/api/richedit/nf-richedit-hyphenateproc) callback function uses this enumeration type.

## Constants

### `khyphNil`

No hyphenation is allowed.

### `khyphNormal`

Do not change any characters during hyphenation.

### `khyphAddBefore`

Add a letter before the hyphenation mark.

### `khyphChangeBefore`

Change the letter before the hyphenation mark.

### `khyphDeleteBefore`

Delete the letter before the hyphenation mark.

### `khyphChangeAfter`

Change the letter after the hyphenation mark.

### `khyphDelAndChange`

The two letters before the hyphenation mark are replaced by one character; see the **chHyph** member of [HYPHRESULT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphresult).

## Remarks

Hyphenation rules are specific for each language; not all hyphenation types are valid for a given language.

## See also

[HYPHRESULT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-hyphresult)

[HyphenateProc](https://learn.microsoft.com/windows/win32/api/richedit/nf-richedit-hyphenateproc)

**Reference**