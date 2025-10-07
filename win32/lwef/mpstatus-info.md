# MPSTATUS\_INFO structure

Status information for the malware protection manager.

## Members

**ProductStatus**

Type: **DWORD**

Overall product status. This is a combination of bit flags from [**MPSTATUS\_FLAG**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-flag).

**LastQuickScan**

Type: **[**MPSCAN\_RESULT**](https://learn.microsoft.com/windows/win32/lwef/mpscan-result)**

Results of the last scan by the malware protection manager. See [**MPSCAN\_RESULT**](https://learn.microsoft.com/windows/win32/lwef/mpscan-result).

**LastFullScan**

Type: **[**MPSCAN\_RESULT**](https://learn.microsoft.com/windows/win32/lwef/mpscan-result)**

Results of the last full scan by the malware protection manager. See [**MPSCAN\_RESULT**](https://learn.microsoft.com/windows/win32/lwef/mpscan-result).

**ThreatStats**

Type: **[**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats)**

Active threat statistics. See [**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats).

**ThreatState**

Type: **[**MPTHREAT\_STATS\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats-data)\[MP\_THREAT\_STAT\_MAX\_VALUE+1\]**

Additional threat statistics data, such as the number of threats. See [**MPTHREAT\_STATS\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats-data).

**Component**

Type: **[**MPCOMPONENT\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpcomponent-status)\[MPCOMPONENT\_MAXVALUE+1\]**

An array of statuses for multiple components. Use a value from the [**MPCOMPONENT\_ID**](https://learn.microsoft.com/windows/win32/lwef/mpcomponent-id) enumeration as an index into the array.

**ProductExpirationTime**

Type: **ULARGE\_INTEGER**

Product expiration timestamp in UNC. This is valid only if the expiration status is set.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPCOMPONENT\_ID**](https://learn.microsoft.com/windows/win32/lwef/mpcomponent-id)

[**MPCOMPONENT\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpcomponent-status)

[**MPSCAN\_RESULT**](https://learn.microsoft.com/windows/win32/lwef/mpscan-result)

[**MPSTATUS\_FLAG**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-flag)

[**MPTHREAT\_STATS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats)

[**MPTHREAT\_STATS\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-stats-data)

