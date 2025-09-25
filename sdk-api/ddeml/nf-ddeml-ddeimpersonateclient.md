# DdeImpersonateClient function

## Description

Impersonates a Dynamic Data Exchange (DDE) client application in a DDE client conversation.

## Parameters

### `hConv` [in]

Type: **HCONV**

A handle to the DDE client conversation to be impersonated.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Impersonation is the ability of a process to take on the security attributes of another process. When a client in a DDE conversation requests information from a DDE server, the server impersonates the client. When the server requests access to an object, the system verifies the access against the client's security attributes.

When the impersonation is complete, the server normally calls the [RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself) function.

### Security Considerations

If the call to **DdeImpersonateClient** fails for any reason, the client is not impersonated and the client request is made in the security context of the calling process. If the calling process is running as a highly privileged account, such as LocalSystem, or as a member of an administrative group, the user may be able to perform actions that would otherwise be disallowed. Therefore it is important that you always check the return value of the call, and if it fails to raise an error, do not continue execution of the client request.

## See also

**Conceptual**

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[ImpersonateNamedPipeClient](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-impersonatenamedpipeclient)

**Other Resources**

[RevertToSelf](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-reverttoself)