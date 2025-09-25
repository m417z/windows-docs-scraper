# SnmpMgrTrapListen function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrTrapListen** function registers the ability of an SNMP manager application to receive SNMP traps from the SNMP Trap Service. This function is an element of the SNMP Management API.

## Parameters

### `phTrapAvailable` [out]

Pointer to an event handle to receive an indication that there are traps available, and that the application should call the
[SnmpMgrGetTrap](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrgettrap) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which may return any of the following error codes.

| Return code | Description |
| --- | --- |
| **SNMP_MEM_ALLOC_ERROR** | Indicates a memory allocation error. |
| **SNMP_MGMTAPI_TRAP_DUPINIT** | Indicates that this function has already been called. |
| **SNMP_MGMTAPI_TRAP_ERRORS** | Indicates one or more errors occurred; traps are not accessible. The application can attempt to call the function again. |

This function may return other system errors as well.

## Remarks

It is important to note that for users who are not administrators, the
**SnmpMgrTrapListen** function succeeds only if the SNMP trap service has been started.

The application must always call the
**SnmpMgrTrapListen** function before calling the
[SnmpMgrGetTrap](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrgettrap) function. This is because the event handle pointed to by the *phTrapAvailable* parameter enables the event-driven acquisition of SNMP traps. The SNMP Management API signals an application's event when the SNMP Trap Service delivers a trap.

The application can also poll the
[SnmpMgrGetTrap](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrgettrap) function for traps at regular intervals. In this case, the application should repeatedly call
**SnmpMgrGetTrap** until the function returns zero.

**Windows Server 2003:** SNMP manager applications can call
[SnmpMgrClose](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrclose) with a **NULL***session* parameter to clean up resources associated with a successful call to the
**SnmpMgrTrapListen** function. Note, however, that if your application is a DLL, it should not call
**SnmpMgrClose** from its
[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) entry-point function.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrGetTrap](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrgettrap)