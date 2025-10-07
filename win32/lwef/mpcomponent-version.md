# MPCOMPONENT\_VERSION structure

Version and update time for an individual component.

## Members

**Version**

Type: **ULONGLONG**

Version field. Each **WORD** represents major, minor, build, and revision.

**UpdateTime**

Type: **ULARGE\_INTEGER**

Last update time of the component, in **FILETIME** format.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

