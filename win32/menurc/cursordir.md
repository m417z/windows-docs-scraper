# CURSORDIR structure

Contains the dimensions of an individual cursor image in a resource group.

The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**Width**

Type: **WORD**

The width of the cursor, in pixels.

The value 0 is accepted as representing a width of 256.

**Height**

Type: **WORD**

The height of the cursor, in pixels.

The value 0 is accepted as representing a height of 256.

## Remarks

The **CURSORDIR** structure is passed in the [**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir) structure if the **RESDIR** structure describes a cursor.

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

