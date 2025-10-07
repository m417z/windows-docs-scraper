# LOCALHEADER structure

Contains the x- and y-coordinates of a hotspot associated with the cursor identified by a [**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir) structure. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**xHotSpot**

Type: **WORD**

The x-coordinate of the cursor hot spot, in pixels.

**yHotSpot**

Type: **WORD**

The y-coordinate of the cursor hot spot, in pixels.

## Remarks

The **LOCALHEADER** structure is the first data written to the [RT\_CURSOR](https://learn.microsoft.com/windows/desktop/menurc/resource-types) resource if a [**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir) structure contains information about a cursor.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**CURSORDIR**](https://learn.microsoft.com/windows/win32/menurc/cursordir)

[**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

