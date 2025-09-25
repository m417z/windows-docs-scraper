# AuthzInitializeContextFromToken function

## Description

The **AuthzInitializeContextFromToken** function initializes a client authorization context from a kernel token. The kernel token must have been opened for TOKEN_QUERY.

Starting with Windows Server 2012 and Windows 8, this function can also copy device groups, user claims, and device claims.

## Parameters

### `Flags` [in]

Reserved for future use.

### `TokenHandle` [in]

A handle to the client token used to initialize the *pAuthzClientContext* parameter. The token must have been opened with TOKEN_QUERY access.

### `hAuthzResourceManager` [in]

A handle to the resource manager that created this client context. This handle is stored in the client context structure.

### `pExpirationTime` [in, optional]

Expiration date and time of the token. If no value is passed, the token never expires. Expiration time is not currently enforced.

### `Identifier` [in]

Identifier that is specific to the resource manager. This parameter is not currently used.

### `DynamicGroupArgs` [in, optional]

A pointer to parameters to be passed to the callback function that computes dynamic groups.

### `phAuthzClientContext` [out]

A pointer to the *AuthzClientContext* handle returned. Call
[AuthzFreeContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreecontext) when done with the client context.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function calls the [AuthzComputeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzcomputegroupscallback) callback function to add [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to the newly created context.

## See also

[AuthzFreeContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreecontext)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)