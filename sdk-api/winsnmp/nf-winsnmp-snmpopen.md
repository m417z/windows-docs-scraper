# SnmpOpen function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpOpen** function requests the Microsoft WinSNMP implementation to open a session for the WinSNMP application. This WinSNMP function enables the implementation to allocate and initialize memory, resources, data structures, and communications mechanisms. The
**SnmpOpen** function returns a handle to the new WinSNMP session.

**Note** When developing new WinSNMP applications, it is recommended that you call the
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function to open a WinSNMP session instead of calling the
**SnmpOpen** function.

## Parameters

### `hWnd` [in]

Handle to a window of the WinSNMP application to notify when an asynchronous request completes, or when trap notification occurs.

### `wMsg` [in]

Specifies an unsigned integer that identifies the notification message to send to the WinSNMP application window.

## Return value

If the function succeeds, the return value is a handle that identifies the WinSNMP session that the implementation opens for the calling application.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_HWND_INVALID** | The *hWnd* parameter is not a valid window handle. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The
**SnmpOpen** function returns a unique handle to each open WinSNMP session within the calling WinSNMP application. The application must use the session handle that
**SnmpOpen** returns in other WinSNMP function calls to facilitate allocation and deallocation of resources by the implementation. When the implementation allocates resources to an individual session, it performs an orderly release of resources in response to a call to
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) for the session.

The
**SnmpOpen** function passes to the implementation the handle to an application window and a notification message identifier. If the *wParam* component of the notification message specified by the *wMsg* parameter is equal to zero, the WinSNMP application must retrieve the incoming protocol data unit (PDU). The application does this by calling the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function with the session handle returned by
**SnmpOpen**. If the *wParam* parameter of the notification message is not equal to zero, it represents a WinSNMP error code. The error code applies to the PDU identified by the request identifier in the *lParam* parameter of the notification message.

One WinSNMP application can open multiple WinSNMP sessions. If an application opens multiple sessions using the same window handle, it is recommended that the WinSNMP application specify a unique *wMsg* parameter for each session.

It is recommended that a WinSNMP application call the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) function once for each session that the implementation opens as a result of a call to the
**SnmpOpen** function. If a WinSNMP application terminates unexpectedly, it must call
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) before it terminates to enable the implementation to deallocate all resources. The implementation treats one
**SnmpCleanup** call as if it were a series of
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) calls, one call for each session the implementation opens as a result of a call to
**SnmpOpen**.

For information about opening a WinSNMP session and specifying the method used to inform the session of available SNMP messages and asynchronous events, see
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession). When you call
**SnmpCreateSession** you can specify a window notification message or an
[SNMPAPI_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winsnmp/nc-winsnmp-snmpapi_callback) function to notify the session.

For more information, see
[WinSNMP Sessions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-sessions).

## See also

[SNMPAPI_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winsnmp/nc-winsnmp-snmpapi_callback)

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)