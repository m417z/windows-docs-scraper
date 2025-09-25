# CoSuspendClassObjects function

## Description

Prevents any new activation requests from the SCM on all class objects registered within the process.

## Return value

This function returns S_OK to indicate that the activation of class objects was successfully suspended.

## Remarks

**CoSuspendClassObjects** prevents any new activation requests from the SCM on all class objects registered within the process. Even though a process may call this function, the process still must call the [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) function for each CLSID it has registered, in the apartment it registered in. Applications typically do not need to call this function, which is generally only called internally by OLE when used in conjunction with the [CoReleaseServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleaseserverprocess) function.

## See also

[CoReleaseServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleaseserverprocess)

[CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject)

[Out-of-Process Server Implementation Helpers](https://learn.microsoft.com/windows/desktop/com/out-of-process-server-implementation-helpers)