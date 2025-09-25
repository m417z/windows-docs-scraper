# SECURITY_IMPERSONATION_LEVEL enumeration

## Description

The **SECURITY_IMPERSONATION_LEVEL** enumeration contains values that specify security impersonation levels. Security impersonation levels govern the degree to which a server process can act on behalf of a client [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Constants

### `SecurityAnonymous`

The server process cannot obtain identification information about the client, and it cannot impersonate the client. It is defined with no value given, and thus, by ANSI C rules, defaults to a value of zero.

### `SecurityIdentification`

The server process can obtain information about the client, such as security identifiers and [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly), but it cannot impersonate the client. This is useful for servers that export their own objects, for example, database products that export tables and views. Using the retrieved client-security information, the server can make access-validation decisions without being able to use other services that are using the client's [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `SecurityImpersonation`

The server process can impersonate the client's security context on its local system. The server cannot impersonate the client on remote systems.

### `SecurityDelegation`

The server process can impersonate the client's security context on remote systems.

## Remarks

Impersonation is the ability of a process to take on the security attributes of another process.

## See also

[Authorization Enumerations](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-enumerations)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[CreatePrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity)

[DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken)

[DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[ImpersonateSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateself)

[OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken)