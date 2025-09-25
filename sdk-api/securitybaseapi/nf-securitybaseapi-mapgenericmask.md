# MapGenericMask function

## Description

The **MapGenericMask** function maps the generic access rights in an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to specific and standard access rights. The function applies a mapping supplied in a
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure.

## Parameters

### `AccessMask` [in, out]

A pointer to an access mask.

### `GenericMapping` [in]

A pointer to a
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure specifying a mapping of generic access types to specific and standard access types.

## Remarks

After calling the **MapGenericMask** function, the access mask pointed to by the *AccessMask* parameter has none of its generic bits (GenericRead, GenericWrite, GenericExecute, or GenericAll) or undefined bits set, although it can have other bits set. If bits other than the generic bits are provided on input, this function does not clear them.

#### Examples

For an example that uses this function, see
[Verifying Client Access with ACLs](https://learn.microsoft.com/windows/desktop/SecAuthZ/verifying-client-access-with-acls-in-c--).

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AreAllAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areallaccessesgranted)

[AreAnyAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areanyaccessesgranted)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)