# _OPEN_REPARSE_LIST_ENTRY structure

## Description

This structure supports callers opening specific reparse points without
inhibiting reparse behavior for all classes of reparse points.

## Members

### `OpenReparseListEntry`

The entry in the open reparse list.

### `ReparseTag`

The reparse tag that should be opened directly without returning **STATUS_REPARSE**.

### `Flags`

Flags that control behavior when a reparse point is encountered on a directory that may be non-empty (one whose reparse tag is recognized by **FsRtlIsNonEmptyDirectoryReparsePointAllowed**)
.

| Value | Meaning |
| --- | --- |
| **OPEN_REPARSE_POINT_TAG_ENCOUNTERED**<br><br>0x00000001 | Indicates that the object that was opened matched the given criteria. |
| **OPEN_REPARSE_POINT_REPARSE_IF_CHILD_EXISTS**<br><br>0x00000002 | Reparse on the directory if the reparse point is on a directory that is not the final path component, and the next path component exists. |
| **OPEN_REPARSE_POINT_REPARSE_IF_CHILD_NOT_EXISTS**<br><br>0x00000004 | Reparse on the directory if the reparse point is on a directory that is not the final path component, and the next path component does not exist. |
| **OPEN_REPARSE_POINT_REPARSE_IF_DIRECTORY_FINAL_COMPONENT**<br><br>0x00000008 | Reparse on the directory if the reparse point is on a directory that is the final path component and **FILE_OPEN_REPARSE_POINT** has not been specified. |
| **OPEN_REPARSE_POINT_VERSION_EX**<br><br>0x80000000 | Indicates that the fields of this structure are valid. |

**Note** When the **OPEN_REPARSE_POINT_REPARSE_IF_CHILD_EXISTS**, **OPEN_REPARSE_POINT_REPARSE_IF_CHILD_NOT_EXISTS**, and **OPEN_REPARSE_POINT_REPARSE_IF_DIRECTORY_FINAL_COMPONENT** flags are used together at the same time, it indicates that the system is to reparse on any directory reparse point.

### `ReparseGuid`

The GUID of the reparse tag that should be opened directly without returning **STATUS_REPARSE**.

### `Size`

The size of this structure.

### `RemainingLength`

The unprocessed path length when the reparse point was
encountered.

## Remarks

This structure lets callers open specific reparse points without
inhibiting reparse behavior for all classes of reparse points.
[OPEN_REPARSE_LIST](https://learn.microsoft.com/previous-versions/mt734264(v=vs.85)) is a structure used in an ECP with **ECP_TYPE_OPEN_REPARSE_GUID** (`323eb6a8-affd-4d95-8230-863bce09d37a`). The **OPEN_REPARSE_LIST** points to a list of **OPEN_REPARSE_LIST_ENTRY**
structures specifying the tag and possibly GUID that should be
opened directly without returning **STATUS_REPARSE**.
If a match is found, the corresponding **OPEN_REPARSE_LIST_ENTRY** structure will have the **OPEN_REPARSE_POINT_TAG_ENCOUNTERED** flag set to indicate that the object that was opened matched the given criteria. If a match is found for a directory that is not the final path component and **STATUS_REPARSE** is returned, the unprocessed path
length will be set in the **RemainingLength** field.