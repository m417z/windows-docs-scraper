# _SECURITY_IMPERSONATION_LEVEL enumeration (wdm.h)

## Description

The **SECURITY_IMPERSONATION_LEVEL** enumeration type contains values that specify security impersonation levels. Security impersonation levels govern the degree to which a server process can act on behalf of a client process.

## Constants

### `SecurityAnonymous`

The server process cannot obtain identification information about the client and it cannot impersonate the client. It is defined with no value given, and thus, by ANSI C rules, defaults to a value of zero.

### `SecurityIdentification`

The server process can obtain information about the client, such as security identifiers and privileges, but it cannot impersonate the client. This is useful for servers that export their own objects, for example, database products that export tables and views. Using the retrieved client-security information, the server can make access-validation decisions without being able to utilize other services using the client's security context.

### `SecurityImpersonation`

The server process can impersonate the client's security context on its local system. The server cannot impersonate the client on remote systems.

### `SecurityDelegation`

The server process can impersonate the client's security context on remote systems.

## Remarks

Impersonation is the ability of a process to take on the security attributes of another process.

Be aware of the following derived types:

```cpp
#define DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#define SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#define SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
```

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[LUID_AND_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes)

[PRIVILEGE_SET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551860(v=vs.85))

[PsImpersonateClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psimpersonateclient)

[PsReferenceImpersonationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreferenceimpersonationtoken)

[SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes)

[SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[SeQueryInformationToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[ZwQueryInformationToken](https://learn.microsoft.com/previous-versions/ff567055(v=vs.85))