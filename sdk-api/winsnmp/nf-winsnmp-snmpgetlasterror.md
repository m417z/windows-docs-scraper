# SnmpGetLastError function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpGetLastError** function returns the calling application's last-error code value. The value indicates the reason why the last function call executed by the WinSNMP application failed.

## Parameters

### `session` [in]

Handle to the WinSNMP session. This parameter can also be **NULL**.

In certain cases, when a function call fails you can pass a **NULL***session* value to the
**SnmpGetLastError** function to retrieve the last-error code value. This is true for function calls that do not involve a *session* parameter, and cases in which the *session* parameter value is invalid. These cases are noted in the Return Values section on the function's reference page.

A single-thread application can pass a **NULL***session* value to
**SnmpGetLastError** to retrieve last-error information for the entire application.

For more information, see the following Remarks and Return Values sections.

## Return value

If the *session* parameter is a valid WinSNMP session handle, the
**SnmpGetLastError** function returns the last WinSNMP error that occurred for the indicated session.

If the *session* parameter is **NULL** — for example, if the
[SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function fails,
**SnmpGetLastError** returns the last WinSNMP error that occurred.

## Remarks

A WinSNMP application must call
**SnmpGetLastError** immediately after a function fails, to retrieve the last-error code. If another function fails, it overwrites the last-error code set by the most recently failed function. For more information, see
[WinSNMP Error Codes](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-error-codes).

Although the *session* parameter accommodates both multithread and single-thread Windows operating environments, the potential still exists for the last-error code from one thread to overwrite the last-error code from another thread.

Note that
**SnmpGetLastError** must be able to return the last-error code to a WinSNMP application under the following conditions:

* After the
  [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function fails
* Before the
  [SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function creates any WinSNMP sessions for the instance of the application
* After the
  [SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) function closes all WinSNMP sessions for the instance of the application
* After the
  [SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) function disconnects the WinSNMP application from the Microsoft WinSNMP implementation

## See also

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession)

[SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)