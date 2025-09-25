# MprAdminInitializeDll function

## Description

When the Routing and Remote Access Service (RRAS) starts, it calls the
**MprAdminInitializeDll** function that is exported by the administration DLL. Use this function to perform any required initialization for the DLL.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function returns any value other than **NO_ERROR**, RRAS will fail to start.

## Remarks

RAS supports multiple Administration DLLs. RAS calls the multiple implementations of **MprAdminInitializeDll** in the order in which the DLLs are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup).

This function can return any of the error codes that are defined in the Winerror.h header file in the Platform Software Development Kit (SDK).

## See also

[MprAdminTerminateDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminterminatedll)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)