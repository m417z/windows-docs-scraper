# AreAnyAccessesGranted function

## Description

The **AreAnyAccessesGranted** function tests whether any of a set of requested access rights has been granted. The access rights are represented as bit flags in an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Parameters

### `GrantedAccess` [in]

Specifies the granted access mask.

### `DesiredAccess` [in]

Specifies the access mask to be requested. This mask must have been mapped from generic to specific and standard access rights, usually by calling the
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function.

## Return value

If any of the requested access rights have been granted, the return value is nonzero.

If none of the requested access rights have been granted, the return value is zero.

## Remarks

The **AreAnyAccessesGranted** function is often used by a server application to check the access rights of a client attempting to gain access to an object. When any of the bits set in the *DesiredAccess* parameter match the bits set in the *GrantedAccess* parameter, at least one of the requested access rights has been granted.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AreAllAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areallaccessesgranted)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)