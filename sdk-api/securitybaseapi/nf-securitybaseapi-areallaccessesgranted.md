# AreAllAccessesGranted function

## Description

The **AreAllAccessesGranted** function checks whether a set of requested access rights has been granted. The access rights are represented as bit flags in an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Parameters

### `GrantedAccess` [in]

An access mask that specifies the access rights that have been granted.

### `DesiredAccess` [in]

An access mask that specifies the access rights that have been requested. This mask must have been mapped from generic to specific and standard access rights, usually by calling the
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function.

## Return value

If all requested access rights have been granted, the return value is nonzero.

If not all requested access rights have been granted, the return value is zero.

## Remarks

The **AreAllAccessesGranted** function is commonly used by a server application to check the access rights of a client attempting to gain access to an object. When the bits set in the *DesiredAccess* parameter match the bits set in the *GrantedAccess* parameter, all requested rights have been granted.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AreAnyAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areanyaccessesgranted)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)