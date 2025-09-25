# CLAIM_SECURITY_ATTRIBUTE_V1 structure

## Description

The **CLAIM_SECURITY_ATTRIBUTE_V1** structure defines a security attribute that can be associated with a token or authorization context.

## Members

### `Name`

A pointer to a string of Unicode characters that contains the name of the security attribute. This string must be at least 4 bytes in length.

### `ValueType`

A union tag value that indicates the type of information contained in the **Values** member. The **ValueType** member must be one of the following values (see remarks for additional information).

| Value | Meaning |
| --- | --- |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_INT64**<br><br>0x0001 | The **Values** member refers to an array of **LONG64** values. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_UINT64**<br><br>0x0002 | The **Values** member refers to an array of **ULONG64** values. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_STRING**<br><br>0x0003 | The **Values** member refers to an array of pointers to Unicode string values. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_FQBN**<br><br>0x0004 | The **Values** member refers to an array of [CLAIM_SECURITY_ATTRIBUTE_FQBN_VALUE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attribute_fqbn_value) values. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_SID**<br><br>0x0005 | The **Values** member refers to an array of [CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-claim_security_attribute_octet_string_value) values where the **pValue** member of each **CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE** is a **PSID**. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_BOOLEAN**<br><br>0x0006 | The **Values** member refers to an array of **ULONG64** values where each element indicates a Boolean value. The value 1 indicates **TRUE** and the value 0 indicates **FALSE**. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING**<br><br>0x0010 | The **Values** member refers to an array of [CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-claim_security_attribute_octet_string_value) values. |

### `Reserved`

This member is reserved and must be set to zero when sent and must be ignored when received.

### `Flags`

The attribute flags that are a 32-bitmask. Bits 16 through 31 may be set to any value. Bits 0 through 15 must be zero or a combination of one or more of the following mask values.

| Value | Meaning |
| --- | --- |
| **CLAIM_SECURITY_ATTRIBUTE_NON_INHERITABLE**<br><br>0x0001 | This attribute is ignored by the operating system. This claim security attribute is not inherited across processes. |
| **CLAIM_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE**<br><br>0x0002 | The value of the claim security attribute is case sensitive. This flag is valid for values that contain string types. |
| **CLAIM_SECURITY_ATTRIBUTE_USE_FOR_DENY_ONLY**<br><br>0x0004 | The claim security attribute is considered only for deny [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs). |
| **CLAIM_SECURITY_ATTRIBUTE_DISABLED_BY_DEFAULT**<br><br>0x0008 | The claim security attribute is disabled by default. |
| **CLAIM_SECURITY_ATTRIBUTE_DISABLED**<br><br>0x0010 | The claim security attribute is disabled and will not be applied by the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck) function. |
| **CLAIM_SECURITY_ATTRIBUTE_MANDATORY**<br><br>0x0020 | The claim security attribute is mandatory. |

### `ValueCount`

The number of values specified in the **Values** member.

### `Values`

An array of security attribute values of the type specified in the **ValueType** member.

### `Values.pInt64`

Pointer to an array of **ValueCount** members where each member is a **LONG64** of type CLAIM_SECURITY_ATTRIBUTE_TYPE_INT64.

### `Values.pUint64`

Pointer to an array of **ValueCount** members where each member is a **ULONG64** of type CLAIM_SECURITY_ATTRIBUTE_TYPE_UINT64.

### `Values.ppString`

Pointer to an array of **ValueCount** members where each member is a **PWSTR** of type CLAIM_SECURITY_ATTRIBUTE_TYPE_STRING.

### `Values.pFqbn`

Pointer to an array of **ValueCount** members where each member is a fully qualified binary name value of type [CLAIM_SECURITY_ATTRIBUTE_FQBN_VALUE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attribute_fqbn_value).

### `Values.pOctetString`

Pointer to an array of **ValueCount** members where each member is an octet string of type [CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-claim_security_attribute_octet_string_value).

## Remarks

The field value type indicates that the value can be an octet string or a SID. However, the [Directory Services documentation for claims entries](https://learn.microsoft.com/openspecs/windows_protocols/ms-adts/252d7e10-eaf8-44e9-8b8d-205b384f5782) specifies that effective possible data types for claims are limited to Int64, UInt64, UnicodeString, and Boolean.

## See also

[CLAIM_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attributes_information)