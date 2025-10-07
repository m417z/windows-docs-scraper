# CHANGE\_LOG\_ENTRY structure

\[This information applies only to Windows XP with Service Pack 2 (SP2).\]

A change log entry.

## Members

**RecordHeader**

A [**RECORD\_HEADER**](https://learn.microsoft.com/windows/win32/sr/record-header) structure. The **dwRecordType** member should be set to **RecordTypeLogEntry** (1).

**dwMagicNum**

This member should be set to 0xabcdef12.

**dwEntryType**

This member can be one of the following values:

****CHANGE\_LOG\_ENTRYTYPES\_ACLCHANGE** (0x2)**

****CHANGE\_LOG\_ENTRYTYPES\_ATTRCHANGE** (0x4)**

****CHANGE\_LOG\_ENTRYTYPES\_DIRCREATE** (0x80)**

****CHANGE\_LOG\_ENTRYTYPES\_DIRRENAME** (0x100)**

****CHANGE\_LOG\_ENTRYTYPES\_DIRDELETE** (0x200)**

****CHANGE\_LOG\_ENTRYTYPES\_FILECREATE** (0x20)**

****CHANGE\_LOG\_ENTRYTYPES\_FILEDELETE** (0x10)**

****CHANGE\_LOG\_ENTRYTYPES\_FILERENAME** (0x40)**

****CHANGE\_LOG\_ENTRYTYPES\_INPRECREATE** (0x100000)**

****CHANGE\_LOG\_ENTRYTYPES\_ISDIR** (0x20000)**

****CHANGE\_LOG\_ENTRYTYPES\_ISNOTDIR** (0x40000)**

****CHANGE\_LOG\_ENTRYTYPES\_MOUNTCREATE** (0x400)**

****CHANGE\_LOG\_ENTRYTYPES\_MOUNTDELETE** (0x800)**

****CHANGE\_LOG\_ENTRYTYPES\_NOOPTIMIZE** (0x10000)**

****CHANGE\_LOG\_ENTRYTYPES\_OPENBYID** (0x200000)**

****CHANGE\_LOG\_ENTRYTYPES\_SIMULATEDELETE** (0x80000)**

****CHANGE\_LOG\_ENTRYTYPES\_STREAMCHANGE** (0x1)**

****CHANGE\_LOG\_ENTRYTYPES\_STREAMCREATE** (0x2000)**

****CHANGE\_LOG\_ENTRYTYPES\_STREAMOVERWRITE** (0x8)**

****CHANGE\_LOG\_ENTRYTYPES\_VOLUMEERROR** (0x1000)**

**dwEntryFlags**

This member can be one of the following values:

**CHANGE\_LOG\_ENTRYFLAGS\_ACLINFO (0x4)**

**CHANGE\_LOG\_ENTRYFLAGS\_DEBUGINFO (0x8)**

**CHANGE\_LOG\_ENTRYFLAGS\_SECONDPATH (0x2)**

**CHANGE\_LOG\_ENTRYFLAGS\_SHORTNAME (0x10)**

**CHANGE\_LOG\_ENTRYFLAGS\_TEMPPATH (0x1)**

**dwAttributes**

The file attributes of the change log file. If no attributes are specified, this value should be set to 0xFFFFFFFF.

**i64SequenceNum**

The sequence number assigned to the change log entry.

**szProcName**

The name of the process making the change.

## Remarks

This structure is followed by a variable number of variable-length data records, plus a **DWORD** value that should be identical to the value of the **dwRecordSize** member of **RecordHeader**.

The variable-length data records consist of a [**RECORD\_HEADER**](https://learn.microsoft.com/windows/win32/sr/record-header) structure plus data that can be used to restore the change log entry. The format of the data depends on the value of the **dwRecordType** member of the **RECORD\_HEADER** structure.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows XP with SP2<br> |

