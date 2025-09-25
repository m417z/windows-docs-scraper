# SCRIPT_ITEM structure

## Description

Contains a script item, including a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure with the string offset of the first character of the item.

## Members

### `iCharPos`

Offset from the beginning of the itemized string to the first character of the item, counted in Unicode code points (WCHAR values).

### `a`

A [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure containing the analysis of the item.

## See also

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)