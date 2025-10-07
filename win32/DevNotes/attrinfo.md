# ATTRINFO structure

Contains the attribute data for a file.

## Members

**tAttrID**

The attribute type. See [TAG Types](https://learn.microsoft.com/windows/win32/devnotes/tag-types).

**dwFlags**

The flags for this attribute.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------|
|

**ATTRIBUTE\_AVAILABLE**

0x00000001

| The attribute is available.<br> |
|

**ATTRIBUTE\_FAILED**

0x00000002

| The call failed because the attribute is not available.<br> |

**ullAttr**

A **QWORD** value (if the tag type is **TAG\_TYPE\_QWORD**).

**dwAttr**

A **DWORD** value (if the tag type is **TAG\_TYPE\_DWORD**).

**lpAttr**

A pointer to a string (if the tag type is **TAG\_TYPE\_STRINGREF**).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[**SdbFormatAttribute**](https://learn.microsoft.com/windows/win32/devnotes/sdbformatattribute)

[**SdbFreeFileAttributes**](https://learn.microsoft.com/windows/win32/devnotes/sdbfreefileattributes)

[**SdbGetFileAttributes**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetfileattributes)

