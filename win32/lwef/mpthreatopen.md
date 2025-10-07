# MpThreatOpen function

Returns an enumeration handle for the purpose of retrieving threats. This function can be used to open threats detected by a specific scan, all the active threats in the system, the history of threat disinfection, or all the threats present in the signature database.

## Parameters

*hScanHandle* \[in\]

Type: **MPHANDLE**

Can be a handle to a completed scan operation, returned by the [**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart) function. Alternately, this parameter can be set to the malware protection manager interface handle returned by [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) to enumerate all active threats in the system, the history of threat disinfection, or threats from signature database.

*ThreatSource* \[in\]

Type: **MPTHREAT\_SOURCE**

Used to control the source of threat enumeration. The possible values for this parameter are:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------|
| **MPTHREAT\_SOURCE\_SCAN** | Threats that are associated with the specific scan handle.<br> |
| **MPTHREAT\_SOURCE\_ACTIVE** | Threats that are currently active in the system.<br> |
| **MPTHREAT\_SOURCE\_HISTORY** | Threats that are acted upon and preserved as a history.<br> |
| **MPTHREAT\_SOURCE\_QUARANTINE** | Threats that are quarantined.<br> |
| **MPTHREAT\_SOURCE\_SIGNATURE** | Threats that are possible to detect with the current signature database.<br> |
| **MPTHREAT\_SOURCE\_STATE** | Threats that have been acted upon recently. ("Recently" is defined by a configurable internal setting.)<br> |

*ThreatType* \[in\]

Type: **MPTHREAT\_TYPE**

Used to filter enumerated threats based on the detection type. The possible values for this parameter are:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| **MPTHREAT\_TYPE\_KNOWNBAD** | Detection is performed based on a specific signature, emulation, or other threat detection method.<br> |
| **MPTHREAT\_TYPE\_SUSPICIOUS** | Detection is performed based on behavior monitoring.<br> |
| **MPTHREAT\_TYPE\_UNKNOWN** | Detection is performed based on unknown threats (unclassified).<br> |
| **MPTHREAT\_TYPE\_KNOWNGOOD** | Detection is performed based on known safe threats.<br> |
| **MPTHREAT\_TYPE\_NIS** | Detection is performed based on NIS threats.<br> |

*phThreatEnumHandle* \[out\]

Type: **PMPHANDLE**

Returned threat enumeration handle which identifies the enumeration context. This handle can be used to enumerate threat information using [**MpThreatEnumerate**](https://learn.microsoft.com/windows/win32/lwef/mpthreatenumerate). The handle must be closed with the [**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose) function.

## Return value

Type: **HRESULT**

If the function succeeds the return value is **S\_OK**.

If the function fails then the return value is a failed **HRESULT** code. The caller can use the [**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat) function to get a generic description of the error message.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |
| DLL<br> | MpClient.dll |

## See also

[**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat)

[**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose)

[**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen)

[**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart)

[**MpThreatEnumerate**](https://learn.microsoft.com/windows/win32/lwef/mpthreatenumerate)

