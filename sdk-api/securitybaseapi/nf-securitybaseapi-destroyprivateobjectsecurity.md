# DestroyPrivateObjectSecurity function

## Description

The **DestroyPrivateObjectSecurity** function deletes a private object's [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). For background information, see the [Security Descriptors for Private Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptors-for-private-objects) topic.

## Parameters

### `ObjectDescriptor` [in, out]

A pointer to a pointer to the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure to be deleted. This security descriptor must have been created by a call to the
[CreatePrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[CreatePrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurity)

[GetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getprivateobjectsecurity)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[Security Descriptors for Private Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptors-for-private-objects)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)