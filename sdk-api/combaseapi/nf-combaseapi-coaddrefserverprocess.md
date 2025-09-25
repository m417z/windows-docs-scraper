# CoAddRefServerProcess function

## Description

Increments a global per-process reference count.

## Return value

The current reference count.

## Remarks

Servers can call **CoAddRefServerProcess** to increment a global per-process reference count. This function is particularly helpful to servers that are implemented with multiple threads, either multi-apartmented or free-threaded. Servers of these types must coordinate the decision to shut down with activation requests across multiple threads. Calling **CoAddRefServerProcess** increments a global per-process reference count, and calling [CoReleaseServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleaseserverprocess) decrements that count.

When that count reaches zero, OLE automatically calls [CoSuspendClassObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosuspendclassobjects), which prevents new activation requests from coming in. This permits the server to deregister its class objects from its various threads without worry that another activation request may come in. New activation requests result in launching a new instance of the local server process.

The simplest way for a local server application to make use of these functions is to call **CoAddRefServerProcess** in the constructor for each of its instance objects, and in each of its [IClassFactory::LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver) methods when the *fLock* parameter is **TRUE**. The server application should also call [CoReleaseServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleaseserverprocess) in the destruction of each of its instance objects, and in each of its **LockServer** methods when the *fLock* parameter is **FALSE**. Finally, the server application should pay attention to the return code from **CoReleaseServerProcess** and if it returns 0, the server application should initiate its cleanup, which, for a server with multiple threads, typically means that it should signal its various threads to exit their message loops and call [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) and [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize).

If these functions are used at all, they must be called in both the object instances and the [LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver) method, otherwise the server application may be shut down prematurely. In-process servers typically should not call **CoAddRefServerProcess** or [CoReleaseServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleaseserverprocess).

## See also

[CoReleaseServerProcess](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coreleaseserverprocess)

[IClassFactory::LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver)

[Out-of-Process Server Implementation Helpers](https://learn.microsoft.com/windows/desktop/com/out-of-process-server-implementation-helpers)