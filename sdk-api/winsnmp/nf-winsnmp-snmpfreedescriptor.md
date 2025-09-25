# SnmpFreeDescriptor function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

A WinSNMP application uses the
**SnmpFreeDescriptor** function to inform the Microsoft WinSNMP implementation that it no longer requires access to a descriptor object. This WinSNMP function signals the implementation to free the memory it allocated for the descriptor object.

## Parameters

### `syntax` [in]

Specifies the syntax data type of the target descriptor object.

### `descriptor` [in]

Pointer to an **smiOPAQUE** structure that contains the target descriptor object to release.

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SYNTAX_INVALID** | The *syntax* parameter is invalid. |
| **SNMPAPI_OPERATION_INVALID** | The *descriptor* parameter is invalid. For additional information, see the following Remarks section. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The implementation allocates and deallocates memory for output descriptor objects with variable lengths. This memory allocation and deallocation are restricted to the implementation, except for the interface that the
**SnmpFreeDescriptor** function provides. For additional information, see
[Freeing WinSNMP Descriptors](https://learn.microsoft.com/windows/desktop/SNMP/freeing-winsnmp-descriptors).

The implementation returns the SNMPAPI_OPERATION_INVALID error code if the *descriptor* parameter specifies a memory allocation that the implementation released in a prior call to
**SnmpFreeDescriptor**. The function returns the same error code if the *descriptor* parameter specifies a memory allocation that the implementation did not make for the calling WinSNMP application.

## See also

[SnmpEncodeMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpencodemsg)

[SnmpOidCopy](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpoidcopy)

[SnmpStrToOid](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtooid)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)