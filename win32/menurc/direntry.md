# DIRENTRY structure

Contains a unique ordinal that identifies an individual font in the font resource group. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**fontOrdinal**

Type: **WORD**

A unique ordinal identifier for an individual font in a font resource group.

## Remarks

The [**FONTDIRENTRY**](https://learn.microsoft.com/windows/win32/menurc/fontdirentry) structure for the specified font directly follows the **DIRENTRY** structure for that font.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**FONTDIRENTRY**](https://learn.microsoft.com/windows/win32/menurc/fontdirentry)

[**FONTGROUPHDR**](https://learn.microsoft.com/windows/win32/menurc/fontgrouphdr)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

