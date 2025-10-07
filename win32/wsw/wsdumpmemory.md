# WsDumpMemory function

This function dumps all memory allocations to the console.

> [!Note]
> This function is for DEBUG ONLY.

## Parameters

*error* \[in, optional\]

A pointer to a [WS\_ERROR](https://learn.microsoft.com/windows/win32/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps \| UWP apps\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps \| UWP apps\]<br> |
| Header<br> | WebServicesDebug.h |

