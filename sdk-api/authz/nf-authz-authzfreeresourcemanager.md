# AuthzFreeResourceManager function

## Description

The **AuthzFreeResourceManager** function frees a resource manager object.

## Parameters

### `hAuthzResourceManager` [in]

The **AUTHZ_RESOURCE_MANAGER_HANDLE** to be freed.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)