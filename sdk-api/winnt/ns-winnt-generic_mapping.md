# GENERIC_MAPPING structure

## Description

The **GENERIC_MAPPING** structure defines the mapping of generic access rights to specific and standard access rights for an object. When a client application requests generic access to an object, that request is mapped to the access rights defined in this structure.

## Members

### `GenericRead`

Specifies an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) defining read access to an object.

### `GenericWrite`

Specifies an access mask defining write access to an object.

### `GenericExecute`

Specifies an access mask defining execute access to an object.

### `GenericAll`

Specifies an access mask defining all possible types of access to an object.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma)

[CreatePrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)