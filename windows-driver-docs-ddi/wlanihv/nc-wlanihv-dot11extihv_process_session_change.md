# DOT11EXTIHV_PROCESS_SESSION_CHANGE callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvProcessSessionChange* function to notify the IHV Extensions DLL of a session change
event.

## Parameters

### `uEventType` [in]

The type of event. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| WTS_CONSOLE_CONNECT | A session was connected to the console session. |
| WTS_CONSOLE_DISCONNECT | A session was disconnected from the console session. |
| WTS_REMOTE_CONNECT | A session was connected to the remote session. |
| WTS_REMOTE_DISCONNECT | A session was disconnected from the remote session. |
| WTS_SESSION_LOGON | A user has logged on to the session. |
| WTS_SESSION_LOGOFF | A user has logged off of the session. |
| WTS_SESSION_LOCK | A session has been locked. |
| WTS_SESSION_UNLOCK | A session has been unlocked. |
| WTS_SESSION_REMOTE_CONTROL | A session has changed its remote controlled status. To determine the status, call the **GetSystemMetrics** function and check the SM_REMOTECONTROL metric. For more information about this function, refer to the Microsoft Windows SDK documentation. |

### `pSessionNotification` [in]

A pointer to a WTSSESSION_NOTIFICATION structure, which provides information about the session
change notification. For more information about this structure, refer to the Windows SDK
documentation.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_PROCESS_SESSION_CHANGE Dot11ExtIhvProcessSessionChange;

DWORD APIENTRY Dot11ExtIhvProcessSessionChange(
  _In_ ULONG                    uEventType,
  _In_ PWTSSESSION_NOTIFICATION pSessionNotification
)
{ ... }
```

## Remarks

The operating system calls the function to notify the IHV Extensions DLL whenever a switch in a user
session occurs.

If the
*uEventType* parameter is set to WTS_SESSION_LOGOFF, the IHV Extensions DLL must cancel all pending
user interface requests internally and must release any allocated resources for the user interface
requests.