# FindNextFrame function

The **FindNextFrame** function finds the next frame in the current capture context that matches the filter.

## Parameters

*hCurrentFrame*

A handle to the frame.

*ProtocolName*

The protocol name, such as TCP.

*DestinationAddress*

The destination address.

*SourceAddress*

The source address.

*ProtocolOffset*

A pointer to a **WORD** that will receive the protocol offset.

*OriginalFrameNumber*

The starting point of the search. By default, this function searches forward 1,000 frames from the *OriginalFrameNumber* starting point. To change the search-forward distance, add this line to the Nmapi.ini file, located in the \\Network Monitor directory.

MAXLOOKBACK=\

*HighestFrame*

The highest frame number in the capture that is searched.

## Return value

If the function is successful, the return value is a handle to the next frame.

If the function is not successful, the return value is **NULL**.

## Remarks

The capture filter is defined primarily by the *ProtocolName* parameter, which is the only required filter input; you can add *DestinationAddress* and *SourceAddress* data to increase the capture speed.

The *ProtocolOffset* pointer is returned to the calling parser, which adds the **WORD** to the pointer returned by locking the frame (with [ParserTemporaryLockFrame](https://learn.microsoft.com/windows/win32/netmon2/parsertemporarylockframe)) to get the **LPBYTE** of the protocol searched for. On return, the HFRAME that passed the filter is given to the parser. If the parser finds that this frame is not the one sought, the parser can hand the HFRAME back to the **FindNextFrame** function to get the next frame. The source and destination addresses are not required and can be passed as **NULL**.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

