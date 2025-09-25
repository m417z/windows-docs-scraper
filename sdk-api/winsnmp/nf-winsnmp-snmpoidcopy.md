# SnmpOidCopy function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpOidCopy** function copies an SNMP object identifier, allocating any necessary memory for the copy.

## Parameters

### `srcOID` [in]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure to copy.

### `dstOID` [out]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure to receive a copy of the object identifier specified by the *srcOID* parameter.

## Return value

If the function succeeds, the return value is the number of subidentifiers in the copied object identifier. This number is also the value of the **len** member of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure pointed to by the *dstOID* parameter.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OID_INVALID** | The *srcOID* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

On input, the
**SnmpOidCopy** function ignores the members of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure pointed to by the *dstOID* parameter. The Microsoft WinSNMP implementation overwrites the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) members if the function completes successfully.

The WinSNMP application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to enable the implementation to free resources allocated for the **ptr** member of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure pointed to by the *dstOID* parameter. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts) and
[Freeing WinSNMP Descriptors](https://learn.microsoft.com/windows/desktop/SNMP/freeing-winsnmp-descriptors).

## See also

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)