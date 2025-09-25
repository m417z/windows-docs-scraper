# CoReleaseServerProcess function

## Description

Decrements the global per-process reference count.

## Return value

If the server application should initiate its cleanup, the function returns 0; otherwise, the function returns a nonzero value.

## Remarks

Servers can call **CoReleaseServerProcess** to decrement a global per-process reference count incremented through a call to [CoAddRefServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coaddrefserverprocess).

When that count reaches zero, OLE automatically calls [CoSuspendClassObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosuspendclassobjects), which prevents new activation requests from coming in. This permits the server to deregister its class objects from its various threads without worry that another activation request may come in. New activation requests result in launching a new instance of the local server process.

The simplest way for a local server application to make use of these functions is to call [CoAddRefServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coaddrefserverprocess) in the constructor for each of its instance objects, and in each of its [IClassFactory::LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver) methods when the *fLock* parameter is **TRUE**. The server application should also call **CoReleaseServerProcess** in the destructor of each of its instance objects, and in each of its **IClassFactory::LockServer** methods when the *fLock* parameter is **FALSE**. Finally, the server application must check the return code from **CoReleaseServerProcess**; if it returns 0, the server application should initiate its cleanup. This typically means that a server with multiple threads should signal its various threads to exit their message loops and call [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) and [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize).

If these APIs are used at all, they must be called in both the object instances and the [LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver) method, otherwise the server application may be shutdown prematurely. In-process Servers typically should not call [CoAddRefServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coaddrefserverprocess) or **CoReleaseServerProcess**.

## See also

[CoAddRefServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coaddrefserverprocess)

[CoSuspendClassObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosuspendclassobjects)

[IClassFactory::LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver)

[Out-of-Process Server Implementation Helpers](https://learn.microsoft.com/windows/desktop/com/out-of-process-server-implementation-helpers)