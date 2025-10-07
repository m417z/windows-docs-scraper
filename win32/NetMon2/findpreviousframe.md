# FindPreviousFrame function

The **FindPreviousFrame** function finds the previous frame in the current capture context that matches the filter.

## Parameters

*hCurrentFrame*

Handle to the frame.

*ProtocolName*

Protocol name, such as TCP.

*DestinationAddress*

Destination address of the frame that is searched for.

*SourceAddress*

Source address of the frame that is searched for.

*ProtocolOffset*

Pointer to a **WORD** that receives the protocol offset.

*OriginalFrameNumber*

Starting point of the search. By default, this function searches backward 1,000 frames from *OriginalFrameNumber* starting point. You can change the search-back distance by adding this line to the Nmapi.ini file, which is located in the \\Network Monitor directory.

MAXLOOKBACK=\

*LowestFrame*

Lowest frame number in the capture that is searched.

## Return value

If the function is successful, the return value is a handle to the previous frame.

If the function is not successful, the return value is **NULL**.

## Remarks

The capture filter is defined primarily by *ProtocolName*, which is the only required filter input; you can add *DestinationAddress* and *SourceAddress* information to increase the capture speed.

*ProtocolOffset* is returned to the calling parser, which adds this **DWORD** to the pointer returned by locking the frame (with [ParserTemporaryLockFrame](https://learn.microsoft.com/windows/win32/netmon2/parsertemporarylockframe)) to get the LPBYTE of the protocol that is being searched for. On return, the HFRAME that passed the filter is given to the parser. If the parser finds that the frame is not the one that is being sought, the parser can hand this HFRAME back to the **FindPreviousFrame** function to retrieve the next frame. The source and destination addresses, which are not required, can be passed in as **NULL**. When used, these addresses can be of type ADDRESS\_TYPE\_IP, and so on, not just MAC types.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

