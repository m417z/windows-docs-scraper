# WFDDisplaySinkStop function

Stops the Miracast sink mode, turns off discoverability, and un-registers the callback. Your app should call this once on shutdown.

## Parameters

This function has no parameters.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

## Remarks

It is expected that your app has unblocked any callbacks in progress before calling **WFDStopDisplaySink**.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| End of client support<br> | Windows 10<br> |
| End of server support<br> | Windows Server 2016<br> |
| Header<br> | Wfdsink.h |
| Library<br> | Wifidisplay.lib |
| DLL<br> | Wifidisplay.dll |

