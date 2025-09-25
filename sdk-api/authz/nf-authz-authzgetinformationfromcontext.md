# AuthzGetInformationFromContext function

## Description

The **AuthzGetInformationFromContext** function returns information about an Authz context.

Starting with Windows Server 2012 and Windows 8, device groups are returned as a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure. User and device claims are returned as an [AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information) structure.

## Parameters

### `hAuthzClientContext` [in]

A handle to the context.

### `InfoClass` [in]

A value of the [AUTHZ_CONTEXT_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_context_information_class) enumeration that indicates the type of information to be returned.

### `BufferSize` [in]

Size of the buffer passed.

### `pSizeRequired` [out]

A pointer to a **DWORD** of the buffer size required for returning the structure.

### `Buffer` [out]

A pointer to memory that can receive the information. The structure returned depends on the information requested in the *InfoClass* parameter.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AUTHZ_CONTEXT_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/authz/ne-authz-authz_context_information_class)

[AUTHZ_SECURITY_ATTRIBUTES_INFORMATION](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attributes_information)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups)