# FONTGROUPHDR structure

Contains the information necessary for an application to access a specific font. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**NumberOfFonts**

Type: **WORD**

The number of individual fonts associated with this resource.

**DE**

Type: **[**DIRENTRY**](https://learn.microsoft.com/windows/win32/menurc/direntry)**

A structure that contains a unique ordinal identifier for each font in the resource. The **DE** member is a placeholder for the variable-length array of [**DIRENTRY**](https://learn.microsoft.com/windows/win32/menurc/direntry) structures.

## Remarks

The **FONTGROUPHDR** structure follows the data for the individual fonts in the .Res file. The resource compiler automatically adds the **FONTGROUPHDR** structure, generally as the last entry in the file.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**DIRENTRY**](https://learn.microsoft.com/windows/win32/menurc/direntry)

[**FONTDIRENTRY**](https://learn.microsoft.com/windows/win32/menurc/fontdirentry)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

