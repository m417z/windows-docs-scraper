# CoResumeClassObjects function

## Description

Called by a server that can register multiple class objects to inform the SCM about all registered classes, and permits activation requests for those class objects.

## Return value

This function returns S_OK to indicate that the CLSID was retrieved successfully.

## Remarks

Servers that can register multiple class objects call **CoResumeClassObjects** once, after having first called [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject), specifying REGCLS_LOCAL_SERVER | REGCLS_SUSPENDED for each CLSID the server supports. This function causes OLE to inform the SCM about all the registered classes, and begins letting activation requests into the server process.

This reduces the overall registration time, and thus the server application startup time, by making a single call to the SCM, no matter how many CLSIDs are registered for the server. Another advantage is that if the server has multiple apartments with different CLSIDs registered in different apartments, or is a free-threaded server, no activation requests will come in until the server calls **CoResumeClassObjects**. This gives the server a chance to register all of its CLSIDs and get properly set up before having to deal with activation requests, and possibly shutdown requests.

## See also

[CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject)

[CoSuspendClassObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosuspendclassobjects)

[Out-of-Process Server Implementation Helpers](https://learn.microsoft.com/windows/desktop/com/out-of-process-server-implementation-helpers)