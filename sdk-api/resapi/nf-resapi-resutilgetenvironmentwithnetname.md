# ResUtilGetEnvironmentWithNetName function

## Description

Adjusts environment data for a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) so that the resource uses a cluster network name to identify its location. The resource must be dependent on a [Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource. The **PRESUTIL_GET_ENVIRONMENT_WITH_NET_NAME** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to a resource that depends on a Network Name resource.

## Return value

If the operations succeeds, the function returns a pointer to the environment block.

If the operation fails,
the function returns **NULL**. For more information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **ResUtilGetEnvironmentWithNetName** function appends environment variables to the current environment block. Pass the returned environment block to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) when starting the resource to achieve the following effects:

* Clients and the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) can locate the resource by using the name of the Network Name resource.
* If the resource calls [GetComputerName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcomputernamea), [GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa), or [gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname), the network name will be returned regardless of which node is currently hosting the resource.

If the resource identified by *hResource* is not dependent on a Network Name resource, **ResUtilGetEnvironmentWithNetName** returns **NULL**.

Use [ResUtilFreeEnvironment](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfreeenvironment) to destroy the environment block.

Do not call **ResUtilGetEnvironmentWithNetName** from any resource DLL entry point function. **ResUtilGetEnvironmentWithNetName** can safely be called from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ResUtilSetResourceServiceEnvironment](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceserviceenvironment)