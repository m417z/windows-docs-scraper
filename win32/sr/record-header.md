# RECORD\_HEADER structure

\[This information applies only to Windows XP with Service Pack 2 (SP2).\]

The record header used by the [**CHANGE\_LOG\_ENTRY**](https://learn.microsoft.com/windows/win32/sr/change-log-entry) and [**CHANGE\_LOG\_HEADER**](https://learn.microsoft.com/windows/win32/sr/change-log-header) structures.

## Members

**dwRecordSize**

The total size of the record, including the header, in bytes.

**dwRecordType**

The record type. This member may be one of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**RecordTypeLogHeader**

0

| The record is the header for the change log.<br> |
|

**RecordTypeLogEntry**

1

| The record is the header for a change log entry.<br> |
|

**RecordTypeVolumePath**

2

| The data is the volume path for the change log entry.<br> |
|

**RecordTypeFirstPath**

3

| The data is the file path for the change log entry.<br> |
|

**RecordTypeSecondPath**

4

| The data is used when renaming change log entries; this path is where the renamed file is stored.<br> |
|

**RecordTypeTempPath**

5

| The data is the name of the backup file used to restore the change log entry. The backup files are located in the RP*n* folder. The file name has the following format: A*xxxxxxx*.*ext*, where *xxxxxxx* is a seven-digit number and *ext* is the file name extension.<br> |
|

**RecordTypeAclInline**

6

| The data is an ACL. The data format is a [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. <br> This value cannot be larger than 8,192 bytes. To specify a value larger than 8,192 bytes, use the **RecordTypeAclFile** member.<br> |
|

**RecordTypeAclFile**

7

| The data is the name of the ACL file used to store the ACL. The ACL files are located in the RP*n* folder. The file name has the following format: S*xxxxxxx*.acl, where *xxxxxxx* is a seven-digit number.<br> |
|

**RecordTypeDebugInfo**

8

| The data is debug information for the change log entry. The data format is a **SR\_LOG\_DEBUG\_INFO** structure. For more information, see Remarks.<br> |
|

**RecordTypeShortName**

9

| The data is the short name of the backup file.<br> |

## Remarks

The **SR\_LOG\_DEBUG\_INFO** structure is defined as follows.

``` syntax
typedef struct _SR_LOG_DEBUG_INFO {
    RECORD_HEADER Header;         // log entry header
    HANDLE ThreadId;              // thread identifier
    HANDLE ProcessId;             // process identifier
    ULARGER_INTEGER TimeStamp;    // event time stamp
    CHAR ProcesName[13];          // process name
} SR_LOG_DEBUG_INFO, *PSR_LOG_DEBUG_INFO;
```

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows XP with SP2<br> |

