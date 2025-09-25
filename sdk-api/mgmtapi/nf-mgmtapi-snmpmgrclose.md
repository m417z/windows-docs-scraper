# SnmpMgrClose function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpMgrClose** function closes the communications sockets and data structures that are associated with the specified session. This function is an element of the SNMP Management API.

## Parameters

### `session` [in]

Pointer to an internal structure that specifies the session to close. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

 This function may return Windows Sockets error codes.

## Remarks

**Windows Server 2003:** SNMP manager applications can call
**SnmpMgrClose** with a **NULL***session* parameter to clean up the resources that are associated with a successful call to the
[SnmpMgrTrapListen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrtraplisten) function. Note, however, that if your application is a DLL, it should not call
**SnmpMgrClose** from its
[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) entry-point function.

**SnmpMgrClose** must not be called when the application DLL is in the process of unloading.

**Windows Server 2003:** **SnmpMgrClose** takes longer to execute under Windows Server 2003 when compared to an identical call under Windows 2000. Specifically, a call to this API takes up to a second to execute under Windows Server 2003, whereas the same call takes around .3 milliseconds under Windows 2000. this may cause performance problems for Windows Server 2003 SNMP applications that call [SnmpMgrOpen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgropen) and **SnmpMgrClose** frequently.

To address this problem, create an extra SNMP manager session by calling [SnmpMgrOpen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgropen) on the local host during application startup, and keep it open for the duration of the application's lifetime. Closing the session manager will close all associated sessions, requiring only one call to **SnmpMgrClose**.

**Windows Server 2003 with SP1:** The above issue does not apply to Windows 2003 Service Pack 1.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpMgrOpen](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgropen)

[SnmpMgrRequest](https://learn.microsoft.com/windows/desktop/api/mgmtapi/nf-mgmtapi-snmpmgrrequest)