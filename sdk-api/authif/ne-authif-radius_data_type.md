# RADIUS_DATA_TYPE enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS.

The
**RADIUS_DATA_TYPE** type enumerates the possible data type for a RADIUS attribute or extended attribute.

## Constants

### `rdtUnknown`

The value is a pointer to an unknown data type.

### `rdtString`

The value of the attribute is a pointer to a character string.

### `rdtAddress`

The value of the attribute is a 32-bit **DWORD** value that represents an address.

### `rdtInteger`

The value of the attribute is a 32-bit **DWORD** value that represents an integer.

### `rdtTime`

The value of the attribute is a 32-bit **DWORD** value that represents a time.

### `rdtIpv6Address`

The value of the attribute is a **BYTE*** value that represents an IPv6 address.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Enumerations](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-enumerations)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute)

[RADIUS_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_attribute_type)