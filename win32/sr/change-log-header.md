# CHANGE\_LOG\_HEADER structure

\[This information applies only to Windows XP with Service Pack 2 (SP2).\]

The change log header.

## Members

**RecordHeader**

A [**RECORD\_HEADER**](https://learn.microsoft.com/windows/win32/sr/record-header) structure. The **dwRecordType** member should be set to RecordTypeLogHeader (0). The **dwRecordSize** member should account for all the members, plus the extra **DWORD** value that follows this header. For more information, see Remarks.

**dwMagicNum**

This member should be set to 0xabcdef12.

**dwLogVersion**

This member should be set to 2.

**DataHeader**

A [**RECORD\_HEADER**](https://learn.microsoft.com/windows/win32/sr/record-header) structure. The **dwRecordType** member should be set to **RecordTypeVolumePath** (2).

**byteData**

The start of a null-terminated string that specifies the volume path.

## Remarks

This header is followed by a **DWORD** value that should be identical to the value of the **dwRecordSize** member of **RecordHeader**.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows XP with SP2<br> |

