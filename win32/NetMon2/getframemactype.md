# GetFrameMacType function

The **GetFrameMacType** function returns the MAC type of the frame.

## Parameters

*hFrame* \[in\]

Handle to the frame.

## Return value

The function returns the MAC type of the frame, which can have one of the following values.

- MAC\_TYPE\_UNKNOWN
- MAC\_TYPE\_ETHERNET
- MAC\_TYPE\_TOKENRING
- MAC\_TYPE\_FDDI

## Remarks

[*Experts*](https://learn.microsoft.com/windows/win32/netmon2/e) and [*parsers*](https://learn.microsoft.com/windows/win32/netmon2/p) can call the **GetFrameMacType** function.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

