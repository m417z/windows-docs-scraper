# MpThreatEnumerate function

Returns information about the next threat in the enumeration list. This function can be called repeatedly until the enumeration of all the threats is complete.

## Parameters

*hThreatEnumHandle* \[in\]

Type: **MPHANDLE**

Handle to a threat enumeration context returned by [**MpThreatOpen**](https://learn.microsoft.com/windows/win32/lwef/mpthreatopen).

*ppThreatInfo* \[out\]

Type: **PMPTHREAT\_INFO\***

Returns a pointer to a threat information structure, [**MPTHREAT\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-info). The structure contains information such as threat id, name, and severity.

## Return value

Type: **HRESULT**

If the function succeeds the return value is **S\_OK**.

If there are no more items to return the return value is **S\_FALSE**.

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

[**MpThreatOpen**](https://learn.microsoft.com/windows/win32/lwef/mpthreatopen)

[**MPTHREAT\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-info)

