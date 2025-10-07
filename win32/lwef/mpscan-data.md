# MPSCAN\_DATA structure

Scan data passed to the callback.

This structure contains cumulative threat and resource statistics. These stat fields are always valid.

## Members

**ScanType**

Type: **[**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type)**

Scan type.

**ResourceInfo**

Type: **PMPRESOURCE\_INFO**

Resource information. See [**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info).

**ResourceStats**

Type: **[**MPRESOURCE\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpresource-stats)**

Resource-related cumulative statistics.

**ThreatStats**

Type: **[**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats)**

Threat statistics with successful scan completions.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info)

[**MPRESOURCE\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpresource-stats)

[**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type)

[**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats)

