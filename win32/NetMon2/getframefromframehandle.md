# GetFrameFromFrameHandle function

The **GetFrameFromFrameHandle** function returns a pointer to a frame from a frame handle.

## Parameters

*hFrame* \[in\]

Handle to the frame.

## Return value

If the function is successful, the return value is a pointer to the frame.

If the function is unsuccessful, the return value is 0.

## Remarks

The **GetFrameFromFrameHandle** function retrieves data that cannot be retrieved by the other helper functions that Network Monitor provides. Use the following functions whenever possible.

[**GetFrameDstAddressOffset**](https://learn.microsoft.com/windows/win32/netmon2/getframedstaddressoffset)
[**GetFrameSrcAddressOffset**](https://learn.microsoft.com/windows/win32/netmon2/getframesrcaddressoffset)
[**GetFrameCaptureHandle**](https://learn.microsoft.com/windows/win32/netmon2/getframecapturehandle)
[**GetFrameDestAddress**](https://learn.microsoft.com/windows/win32/netmon2/getframedestaddress)
[**GetFrameSourceAddress**](https://learn.microsoft.com/windows/win32/netmon2/getframesourceaddress)
[**GetFrameMacHeaderLength**](https://learn.microsoft.com/windows/win32/netmon2/getframemacheaderlength)
[**GetFrameLength**](https://learn.microsoft.com/windows/win32/netmon2/getframelength)
[**GetFrameStoredLength**](https://learn.microsoft.com/windows/win32/netmon2/getframestoredlength)
[**GetFrameMacType**](https://learn.microsoft.com/windows/win32/netmon2/getframemactype)
[**GetFrameNumber**](https://learn.microsoft.com/windows/win32/netmon2/getframenumber)
[**GetFrameTimeStamp**](https://learn.microsoft.com/windows/win32/netmon2/getframetimestamp)

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameFromFrameHandle** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

