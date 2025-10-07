# ICONRESDIR structure

Contains the dimensions and color format of an individual icon image in a resource group.

The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**Width**

Type: **BYTE**

The width of the icon, in pixels.
The value 0 is accepted as representing a width of 256.

**Height**

Type: **BYTE**

The height of the icon, in pixels.
The value 0 is accepted as representing a height of 256.

**ColorCount**

Type: **BYTE**

The number of colors in the icon.
Acceptable values are 2, 8, and 16. The value 0 means that the number of colors deduced from **BitCount** and **Planes** in the [**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir) structure.

**reserved**

Type: **BYTE**

Reserved; must be set to the same value as that of the reserved field in the icon file header.

## Remarks

The **ICONRESDIR** structure is passed in the [**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir) structure if the **RESDIR** structure describes an icon.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

