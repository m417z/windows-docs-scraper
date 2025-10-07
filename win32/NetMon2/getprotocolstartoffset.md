# GetProtocolStartOffset function

The **GetProtocolStartOffset** function returns the offset of a specified protocol in the frame.

## Parameters

*hFrame*

A handle to the frame.

*ProtocolName*

The Protocol name, such as TCP.

## Return value

If the function is successful, the return value is a **DWORD** offset to the beginning of the protocol being searched for a return value of zero indicates the protocol is the first protocol in the frame.

If the function is unsuccessful, the protocol is not in the frame, the return value is -1.

## Remarks

When given the handle to a frame, this function returns the offset to a specified protocol in the frame. For example, to determine whether the frame is a DNS frame, the DNS parser requires the port address of the TCP protocol. The DNS parser would call this function with TCP as the *ProtocolName* value. If the frame is recognized by the TCP protocol, the **WORD** offset from the beginning of the frame to the beginning of the TCP frame is returned. If there is no TCP protocol, the return value is zero.

This function finds the beginning of a protocol in a frame.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

