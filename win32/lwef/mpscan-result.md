# MPSCAN\_RESULT structure

The results of a scan.

## Members

**ScanType**

Type: **[**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type)**

Scan type. See [**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type).

**Source**

Type: **[**MPSOURCE**](https://learn.microsoft.com/windows/win32/lwef/mpsource)**

Scan source, such as user or system initiated. See [**MPSOURCE**](https://learn.microsoft.com/windows/win32/lwef/mpsource).

**ScanGuid**

Type: **GUID**

Scan identifier.

**StartTime**

Type: **ULARGE\_INTEGER**

Scan start time.

**EndTime**

Type: **ULARGE\_INTEGER**

Scan end time.

**ThreatStats**

Type: **[**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats)**

Threat-related statistics. See [**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats).

**ResourceStats**

Type: **[**MPRESOURCE\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpresource-stats)**

Resource-related statistics. See [**MPRESOURCE\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpresource-stats).

**SignatureVersion**

Type: **ULONGLONG**

Version of signature used for scan.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPRESOURCE\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpresource-stats)

[**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type)

[**MPSOURCE**](https://learn.microsoft.com/windows/win32/lwef/mpsource)

[**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats)

