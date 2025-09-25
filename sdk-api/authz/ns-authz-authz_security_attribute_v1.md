# AUTHZ_SECURITY_ATTRIBUTE_V1 structure

## Description

The **AUTHZ_SECURITY_ATTRIBUTE_V1** structure defines a security attribute that can be associated with an authorization context.

## Members

### `pName`

A pointer to a name of a security attribute.

### `ValueType`

The data type of the values pointed to by the **Values** member.

| Value | Meaning |
| --- | --- |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_INT64**<br><br>0x0001 | The **Values** member refers to a security attribute that is of **INT64** type. |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_UINT64**<br><br>0x0002 | The **Values** member refers to a security attribute that is of **UINT64** type. |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_STRING**<br><br>0x0003 | The **Values** member refers to a security attribute that is of **STRING** type. |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_FQBN**<br><br>0x0004 | The **Values** member refers to a security attribute that is of **AUTHZ_SECURITY_ATTRIBUTE_TYPE_FQBN** type. |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_SID**<br><br>0x0005 | The **Values** member refers to a security attribute that is of **AUTHZ_SECURITY_ATTRIBUTE_TYPE_SID** type.<br><br>**Windows Server 2008 R2 and Windows 7:** This value type is not available. |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_BOOLEAN**<br><br>0x0006 | The **Values** member refers to a security attribute that is of **AUTHZ_SECURITY_ATTRIBUTE_TYPE_BOOLEAN** type.<br><br>**Windows Server 2008 R2 and Windows 7:** This value type is not available. |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING**<br><br>0x0010 | The **Values** member refers to a security attribute that is of **AUTHZ_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING** type. |
| **AUTHZ_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING**<br><br>0x0010 | The **Values** member refers to a security attribute that is of **AUTHZ_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING** type. |

### `Reserved`

Reserved for future use.

### `Flags`

A combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **AUTHZ_SECURITY_ATTRIBUTE_NON_INHERITABLE**<br><br>0x0001 | This security attribute is not inherited across processes. |
| **AUTHZ_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE**<br><br>0x0002 | The value of the attribute is case sensitive. This flag is valid for values that contain string types. |

### `ValueCount`

The number of values specified in the **Values** member.

### `Values`

### `Values.pInt64`

A pointer to one or more numeric attribute values.

### `Values.pUint64`

A pointer to one or more numeric attribute values.

### `Values.ppString`

A pointer to one or more string attribute values.

### `Values.pFqbn`

A pointer to one or more [AUTHZ_SECURITY_ATTRIBUTE_FQBN_VALUE](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attribute_fqbn_value) structures.

### `Values.pOctetString`

A pointer to one or more [AUTHZ_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE](https://learn.microsoft.com/windows/win32/api/authz/ns-authz-authz_security_attribute_octet_string_value) structures.

## See also

[AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information)

[AuthzModifySecurityAttributes](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzmodifysecurityattributes)