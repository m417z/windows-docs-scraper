# MpFreeMemory function

Frees memory for the malware protection manager. All buffers allocated and returned by malware protection functions must be freed by the caller using this function.

## Parameters

*pMemory* \[in\]

Type: **PVOID**

A pointer to memory allocated by a malware protection function.

## Return value

This function does not return a value.

## Remarks

To facilitate memory management for clients, the malware protection manager also defines macros to free memory associated with various structures returned by malware protection functions. The following macros are defined in the header file mpmemfree.h:

| Name | Description |
|---------------------------------|----------------------------------------------------------------------------------|
| MPRESOURCE\_INFO\_FREE | Frees an allocated [**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info). |
| MPTHREAT\_INFO\_FREE | Frees an allocated [**MPTHREAT\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-info). |
| MPTHREAT\_LOCALIZED\_INFO\_FREE | Frees an allocated [**MPTHREAT\_LOCALIZED\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-localized-info). |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |
| DLL<br> | MpClient.dll |

## See also

[**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat)

[**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info)

[**MPTHREAT\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-info)

[**MPTHREAT\_LOCALIZED\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-localized-info)

