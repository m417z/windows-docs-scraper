# SnmpCleanupEx function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpCleanupEx** function performs cleanup when there are no outstanding successful calls to [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) or [SnmpStartupEx](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartupex) within a Windows SNMP (WinSNMP) application. Otherwise, an internal reference count indicating the current number of outstanding successful calls to **SnmpStartupEx** is decremented.

This function should be used instead of [SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) if Windows Server 2003 with Service Pack 1 (SP1) or later is installed. **SnmpCleanupEx** enables support for multiple independent software modules that use WinSNMP within the same application.

**Note** A WinSNMP application must call the
**SnmpCleanupEx** function for each successful call to [SnmpStartupEx](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartupex) before the application terminates.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS. Until the WinSNMP application successfully recalls the
corresponding [SnmpStartupEx](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartupex) function and there are no additional outstanding successful calls to either [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) or **SnmpStartupEx**, any other call to a WinSNMP function within the same application returns SNMPAPI_FAILURE, with an extended error code of SNMPAPI_NOT_INITIALIZED.

If the function fails, the return value is SNMPAPI_FAILURE, but the WinSNMP application does not need to retry the call to
**SnmpCleanupEx**. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OTHER_ERROR** | The [SnmpStartupEx](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartupex) function did not complete successfully, or an unknown or undefined error occurred. |

## Remarks

Before the WinSNMP application calls
**SnmpCleanupEx**, it should call the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) function once for each session the implementation opens as a result of a call to the
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function.

When a WinSNMP application calls the
**SnmpCleanupEx** function, the implementation deallocates all resources allocated to the application if there are also no outstanding successful calls to either [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) or [SnmpStartupEx](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartupex). However, it is recommended that a WinSNMP application free the specific resources that the implementation allocates for it with the WinSNMP function that corresponds to the resource. For additional information about freeing individual resources, see
[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity),
[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl),
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor),
[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext), and
[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu).

If a WinSNMP application must perform an emergency exit, and it calls
**SnmpCleanupEx** without freeing individual resources and without calling
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) for every open session, the implementation deallocates all resources allocated to the WinSNMP application. However, to enable this functionality in the implementation, the application must still call
**SnmpCleanupEx**.

**SnmpCleanupEx** must not be called when the application DLL is in the process of unloading.

## See also

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession)

[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext)

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[SnmpFreeEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreeentity)

[SnmpFreePdu](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreepdu)

[SnmpFreeVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreevbl)

[SnmpStartupEx](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartupex)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)