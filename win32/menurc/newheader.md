# NEWHEADER structure

Contains the number of icon or cursor components in a resource group. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**Reserved**

Type: **WORD**

Reserved; must be zero.

**ResType**

Type: **WORD**

The resource type. This member must have one of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------|
|

**RES\_CURSOR**

2

| Cursor resource type.<br> |
|

**RES\_ICON**

1

| Icon resource type.<br> |

**ResCount**

Type: **WORD**

The number of icon or cursor components in the resource group.

## Remarks

One or more [**RESDIR**](https://learn.microsoft.com/windows/win32/menurc/resdir) structures immediately follow the **NEWHEADER** structure in the .res file. The **ResCount** member specifies the number of **RESDIR** structures.

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

