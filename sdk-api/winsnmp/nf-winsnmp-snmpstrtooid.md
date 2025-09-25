# SnmpStrToOid function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**SnmpStrToOid** function converts the dotted numeric string format of an SNMP object identifier, for example, "1.2.3.4.5.6", to its internal binary representation.

## Parameters

### `string` [in]

Pointer to a **null**-terminated object identifier string to convert.

### `dstOID` [out]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure that receives the converted value.

## Return value

If the function succeeds, the return value is the number of subidentifiers in the converted object identifier. This number is also the value of the **len** member of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure pointed to by the *dstOID* parameter.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OID_INVALID** | The *string* parameter is invalid. For additional information, see the following Remarks section. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The WinSNMP application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to free resources allocated for the **ptr** member of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure pointed to by the *dstOID* parameter. On input,
**SnmpFreeDescriptor** ignores the members of this
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure. The Microsoft WinSNMP implementation overwrites the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) members if the function completes successfully.

The
**SnmpStrToOid** function fails and returns the SNMPAPI_OID_INVALID error code if the *string* parameter meets one of the following conditions:

* Is not **null**-terminated.
* Is not the textual form of a valid object identifier.
* Is insufficient in length; all object identifiers must have two subidentifiers.
* Exceeds the MAXOBJIDSTRSIZE of 1408 bytes.

For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts) and
[Freeing WinSNMP Descriptors](https://learn.microsoft.com/windows/desktop/SNMP/freeing-winsnmp-descriptors).

## See also

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)