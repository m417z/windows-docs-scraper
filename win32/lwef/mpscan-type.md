# MPSCAN\_TYPE enumeration

Type of scan performed.

## Constants

**MPSCAN\_TYPE\_UNKNOWN**

Internal use only.

**MPSCAN\_TYPE\_QUICK**

Scans running processes and various ASEP points in the system where malware typically hides.

**MPSCAN\_TYPE\_FULL**

Performs a quick scan followed by scan of all fixed drives of the system.

**MPSCAN\_TYPE\_RESOURCE**

Scans specific resources, such as files or folders.

**MPSCAN\_TYPE\_MAXVALUE**

Maximum value possible.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

