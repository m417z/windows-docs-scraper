# smiVALUE structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The WinSNMP
**smiVALUE** structure describes the value associated with a variable name in a variable binding entry.

The **syntax** member of the
**smiVALUE** structure contains a WinSNMP data type that indicates the type of data in the **value** member. The **value** member of the structure is the union of all possible WinSNMP data types.

## Members

### `syntax`

Type: **smiUINT32**

Specifies an unsigned long integer that indicates the syntax data type of the **value** member. This member can be only one of the types listed in the following table. For more information, see
[WinSNMP Data Types](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-types) and RFC 1902, "Structure of Management Information for Version 2 of the Simple Network Management Protocol (SNMPv2)."

| Syntax data type | Meaning |
| --- | --- |
| ****SNMP_SYNTAX_INT**** | Indicates a 32-bit signed integer variable. |
| ****SNMP_SYNTAX_OCTETS**** | Indicates an octet string variable that is binary or textual data. |
| ****SNMP_SYNTAX_NULL**** | Indicates a **NULL** value. |
| ****SNMP_SYNTAX_OID**** | Indicates an object identifier variable that is an assigned name with a maximum of 128 subidentifiers. |
| ****SNMP_SYNTAX_INT32**** | Indicates a 32-bit signed integer variable. |
| ****SNMP_SYNTAX_IPADDR**** | Indicates a 32-bit Internet address variable. |
| ****SNMP_SYNTAX_CNTR32**** | Indicates a counter variable that increases until it reaches a maximum value of (2^32) – 1. |
| ****SNMP_SYNTAX_GAUGE32**** | Indicates a gauge variable that is a non-negative integer that can increase or decrease, but never exceed a maximum value. |
| ****SNMP_SYNTAX_TIMETICKS**** | Indicates a counter variable that measures the time in hundredths of a second, until it reaches a maximum value of (2^32) – 1. It is a non-negative integer that is relative to a specific timer event. |
| ****SNMP_SYNTAX_OPAQUE**** | This type provides backward compatibility, and should not be used for new object types. It supports the capability to pass arbitrary Abstract Syntax Notation One (ASN.1) syntax. |
| ****SNMP_SYNTAX_CNTR64**** | Indicates a counter variable that increases until it reaches a maximum value of (2^64) – 1. |
| ****SNMP_SYNTAX_UINT32**** | Indicates a 32-bit unsigned integer variable. |
| ****SNMP_SYNTAX_NOSUCHOBJECT**** | Indicates that the agent does not support the object type that corresponds to the variable. |
| ****SNMP_SYNTAX_NOSUCHINSTANCE**** | Indicates that the object instance does not exist for the operation. |
| ****SNMP_SYNTAX_ENDOFMIBVIEW**** | Indicates the WinSNMP application is attempting to reference an object identifier that is beyond the end of the MIB tree that the agent supports. |

The last three syntax types describe exception conditions under the SNMP version 2C (SNMPv2C) framework.

### `value`

Specifies the union of all possible WinSNMP syntax data types, including the
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) or
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) descriptor types.

#### sNumber

**Type: **smiINT****
Specifies a signed long integer value.

#### uNumber

**Type: **smiUINT32****
Specifies a 32-bit unsigned long integer value.

#### hNumber

**Type: **smiCNTR64****
Specifies a 64-bit unsigned integer value

#### string

**Type: **smiOCTETS****
Specifies a string.

#### oid

**Type: **smiOID****
Specifies an object identifier (OID).

#### empty

**Type: **smiBYTE****
Specifies an empty member.

### `sNumber`

### `uNumber`

### `hNumber`

### `string`

### `oid`

### `empty`

## Remarks

A WinSNMP application must check the **syntax** member of an
**smiVALUE** structure to correctly dereference the **value** member. The **value** member can contain a simple scalar value or a non-scalar value like an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) or an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) descriptor structure.

If the **syntax** member indicates that the **value** member is an
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) or an
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) descriptor structure, the WinSNMP application must determine whether to free the resources allocated for the structure. The Microsoft WinSNMP implementation allocates and deallocates memory for all output
[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets) and
[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid) structures. The application must call the
[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor) function to free the memory for the **ptr** member of these structures.

Because the WinSNMP application allocates memory for input descriptors with variable lengths, it must free that memory. For more information, see
[WinSNMP Data Management Concepts](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-data-management-concepts).

## See also

[SnmpCreateVbl](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatevbl)

[SnmpFreeDescriptor](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpfreedescriptor)

[SnmpGetVb](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetvb)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)

[WinSNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-structures)

[smiOCTETS](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioctets)

[smiOID](https://learn.microsoft.com/windows/desktop/api/winsnmp/ns-winsnmp-smioid)