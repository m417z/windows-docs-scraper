# MpThreatQuery function

Used to query static (such as severity and category) or localized (such as category description and advice) information about a particular threat.

## Parameters

*hMpHandle* \[in\]

Type: **MPHANDLE**

Handle to the malware protection manager interface. This handle is returned by the [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) function.

*ThreatID* \[in\]

Type: **MPTHREAT\_ID**

Threat identifier for which information is requested.

*ppThreatInfo* \[out\]

Type: **PMPTHREAT\_INFO\***

Returns a pointer to a threat information structure, [**MPTHREAT\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-info). The structure contains information such as threat id, name, and severity.

*ppThreatLocalizedInfo* \[out, optional\]

Type: **PMPTHREAT\_LOCALIZED\_INFO\***

Returns a pointer to a structure containing localized information about the threat. You can pass **NULL** if you are not interested in localized information about the threat. See [**MPTHREAT\_LOCALIZED\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-localized-info).

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

[**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen)

[**MPTHREAT\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-info)

[**MPTHREAT\_LOCALIZED\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-localized-info)

