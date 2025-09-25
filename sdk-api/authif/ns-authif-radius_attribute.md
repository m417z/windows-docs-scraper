# RADIUS_ATTRIBUTE structure

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS.

The
**RADIUS_ATTRIBUTE** structure represents a RADIUS attribute or an extended attribute.

## Members

### `dwAttrType`

Stores a value from the
[RADIUS_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_attribute_type) enumeration. This value specifies the type of the attribute represented by the
**RADIUS_ATTRIBUTE** structure.

### `fDataType`

Stores a value from the
[RADIUS_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_data_type) enumeration. This value specifies the type of the value stored in the union that contains the **dwValue** and **lpValue** members.

### `cbDataLength`

Stores the length, in bytes, of the data. The **cbDataLength** member is used only if **lpValue** member is used.

### `dwValue`

Stores a value of type **DWORD**. The **dwValue** member is used if the **fDataType** member specifies **rdtAddress**, **rdtInteger**, or **rdtTime**.

**Note** In Windows Server 2008 the byte order format of dwValue is represented in network byte order (big-endian) when **fDataType** is specified as **rdtAddress**. Previous Windows versions represented network addressing using the little-endian format.

### `lpValue`

Stores a multi-byte data value. The **lpValue** member is used if the **fDataType** member specifies **rdtUnknown**, **rdtIpv6Address**, or **rdtString**.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[NPS Extensions Structures](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-structures)

[RADIUS_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_attribute_type)

[RADIUS_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_data_type)