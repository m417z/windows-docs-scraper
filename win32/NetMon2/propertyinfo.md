# PROPERTYINFO structure

The **PROPERTYINFO** data structure defines one property of the protocol.

## Members

**hProperty**

Set this field to zero. On output, Network Monitor returns a handle to the property after the property is added to the property database.

**Version**

Reserved. Must be set to zero.

**Label**

Name of the property.

**Comment**

Description of the property. The description appears on the Network Monitor status bar.

**DataType**

Data type of the property. This member can have one of the following values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**PROP\_TYPE\_VOID**

| Property type is unknown. There is no implied length or format.<br> |
|

**PROP\_TYPE\_SUMMARY**

| Summarizing property type. Indicates the first property instance that the parser attaches to a frame. PROP\_TYPE\_SUMMARY can serve as a placeholder for groups of properties. This value indicates that the property is not defined in the protocol *RFC*.<br> |
|

**PROP\_TYPE\_BYTE**

| Numeric data with a size of one byte (8-bit entity).<br> |
|

**PROP\_TYPE\_WORD**

| Numeric data with a size of two bytes (16-bit entity).<br> |
|

**PROP\_TYPE\_DWORD**

| Numeric data with a size of four bytes (32-bit entity).<br> |
|

**PROP\_TYPE\_LARGEINT**

| Numeric data with a size of eight bytes (64-bit entity).<br> |
|

**PROP\_TYPE\_ADDR**

| MAC address (6-byte entity).<br> |
|

**PROP\_TYPE\_TIME**

| **SYSTEMTIME** structure.<br> |
|

**PROP\_TYPE\_STRING**

| ASCII text data. This data type is not NULL-terminated. <br> For Unicode data, when ASCII text data is specified, the IFLAG\_UNICODE flag must also be set when the attach property instance function is called.<br> |
|

**PROP\_TYPE\_IP\_ADDRESS**

| IP Address. (4-byte entity).<br> |
|

**PROP\_TYPE\_IPX\_ADDRESS**

| IPX Address. (10-byte entity).<br> |
|

**PROP\_TYPE\_BYTESWAPPED\_WORD**

| Obsolete. For byte-swapped WORD data, set **DataType** to PROP\_TYPE\_WORD and set the IFLAG\_SWAPPED flag when calling an **Attach** property instance function.<br> |
|

**PROP\_TYPE\_BYTESWAPPED\_DWORD**

| Obsolete. For byte-swapped DWORD data, set **DataType** to PROP\_TYPE\_DWORD and set the IFLAG\_SWAPPED flag when calling an **Attach** property instance function.<br> |
|

**PROP\_TYPE\_TYPED\_STRING**

| Obsolete. For variable-type string data, set **DataType** to PROP\_TYPE\_STRING and set the IFLAG\_UNICODE flag when calling an **Attach** property instance function.<br> |
|

**PROP\_TYPE\_RAW\_DATA**

| Raw data of unknown length and format.<br> |
|

**PROP\_TYPE\_COMMENT**

| Same as PROP\_TYPE\_VOID.<br> |
|

**PROP\_TYPE\_SRCFRIENDLYNAME**

| Address of source-friendly name. Network Monitor does not provide built-in formatting support for this data type.<br> |
|

**PROP\_TYPE\_DSTFRIENDLYNAME**

| Address of destination friendly name. Network Monitor does not provide built-in formatting support for this data type.<br> |
|

**PROP\_TYPE\_TOKENRING\_ADDRESS**

| Token-ring address. Network Monitor does not provide built-in formatting support for this data type.<br> |
|

**PROP\_TYPE\_FDDI\_ADDRESS**

| FDDI address. Network Monitor does not provide built-in formatting support for this data type.<br> |
|

**PROP\_TYPE\_ETHERNET\_ADDRESS**

| Ethernet address. Network Monitor does not provide built-in formatting support for this data type.<br> |
|

**PROP\_TYPE\_OBJECT\_IDENTIFIER**

| BER-encoded SNMP object identifier.<br> |
|

**PROP\_TYPE\_VINES\_IP\_ADDRESS**

| Vines IP address (6-byte entity).<br> |
|

**PROP\_TYPE\_VAR\_LEN\_SMALL\_INT**

| Numeric value without a pre-determined length, but no more than 8 bytes long. The length of the attached data determines the length of the value.<br> |

**DataQualifier**

The data qualifier of a property. This member provides precise information about the data type.

**DataQualifier** can have one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**PROP\_QUAL\_NONE**

| The property data type is the only specification of the property. <br> When this value is set, the union member of the structure is set to **NULL**, and then ignored.<br> |
|

**PROP\_QUAL\_RANGE**

| The numeric value is expected to be within a given range. Define the range in the **lpRange** member.<br> |
|

**PROP\_QUAL\_SET**

| The value of a property is compared to a set of values that are specified in the **lpSet** member of the structure's union. The value of a property can be a **BYTE**, **WORD**, **DWORD**, **LARGEINT** or **TIME**.<br> |
|

**PROP\_QUAL\_BITFIELD**

| Obsolete.<br> |
|

**PROP\_QUAL\_LABELED\_SET**

| The value of a property is compared to a value in a set of value label pairs. The value label pairs are specified in the **lpSet** member of the structure's union. <br> At display time, if the value of the property matches a value in the set, then both a value, and the associated label are displayed.<br> |
|

**PROP\_QUAL\_LABELED\_BITFIELD**

| Obsolete. Use PROP\_QUAL\_FLAGS instead.<br> |
|

**PROP\_QUAL\_CONST**

| The value of a property is compared to a constant that is specified in the **Value** member of the union. <br> At display time, if the property values and constant do not match, a formatted error message appears with the value set as Normal.<br> |
|

**PROP\_QUAL\_FLAGS**

| The value of the property is compared to specific BITs identified in the **lpSet** member of the union.<br> |
|

**PROP\_QUAL\_ARRAY**

| The value of a property specifies an array of values. The length of attached data determines the length of an array. <br> When the PROP\_QUAL\_ARRAY value is set, the union member of the **PROPERTYINFO** data structure is set to **NULL** and ignored.<br> |

**lpExtendedInfo**

Reserved (member of union).

**lpRange**

Pointer to a [RANGE](https://learn.microsoft.com/windows/win32/netmon2/range) structure that defines a range of values. This member must be set if the **DataQualifier** member of this structure is set to PROP\_QUAL\_RANGE (member of union).

**lpSet**

Pointer to a [SET](https://learn.microsoft.com/windows/win32/netmon2/set) structure that specifies a set of values or labels. This member must be set if the **DataQualifier** member of the structure is set to PROP\_QUAL\_SET, PROP\_QUAL\_LABELED\_SET, or PROP\_QUAL\_FLAGS (member of union).

**Bitmask**

Obsolete (member of union).

**Value**

Constant value used when the **DataQualifier** is set to PROP\_QUAL\_CONST (member of union).

**FormatStringSize**

Maximum size used only for the property description.

**InstanceData**

Specify the format function that is called to format the displayed data for the property. To use the generic formatter, specify the **FormatPropertyInstance** function.

## Remarks

The **PROPERTYINFO** structure is used in calls to the [AddProperty](https://learn.microsoft.com/previous-versions/bb251873(v=msdn.10)) function. The **AddProperty** function adds a single property definition to the parser [*property database*](https://learn.microsoft.com/windows/win32/netmon2/p).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[AddProperty](https://learn.microsoft.com/previous-versions/bb251873(v=msdn.10))

[RANGE](https://learn.microsoft.com/windows/win32/netmon2/range)

[SET](https://learn.microsoft.com/windows/win32/netmon2/set)

