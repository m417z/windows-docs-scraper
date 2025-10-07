# MPRESOURCE\_STATS structure

Resource-related statistics.

## Members

**PPMProgress**

Type: **DWORD**

Approximate progress for scan in ppm (parts per million). Set to **MPPROGRESS\_INVALID** if progress information is not available.

**ProcessCount**

Type: **UINT64**

Number of processes scanned.

**FileCount**

Type: **UINT64**

Number of files scanned.

**FileBytesCount**

Type: **UINT64**

Number of bytes scanned for files.

**RegKeyCount**

Type: **UINT64**

Number of RegKeys scanned.

**Reserved**

Type: **UINT64\[4\]**

Fields reserved for future use.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

