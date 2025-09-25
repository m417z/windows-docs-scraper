# MprAdminTerminateDll function

## Description

When the RAS shuts down, it calls the
**MprAdminTerminateDll** function exported by the administration DLL. Use this function to perform any required clean-up for the DLL.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

## Remarks

RAS supports multiple Administration DLLs. RAS calls the multiple implementations of [MprAdminInitializeDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininitializedll) in the order in which the DLLs are listed in the
[registry](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll-registry-setup).

## See also

[MprAdminInitializeDll](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininitializedll)

[RAS Administration DLL](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-dll)

[RAS Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-functions)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)