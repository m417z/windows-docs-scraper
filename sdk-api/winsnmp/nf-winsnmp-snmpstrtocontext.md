# SnmpStrToContext function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpStrToContext** function returns a handle to SNMP context information that is specific to the Microsoft WinSNMP implementation. The handle is a valid value that a WinSNMP application can use as the *context* parameter in a call to the
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg) and
[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister) functions.

## Parameters

### `session` [in]

Handle to the WinSNMP session.

### `string` [in]

Pointer to an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure that contains a string to interpret. The string can identify a collection of managed objects, or it can be a community string.

The current setting of the entity and context translation mode determines the way
**SnmpStrToContext** interprets the input string structure as shown in the following table.

| Entity/Context Translation Mode | Meaning |
| --- | --- |
| **SNMPAPI_TRANSLATED** | The implementation interprets the *string* parameter as a user-friendly name for a collection of managed objects. The implementation translates the name into its SNMPv1 or SNMPv2C components using the implementation's database. |
| **SNMPAPI_UNTRANSLATED_V1** | The implementation interprets the *string* parameter as a literal SNMP community string. |
| **SNMPAPI_UNTRANSLATED_V2** | The implementation interprets the *string* parameter as a literal SNMP community string. |

## Return value

If the function succeeds, the return value is a handle to the context of interest.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_SESSION_INVALID** | The *session* parameter is invalid. |
| **SNMPAPI_CONTEXT_INVALID** | The *string* parameter format is invalid. For example, the **len** member or the **ptr** member of the [smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure pointed to by the *string* parameter is **NULL**. |
| **SNMPAPI_CONTEXT_UNKNOWN** | The value referenced in the *string* parameter does not exist. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The current setting of the entity and context translation mode determines the manner in which
**SnmpStrToContext** interprets the input string structure. For additional information, see
[Setting the Entity and Context Translation Mode](https://learn.microsoft.com/windows/desktop/SNMP/setting-the-entity-and-context-translation-mode).

The WinSNMP application must call the
[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext) function to release the context handle allocated by the
**SnmpStrToContext** function. For additional information about releasing resources, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

The WinSNMP application should free the memory associated with the **ptr** member of the
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) structure pointed to by the *string* parameter. This is because the application defines and allocates the resources. For example, if the application allocated resources with a call to the
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc) function, it should use the
[GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function to deallocate the resources. For additional information, see
[Freeing WinSNMP Descriptors](https://learn.microsoft.com/windows/desktop/SNMP/freeing-winsnmp-descriptors).

## See also

[SnmpFreeContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreecontext)

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister)

[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets)