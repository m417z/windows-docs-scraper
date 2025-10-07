# FIND\_INFO structure

Contains search context information.

## Members

**tiIndex**

The **TAGID** for the index to be searched.

**tiCurrent**

The **TAGID** for the current item that was located.

**tiEndIndex**

The **TAGID** for the last record after FindFirst if the index is UNIQUE.

**tName**

The type of the item to be located. See [TAG Types](https://learn.microsoft.com/windows/win32/devnotes/tag-types).

**dwIndexRec**

An internal counter used to track where in the index the next find operation should start.

**dwFlags**

This member can be 0 or **SHIMDB\_INDEX\_UNIQUE\_KEY** (0x00000001), which indicates that this is a unique-key index.

**ullKey**

The key for the current entry.

**szName**

The current string (if the tag type is **TAG\_TYPE\_STRINGREF**).

**dwName**

The current **DWORD** value (if the tag type is **TAG\_TYPE\_DWORD**).

**pguidName**

The current GUID value (if the tag type is **TAG\_TYPE\_BINARY** and the TAG is **TAG\_DATABASE\_ID**).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[**SdbFindFirstDWORDIndexedTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindfirstdwordindexedtag)

