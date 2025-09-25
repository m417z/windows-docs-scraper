# WTSGetActiveConsoleSessionId function

## Description

Retrieves the session identifier of the console session. The console session is the session that is currently attached to the physical console. Note that it is not necessary that Remote Desktop Services be running for this
function to succeed.

## Return value

The session identifier of the session that is attached to the physical console. If there is no session attached to the
physical console, (for example, if the physical console session is in the process of being attached or detached), this function
returns 0xFFFFFFFF.

## Remarks

The session identifier returned by this function is the identifier of the current physical console session. To monitor
the state of the current physical console session, use the
[WTSRegisterSessionNotification](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotification)
function.

## See also

[ProcessIdToSessionId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-processidtosessionid)

[WM_WTSSESSION_CHANGE](https://learn.microsoft.com/windows/desktop/TermServ/wm-wtssession-change)

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)

[WTSRegisterSessionNotification](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotification)