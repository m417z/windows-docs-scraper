# MpManagerStatusQueryEx function

Returns status information about various components of the malware protection manager.

## Parameters

*hMpHandle* \[in\]

Type: **MPHANDLE**

Handle to the malware protection manager interface. This handle is returned by the [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) function.

*dwFlag* \[in\]

Type: **DWORD**

Controls which query information is returned. Some information is expensive and may not be needed.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|
|

**MP\_STATUS\_QUERY\_FLAGS\_NONE**

| Default.<br> |
|

**MP\_STATUS\_QUERY\_FLAG\_NOSTATE**

| Do not query for state information.<br> |

*pStatusInfo* \[out\]

Type: **PMPSTATUS\_INFO**

Pointer to a structure that returns status information regarding last scans, active threats and various component status. See [**MPSTATUS\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-info).

## Return value

Type: **HRESULT**

If the function succeeds the return value is **S\_OK**. This function call is guaranteed to succeed even if an AntiMalware service is not running.

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

[**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen)

[**MPSTATUS\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-info)

