# MpScanControl function

Allows the control of a scan that was asynchronously initiated via [**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart).

## Parameters

*hScanHandle* \[in\]

Type: **MPHANDLE**

Handle to an asynchronous scan operation. This handle is returned by the [**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart) function. This parameter can also be set to the malware protection manager interface handle returned by [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) function to control a system initiated scan, in which case the caller must have administrative privilege.

*ScanControl* \[in\]

Type: **MPCONTROL**

Specifies a scan control option. This parameter must be one of the following control options:

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------|
| **MPCONTROL\_ABORT** | Abort the scan operation.<br> |
| **MPCONTROL\_PAUSE** | Pause the scan operation.<br> |
| **MPCONTROL\_RESUME** | Resume the paused scan operation.<br> |

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

[**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart)

