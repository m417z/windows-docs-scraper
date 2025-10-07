# GetCaptureMacType function

The **GetCaptureMacType** function returns the MAC type of a given capture.

## Parameters

*hCapture* \[in\]

Handle to the capture. For information about obtaining the capture handle, see the Remarks section in this **GetCaptureMacType** topic.

## Return value

If the function is successful, the return value is one of the following MAC types.

- MAC\_TYPE\_UNKNOWN
- MAC\_TYPE\_ETHERNET
- MAC\_TYPE\_TOKENRING
- MAC\_TYPE\_FDDI

If the function is unsuccessful, the return value is an error code.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| **NMERR\_MAC\_TYPE\_UNKNOWN** | Network Monitor could not find a known MAC type.<br> |

## Remarks

The handle of the capture can be obtained in several ways, depending on who makes the call. For experts, the handle is specified in the **hCapture** member of the [EXPERTSTARTUPINFO](https://learn.microsoft.com/windows/win32/netmon2/expertstartupinfo) structure. For parsers, the capture handle can be obtained by calling the [GetFrameCaptureHandle](https://learn.microsoft.com/windows/win32/netmon2/getframecapturehandle) function.

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetCaptureMacType** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

