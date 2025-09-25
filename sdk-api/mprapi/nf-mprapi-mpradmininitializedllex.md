# MprAdminInitializeDllEx function

## Description

When the Routing and Remote Access Service (RRAS) starts, it calls the
[MprAdminInitializeDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininitializedll) function that is exported by the administration DLL. Use this function to perform any required initialization for the DLL and call the callback functions. This serves as a placeholder for the callback functions.

## Parameters

### `pAdminCallbacks`

A pointer to a [MPRAPI_ADMIN_DLL_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mprapi_admin_dll_callbacks) structure that contains the function pointers of the callbacks being registered.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function returns any value other than **NO_ERROR**, RRAS will fail to start.

## See also

[MprAdminInitializeDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininitializedll)

[MprAdminTerminateDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminterminatedll)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)