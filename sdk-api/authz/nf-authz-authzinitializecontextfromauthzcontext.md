# AuthzInitializeContextFromAuthzContext function

## Description

The **AuthzInitializeContextFromAuthzContext** function creates a new client context based on an existing client context.

Starting with Windows Server 2012 and Windows 8, this function also duplicates device groups, user claims, and device claims.

## Parameters

### `Flags` [in]

Reserved for future use.

### `hAuthzClientContext` [in]

The handle to an existing client context.

### `pExpirationTime` [in, optional]

Sets the time limit for how long the returned context structure is valid. If no value is passed, then the token never expires. Expiration time is not currently enforced.

### `Identifier` [in]

The specific identifier for the resource manager.

### `DynamicGroupArgs` [in]

A pointer to parameters to be passed to the callback function that computes dynamic groups. If the value is **NULL**, then the callback function is not called.

### `phNewAuthzClientContext` [out]

A pointer to the duplicated AUTHZ_CLIENT_CONTEXT_HANDLE handle. When you have finished using the handle, release it by calling the [AuthzFreeContext](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzfreecontext) function.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function calls the [AuthzComputeGroupsCallback](https://learn.microsoft.com/windows/desktop/SecAuthZ/authzcomputegroupscallback) callback function to add [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to the newly created context.

## See also

[AUTHZ_ACCESS_REPLY](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_access_reply)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)