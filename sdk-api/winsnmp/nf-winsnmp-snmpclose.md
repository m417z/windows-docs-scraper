# SnmpClose function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpClose** function enables the Microsoft WinSNMP implementation to deallocate memory, resources, and data structures associated with a WinSNMP session. The WinSNMP
**SnmpClose** function also closes communications mechanisms the implementation opened as a result of a call to the
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function.

## Parameters

### `session` [in]

Handle to the WinSNMP session to close.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The *session* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

It is recommended that a WinSNMP application call the
**SnmpClose** function once for each session that the application opened using the
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function. If a WinSNMP application terminates unexpectedly, it must call
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) before it terminates to enable the implementation to deallocate all resources. The implementation processes one
**SnmpCleanup** call as if it were a series of
**SnmpClose** calls, one call for each session opened as a result of a call to
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession).

When the implementation closes a session it discards all outstanding incoming and outgoing asynchronous requests and replies for the session. For additional information, see
[WinSNMP Sessions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-sessions).

## See also

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)