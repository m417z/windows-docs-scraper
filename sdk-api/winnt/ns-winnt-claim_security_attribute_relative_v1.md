# CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1 structure

## Description

The **CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1** structure defines a resource attribute that is defined in continuous memory for persistence within a serialized security descriptor.

## Members

### `Name`

A value that indicates an offset from the beginning of the **CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1** structure to a string of Unicode characters that contain the name of the claim security attribute. The string must be at least 4 bytes in length.

### `ValueType`

A union tag value that indicates the type of information being referred to by the **Values** member. The **Values** member will contain an array of offsets from the beginning of the **CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1** structure to each value. The **ValueType** member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_INT64**<br><br>0x0001 | The **Values** member refers to an array of offsets to **LONG64** values. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_UINT64**<br><br>0x0002 | The **Values** member refers to an array of offsets to **ULONG64** values. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_STRING**<br><br>0x0003 | The **Values** member refers to an array of offsets to Unicode character string values. |
| **CLAIM_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING**<br><br>0x0010 | The **Values** member refers to an array of [CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-claim_security_attribute_octet_string_value) values. |

### `Reserved`

This member is currently reserved and must be set to zero when sent and must be ignored when received.

### `Flags`

The claim security attribute flags must be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CLAIM_SECURITY_ATTRIBUTE_NON_INHERITABLE**<br><br>0x0001 | This claim security attribute is not inherited across processes. |
| **CLAIM_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE**<br><br>0x0002 | The value of the claim security attribute is case sensitive. This flag is valid for values that contain string types. |
| **CLAIM_SECURITY_ATTRIBUTE_USE_FOR_DENY_ONLY**<br><br>0x0004 | The claim security attribute is considered only for deny [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs). |
| **CLAIM_SECURITY_ATTRIBUTE_DISABLED_BY_DEFAULT**<br><br>0x0008 | The claim security attribute is disabled by default. |
| **CLAIM_SECURITY_ATTRIBUTE_DISABLED**<br><br>0x0010 | The claim security attribute is disabled. |
| **CLAIM_SECURITY_ATTRIBUTE_MANDATORY**<br><br>0x0020 | The claim security attribute is mandatory. |

### `ValueCount`

The number of values contained in the **Values** member.

### `Values`

An array of offsets from the beginning of the CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1 structure. Each offset indicates the location of a claim security attribute value of the type specified in the **ValueType** member.

### `Values.pInt64`

Pointer to an array of **ValueCount** members that is an offset from the beginning of the structure to a **LONG64** of type CLAIM_SECURITY_ATTRIBUTE_TYPE_INT64.

### `Values.pUint64`

Pointer to an array of **ValueCount** members where each member is an offset from the beginning of the structure to a **ULONG64** of type CLAIM_SECURITY_ATTRIBUTE_TYPE_UINT64.

### `Values.ppString`

Pointer to an array of **ValueCount** members where each member is an offset from the beginning of the structure to a **PWSTR** of type CLAIM_SECURITY_ATTRIBUTE_TYPE_STRING.

### `Values.pFqbn`

Pointer to an array of **ValueCount** members where each member is an offset from the beginning of the structure to the fully qualified binary name value of type [CLAIM_SECURITY_ATTRIBUTE_FQBN_VALUE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attribute_fqbn_value).

### `Values.pOctetString`

Pointer to an array of **ValueCount** members where each member is an offset from the beginning of the structure to a **LONG64** octet string of type [CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-claim_security_attribute_octet_string_value).