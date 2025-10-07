# MpHandleClose function

Closes the handle returned by [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen), [**MpScanStart**](https://learn.microsoft.com/windows/win32/lwef/mpscanstart), [**MpThreatOpen**](https://learn.microsoft.com/windows/win32/lwef/mpthreatopen), or [**MpUpdateStart**](https://learn.microsoft.com/windows/win32/lwef/mpupdatestart).

## Parameters

*hMpHandle* \[in\]

Type: **MPHANDLE**

Handle to close.

## Return value

Type: **HRESULT**

If the function succeeds the return value is **S\_OK**.

If the function fails then the return value is a failed **HRESULT** code. The caller can use the [**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat) function to get a generic description of the error message.

The following specific error can be returned by the function:

| Return Code | Description |
|-------------------------|----------------------------------|
| E\_WIN\_INVALID\_HANDLE | The specified handle is invalid. |

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

[**MpThreatOpen**](https://learn.microsoft.com/windows/win32/lwef/mpthreatopen)

