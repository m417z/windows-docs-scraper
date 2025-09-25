# LUID_AND_ATTRIBUTES structure

## Description

The **LUID_AND_ATTRIBUTES** structure represents a [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LUID) and its attributes.

## Members

### `Luid`

Specifies an [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) value.

### `Attributes`

Specifies attributes of the LUID. This value contains up to 32 one-bit flags. Its meaning is dependent on the definition and use of the LUID.

## Remarks

An **LUID_AND_ATTRIBUTES** structure can represent an LUID whose attributes change frequently, such as when the LUID is used to represent privileges in the [PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure. Privileges are represented by LUIDs and have attributes indicating whether they are currently enabled or disabled.

## See also

[AllocateLocallyUniqueId](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocatelocallyuniqueid)

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)

[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)

[TOKEN_PRIVILEGES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_privileges)