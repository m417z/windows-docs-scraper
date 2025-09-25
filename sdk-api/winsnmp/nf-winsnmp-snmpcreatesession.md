# SnmpCreateSession function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpCreateSession** function requests the Microsoft WinSNMP implementation to open a session for the WinSNMP application. The application can specify how the implementation should inform the WinSNMP session of available SNMP messages and asynchronous events. The application can specify a window notification message or an
[SNMPAPI_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winsnmp/nc-winsnmp-snmpapi_callback) function to notify the session.

The
**SnmpCreateSession** function is an element of the WinSNMP API, version 2.0. When developing new WinSNMP applications, it is recommended that you call
**SnmpCreateSession** to open a WinSNMP session instead of calling the
[SnmpOpen](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpopen) function.

## Parameters

### `hWnd` [in]

Handle to a window of the WinSNMP application to notify when an asynchronous request completes, or when trap notification occurs. This parameter is required for window notification messages for the session.

### `wMsg` [in]

Specifies an unsigned integer that identifies the notification message to send to the WinSNMP application window. This parameter is required for window notification messages for the session.

### `fCallBack` [in]

Specifies the address of an application-defined, session-specific
[SNMPAPI_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winsnmp/nc-winsnmp-snmpapi_callback) function. The implementation will call this function to inform the WinSNMP session when notifications are available.

This parameter is required to specify callback notifications for the session. This parameter must be **NULL** to specify window notification messages for the session. For additional information, see the following Remarks section.

### `lpClientData` [in]

Pointer to application-defined data to pass to the callback function specified by the *fCallback* parameter. This parameter is optional and can be **NULL**. If the *fCallback* parameter is **NULL**, the implementation ignores this parameter.

## Return value

If the function succeeds, the return value is a handle that identifies the WinSNMP session that the implementation opens for the calling application.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_HWND_INVALID** | The *fCallback* parameter is **NULL**, but the *hWnd* parameter is not a valid window handle. |
| **SNMPAPI_MESSAGE_INVALID** | The *fCallback* parameter is **NULL**, but the *wMsg* parameter is not a valid message value. |
| **SNMPAPI_MODE_INVALID** | The *fCallback* parameter is **NULL** and the *hWnd* and *wMsg* parameters are valid individually. However, the values are mutually incompatible on the Windows platform. |
| **SNMPAPI_OPERATION_INVALID** | The combination of parameter values does not specify callback notifications or window notification messages. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The
**SnmpCreateSession** function returns a unique handle to each open WinSNMP session within the calling WinSNMP application. The application must use the session handle that
**SnmpCreateSession** returns in other WinSNMP function calls to facilitate allocation and deallocation of resources by the implementation.

It is recommended that a WinSNMP application call the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) function once for each session that the implementation opens as a result of a call to the
**SnmpCreateSession** function. If a WinSNMP application terminates unexpectedly, it must call
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) before it terminates to enable the implementation to deallocate all resources.

### Callback Notifications

If the *fCallback* parameter is not **NULL** on a successful call to the
**SnmpCreateSession** function, the implementation alerts the session to notifications using the callback function specified by the *fCallback* parameter.

Following is an example of a call to the
**SnmpCreateSession** function, requesting that the implementation signal the session about messages and events using callback notifications.

`hSession = SnmpCreateSession (0, 0, myFunc, <NULL|myData>);`

### Window Notification Messages

The
**SnmpCreateSession** function passes to the implementation the handle to an application window and a notification message identifier. When the application window receives the notification message specified by the *wMsg* parameter, the WinSNMP application must retrieve the incoming protocol data unit (PDU). The application does this by calling the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function with the session handle returned by
**SnmpCreateSession**.

One WinSNMP application can open multiple WinSNMP sessions. If an application opens multiple sessions using the same window handle, it is recommended that the WinSNMP application specify a unique *wMsg* parameter for each session.

Following is an example of a call to the
**SnmpCreateSession** function, requesting that the implementation signal the session about messages and events using window notification messages.

`hSession = SnmpCreateSession (myWnd, myMsg, NULL, NULL);`

## See also

[SNMPAPI_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winsnmp/nc-winsnmp-snmpapi_callback)

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)