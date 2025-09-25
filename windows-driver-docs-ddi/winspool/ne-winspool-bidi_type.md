## Description

The BIDI_TYPE enumeration lists the possible values of data transferred in a bidi operation.

## Constants

### `BIDI_NULL`

Indicates that there is no data.

### `BIDI_INT`

Indicates that the bidi data is an integer.

### `BIDI_FLOAT`

Indicates that the bidi data is a floating-point number.

### `BIDI_BOOL`

Indicates that the bidi data is either **TRUE** or **FALSE**.

### `BIDI_STRING`

Indicates that the bidi data is a Unicode character string.

### `BIDI_TEXT`

Indicates that the bidi data is a nonlocalizable Unicode string.

### `BIDI_ENUM`

Indicates that the bidi data value is a Unicode string.

### `BIDI_BLOB`

Indicates that the bidi data is binary data.

## Remarks

The following correspondence applies between Simple Network Management Protocol (SNMP) types and bidi types defined in the BIDI_TYPE enumeration.

| SNMP type | Bidi type |
|---|---|
| SNMP_SYNTAX_CNTR32, SNMP_SYNTAX_GAUGE32, SNMP_SYNTAX_INT, SNMP_SYNTAX_TIMETICKS, SNMP_SYNTAX_UINT32 | BIDI_BOO,L BIDI_INT |
| SNMP_SYNTAX_IPADDR, SNMP_SYNTAX_OCTETS, SNMP_SYNTAX_OID | BIDI_ENUM, BIDI_STRING, BIDI_TEXT |
| SNMP_SYNTAX_CNTR64, SNMP_SYNTAX_OCTETS, SNMP_SYNTAX_OPAQUE | BIDI_BLOB |
| (none) | BIDI_FLOAT |

See the smiValue structure in the Microsoft Windows SDK documentation for descriptions of the WinSNMP data types.