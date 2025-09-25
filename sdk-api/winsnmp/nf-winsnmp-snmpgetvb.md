# SnmpGetVb function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

A WinSNMP application calls the
**SnmpGetVb** function to retrieve information from a variable bindings list. This WinSNMP function retrieves a variable name and its associated value from the variable binding entry specified by the *index* parameter.

## Parameters

### `vbl` [in]

Handle to the variable bindings list to retrieve.

### `index` [in]

Specifies an unsigned long integer variable that identifies the variable binding entry to retrieve. This variable contains the position of the variable binding entry, within the variable bindings list.

Valid values for this parameter are in the range from 1 to n, where 1 indicates the first variable binding entry in the variable bindings list, and n is the total number of entries in the list. For additional information, see the following Remarks section.

### `name` [out]

Pointer to an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure to receive the variable name of the variable binding entry.

### `value` [out]

Pointer to an
[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue) structure to receive the value associated with the variable identified by the *name* parameter.

If the function succeeds, the **syntax** member of the structure pointed to by the *value* parameter can be one of the following syntax data types. For additional information, see RFC 1902, "Structure of Management Information for Version 2 of the Simple Network Management Protocol (SNMPv2)."

| Syntax data type | Meaning |
| --- | --- |
| ****SNMP_SYNTAX_INT**** | Indicates a 32-bit signed integer variable. |
| ****SNMP_SYNTAX_OCTETS**** | Indicates an octet string variable that is binary or textual data. |
| ****SNMP_SYNTAX_NULL**** | Indicates a **NULL** value. |
| ****SNMP_SYNTAX_OID**** | Indicates an object identifier variable that is an assigned name with a maximum of 128 subidentifiers. |
| ****SNMP_SYNTAX_INT32**** | Indicates a 32-bit signed integer variable. |
| ****SNMP_SYNTAX_IPADDR**** | Indicates a 32-bit Internet address variable. If SNMPv1 PDU trap format is used to represent an IPv6 address, this value is 0.0.0.0. |
| ****SNMP_SYNTAX_CNTR32**** | Indicates a counter variable that increases until it reaches a maximum value of (2^32) – 1. |
| ****SNMP_SYNTAX_GAUGE32**** | Indicates a gauge variable that is a non-negative integer that can increase or decrease, but never exceed a maximum value. |
| ****SNMP_SYNTAX_TIMETICKS**** | Indicates a counter variable that measures the time in hundredths of a second, until it reaches a maximum value of (2^32) – 1. It is a non-negative integer that is relative to a specific timer event. |
| ****SNMP_SYNTAX_OPAQUE**** | This type provides backward compatibility, and should not be used for new object types. It supports the capability to pass arbitrary Abstract Syntax Notation One (ASN.1) syntax. |
| ****SNMP_SYNTAX_CNTR64**** | Indicates a counter variable that increases until it reaches a maximum value of (2^64) – 1. |
| ****SNMP_SYNTAX_UINT32**** | Indicates a 32-bit unsigned integer variable. |
| ****SNMP_SYNTAX_NOSUCHOBJECT**** | Indicates that the agent does not support the object type that corresponds to the variable. |
| ****SNMP_SYNTAX_NOSUCHINSTANCE**** | Indicates that the object instance does not exist for the operation. |
| ****SNMP_SYNTAX_ENDOFMIBVIEW**** | Indicates the WinSNMP application is attempting to reference an object identifier that is beyond the end of the MIB tree that the agent supports. |

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror). The
**SnmpGetLastError** function can return one of the following errors.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The [SnmpStartup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstartup) function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_INDEX_INVALID** | The *index* parameter is invalid. |
| **SNMPAPI_VBL_INVALID** | The *vbl* parameter is invalid. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

The last three syntax types describe exception conditions under the SNMP version 2C(SNMPv2C) framework.

The
**SnmpGetVb** function returns the variable name of the variable binding entry in the structure pointed to by the *name* parameter. It returns the variable's associated value in the structure pointed to by the *value* parameter.

On input, the
**SnmpGetVb** function ignores the members of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) and
[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue) structures pointed to by the *name* and *value* parameters respectively. The Microsoft WinSNMP implementation overwrites the members if the function completes successfully.

Valid values for a WinSNMP application to use for the *index* parameter are as follows:

* The return value from a call to the
  [SnmpCountVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcountvbl) function
* The error index field of an **SNMP_PDU_RESPONSE** protocol data unit (PDU) returned by a call to the
  [SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function

The WinSNMP application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to free resources allocated for the **ptr** member of the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure pointed to by the *name* parameter. The application must also call the
**SnmpFreeDescriptor** function to release resources allocated for the
[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue) structure pointed to by the *value* parameter under the conditions following. If the **value** member is an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) or an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structure, the application must call
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) to free the resources allocated for these structures. For additional information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpCountVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcountvbl)

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)

[smiVALUE](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smivalue)