# MpManagerVersionQuery function

Returns version information about various components of the malware protection manager.

## Parameters

*hMpHandle* \[in\]

Type: **MPHANDLE**

Handle to the malware protection manager interface. This handle is returned by the [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) function.

*pVersionInfo* \[out\]

Type: **PMPVERSION\_INFO**

Pointer to a structure that contains version information about various components of the malware protection manager. See [**MPVERSION\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpversion-info).

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

[**MPVERSION\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpversion-info)

