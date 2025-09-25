# RegisterApplicationRecoveryCallback function

## Description

Registers the active instance of an application for recovery.

## Parameters

### `pRecoveyCallback` [in]

A pointer to the recovery callback function. For more information, see [ApplicationRecoveryCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa373202(v=vs.85)).

### `pvParameter` [in, optional]

A pointer to a variable to be passed to the callback function. Can be **NULL**.

### `dwPingInterval` [in]

The recovery ping interval, in milliseconds. By default, the interval is 5 seconds (RECOVERY_DEFAULT_PING_INTERVAL). The maximum interval is 5 minutes. If you specify zero, the default interval is used.

You must call the [ApplicationRecoveryInProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-applicationrecoveryinprogress) function within the specified interval to indicate to ARR that you are still actively recovering; otherwise, WER terminates recovery. Typically, you perform recovery in a loop with each iteration lasting no longer than the ping interval. Each iteration performs a block of recovery work followed by a call to **ApplicationRecoveryInProgress**. Since you also use **ApplicationRecoveryInProgress** to determine if the user wants to cancel recovery, you should consider a smaller interval, so you do not perform a lot of work unnecessarily.

### `dwFlags` [in]

Reserved for future use. Set to zero.

## Return value

This function returns **S_OK** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Internal error; the registration failed. |
| **E_INVALIDARG** | The ping interval cannot be more than five minutes. |

## Remarks

If the application encounters an unhandled exception or becomes unresponsive, Windows Error Reporting (WER) calls the specified recovery callback. You should use the callback to save data and state information. You can use the information if you also call the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function to request that WER restart the application.

WER will not call your recovery callback if an installer wants to update a component of your application. To save data and state information in the update case, you should handle the [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) and [WM_ENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-endsession) messages. For details, see each message. The timeout for responding to these messages is five seconds. Most of the available recovery time is in the [WM_CLOSE](https://learn.microsoft.com/windows/desktop/winmsg/wm-close) message for which you have 30 seconds.

A console application that can be updated uses the CTRL_C_EVENT notification to initiate recovery (for details, see the [HandlerRoutine](https://learn.microsoft.com/windows/console/handlerroutine) callback function). The timeout for the handler to complete is 30 seconds.

Applications should consider saving data and state information on a periodic bases to shorten the amount of time required for recovery.

## See also

[ApplicationRecoveryCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa373202(v=vs.85))

[ApplicationRecoveryInProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-applicationrecoveryinprogress)

[RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart)

[UnregisterApplicationRecoveryCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-unregisterapplicationrecoverycallback)