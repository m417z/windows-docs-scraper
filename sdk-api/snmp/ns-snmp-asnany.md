# AsnAny structure

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**AsnAny** structure contains an SNMP variable type and value. This structure is a member of the
[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind) structure that is used as a parameter in many of the SNMP functions. This structure is not used by the
[WinSNMP API](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api) functions.

## Members

### `asnType`

Type: **BYTE**

Indicates the variable's type. This member must be only one of the following values.

| Value | Meaning |
| --- | --- |
| **ASN_INTEGER** | Indicates a 32-bit signed integer variable. |
| **ASN_INTEGER32** | Indicates a 32-bit signed integer variable. |
| **ASN_UNSIGNED32** | Indicates a 32-bit unsigned integer variable. For more information, see the following Remarks section. |
| **ASN_COUNTER64** | Indicates a counter variable that increases until it reaches a maximum value of (2^64) – 1. |
| **ASN_OCTETSTRING** | Indicates an octet string variable. |
| **ASN_BITS** | Indicates a variable that is an enumeration of named bits. |
| **ASN_OBJECTIDENTIFIER** | Indicates an object identifier variable. |
| **ASN_SEQUENCE** | Indicates an ASN sequence variable. |
| **ASN_IPADDRESS** | Indicates an IP address variable. |
| **ASN_COUNTER32** | Indicates a counter variable. |
| **ASN_GAUGE32** | Indicates a gauge variable. For more information, see the following Remarks section. |
| **ASN_TIMETICKS** | Indicates a timeticks variable. |
| **ASN_OPAQUE** | Indicates an opaque variable. |
| **SNMP_EXCEPTION_NOSUCHOBJECT** | Indicates that the object provided is not available. |
| **SNMP_EXCEPTION_NOSUCHINSTANCE** | Indicates that the instance provided is not available. |
| **SNMP_EXCEPTION_ENDOFMIBVIEW** | Indicates that the end of the MIB view has been reached. |

### `asnValue`

Contains the variable's value. This member can be only one of the following values.

#### number

Type: **AsnInteger32**

Accesses a 32-bit signed integer variable.

#### unsigned32

Type: **AsnUnsigned32**

Accesses a 32-bit unsigned integer variable.

#### counter64

Type: **AsnCounter64**

Accesses a counter variable that increases until it reaches a maximum value of (2^64) – 1.

#### string

Type: **AsnOctetString**

Accesses an octet string variable.

#### bits

Type: **AsnBits**

Accesses a variable that is an enumeration of named bits with non-negative, contiguous values, starting at zero.

#### object

Type: **AsnObjectIdentifier**

Accesses an object identifier variable.

#### sequence

Type: **AsnSequence**

Accesses an ASN sequence variable.

#### address

Type: **AsnIPAddress**

Accesses an IP address variable.

#### counter

Type: **AsnCounter32**

Accesses a counter variable that increases until it reaches a maximum value of (2^32) – 1.

#### gauge

Type: **AsnGauge32**

Accesses a gauge variable.

#### ticks

Type: **AsnTimeticks**

Accesses a timeticks counter variable that is relative to a specific timer event.

#### arbitrary

Type: **AsnOpaque**

Accesses an opaque variable.

### `number`

### `unsigned32`

### `counter64`

### `string`

### `bits`

### `object`

### `sequence`

### `address`

### `counter`

### `gauge`

### `ticks`

### `arbitrary`

## Remarks

To use the definition of the Unsigned32 type described in RFC 1902, you can specify the ASN_GAUGE32 variable type. Currently the ASN_UNSIGNED32 variable type specifies the UInteger32 type described in RFC 1442.

## See also

[SNMP Structures](https://learn.microsoft.com/windows/desktop/SNMP/snmp-structures)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpExtensionMonitor](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpextensionmonitor)

[SnmpVarBind](https://learn.microsoft.com/windows/desktop/api/snmp/ns-snmp-snmpvarbind)