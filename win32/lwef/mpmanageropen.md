# MpManagerOpen function

Establishes a connection to the malware protection manager on the local computer.

## Parameters

*dwReserved* \[in\]

Type: **DWORD**

Reserved for future use. Must be set to 0.

*phMpHandle* \[out\]

Type: **PMPHANDLE**

Handle to the malware protection manager interface. This handle must be closed with the [**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose) function.

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

[**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose)

