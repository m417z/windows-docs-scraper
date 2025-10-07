# MpUpdateControl function

Allows the control of a signature update operation that was asynchronously initiated via [**MpUpdateStart**](https://learn.microsoft.com/windows/win32/lwef/mpupdatestart). Calling this function requires administrator privilege as it allows the cancellation of a system-wide signature update.

## Parameters

*hUpdateHandle* \[in\]

Type: **MPHANDLE**

Handle to an asynchronous signature update operation. This handle is returned by the [**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart) function.

*UpdateControl* \[in\]

Type: **MPCONTROL**

Specifies the signature update control option. It must be the following value:

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------|
| **MPCONTROL\_ABORT** | Abort the signature update operation.<br> |

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

[**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart)

