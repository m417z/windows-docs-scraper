# WsSetAutoFail function

Sets the next point to inject a failure. This is a DEBUG ONLY function.

## Parameters

*count* \[in\]

Specifies how many operations before failures begin to occur.

*error* \[in, optional\]

A pointer to a [WS\_ERROR](https://learn.microsoft.com/windows/win32/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | WebServicesDebug.h |

