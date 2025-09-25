# CreatePrivateObjectSecurity function

## Description

The **CreatePrivateObjectSecurity** function allocates and initializes a [self-relative security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for a new private object. A protected server calls this function when it creates a new private object.

To specify the object type GUID of the new object or control how [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) are inherited, use the
[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex) function.

## Parameters

### `ParentDescriptor` [in, optional]

A pointer to the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the parent directory in which a new object is being created. If there is no parent directory, this parameter can be **NULL**.

### `CreatorDescriptor` [in, optional]

A pointer to a security descriptor provided by the creator of the object. If the object's creator does not explicitly pass security information for the new object, this parameter is intended to be **NULL**.

### `NewDescriptor` [out]

A pointer to a variable that receives a pointer to the newly allocated self-relative security descriptor. The caller must call the
[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity) function to free this security descriptor.

### `IsDirectoryObject` [in]

Specifies whether the new object is a container. A value of **TRUE** indicates the object contains other objects, such as a directory.

### `Token` [in, optional]

A handle to the [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for the client [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) on whose behalf the object is being created. If this is an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly), it must be at SecurityIdentification level or higher. For a full description of the SecurityIdentification impersonation level, see the
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumerated type.

A client token is used to retrieve default security information for the new object, such as its default owner, primary group, and [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly). The token must be open for **TOKEN_QUERY** access.

If all of the following conditions are true, then the handle must be opened for **TOKEN_DUPLICATE** access in addition to **TOKEN_QUERY** access.

* The token handle refers to a primary token.
* The security descriptor of the token contains one or more ACEs with the **OwnerRights** SID.
* A security descriptor is specified for the *CreatorDescriptor* parameter.
* The caller of this function does not set the **SEF_AVOID_OWNER_RESTRICTION** flag in the *AutoInheritFlags* parameter.

### `GenericMapping` [in]

A pointer to a
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure that specifies the mapping from each generic right to specific rights for the object.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) is specified in the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) specified by the *CreatorDescriptor* parameter, the *Token* parameter must have the SE_SECURITY_NAME privilege enabled. The **CreatePrivateObjectSecurity** function checks this privilege and may generate audits during the process.

## See also

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[Client/Server Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[CreatePrivateObjectSecurityEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createprivateobjectsecurityex)

[DestroyPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-destroyprivateobjectsecurity)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[GetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getprivateobjectsecurity)

[GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation)

[OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)

[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity)