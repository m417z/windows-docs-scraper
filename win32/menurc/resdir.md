# RESDIR structure

Contains information about an individual icon or cursor component in a [RT\_GROUP\_ICON](https://learn.microsoft.com/windows/desktop/menurc/resource-types) or [RT\_GROUP\_CURSOR](https://learn.microsoft.com/windows/desktop/menurc/resource-types) resource group.

There is one **RESDIR** structure for each group component.

The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**Icon**

Type: **[**ICONRESDIR**](https://learn.microsoft.com/windows/win32/menurc/iconresdir)**

The width, height, and color count of the indicated icon.

**Cursor**

Type: **[**CURSORDIR**](https://learn.microsoft.com/windows/win32/menurc/cursordir)**

The width and height of the indicated cursor.

**Planes**

Type: **WORD**

The number of color planes in the icon or cursor bitmap.

**BitCount**

Type: **WORD**

The number of bits per pixel in the icon or cursor bitmap.

**BytesInRes**

Type: **DWORD**

The size of the resource, in bytes.

**IconCursorId**

Type: **WORD**

Unique ordinal identifier of the [RT\_ICON](https://learn.microsoft.com/windows/desktop/menurc/resource-types) icon or [RT\_CURSOR](https://learn.microsoft.com/windows/desktop/menurc/resource-types) cursor resource.

## Remarks

One or more **RESDIR** structures immediately follow the [**NEWHEADER**](https://learn.microsoft.com/windows/win32/menurc/newheader) structure in the .res file. The **ResCount** member of the **NEWHEADER** structure specifies the number of **RESDIR** structures. Note that the **RESDIR** structure consists of either an [**ICONRESDIR**](https://learn.microsoft.com/windows/win32/menurc/iconresdir) structure or a [**CURSORDIR**](https://learn.microsoft.com/windows/win32/menurc/cursordir) structure followed by the **Planes**, **BitCount**, **BytesInRes**, and **IconCursorId** members.

If the **RESDIR** structure contains information about a cursor, the first two **WORD**s the resource compiler writes to the [RT\_CURSOR](https://learn.microsoft.com/windows/desktop/menurc/resource-types) resource are the **xHotSpot** and **yHotSpot** members of the [**LOCALHEADER**](https://learn.microsoft.com/windows/win32/menurc/localheader) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**CURSORDIR**](https://learn.microsoft.com/windows/win32/menurc/cursordir)

[**ICONRESDIR**](https://learn.microsoft.com/windows/win32/menurc/iconresdir)

[**LOCALHEADER**](https://learn.microsoft.com/windows/win32/menurc/localheader)

[**NEWHEADER**](https://learn.microsoft.com/windows/win32/menurc/newheader)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

