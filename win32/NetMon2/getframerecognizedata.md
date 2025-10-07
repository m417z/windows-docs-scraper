# GetFrameRecognizeData function

The **GetFrameRecognizeData** function returns a table of **RECOGNIZEDATA** structures. Each of these structures contains a protocol identifier and an offset that points to the start of the specified protocol in the data.

## Parameters

*hFrame* \[in\]

Handle to a frame.

## Return value

If the function is successful, the return value is a pointer to a **RECOGNIZEDATATABLE** structure.

If the function is not successful, the return value is zero.

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameRecognizeData** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

