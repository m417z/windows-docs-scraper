# ResUtilEnumResources function

## Description

Enumerates all of the [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in the local
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and initiates a user-defined operation for each
resource. The **PRESUTIL_ENUM_RESOURCES** type defines a pointer to this function.

## Parameters

### `hSelf` [in]

Optional handle to a cluster resource. The callback function is not invoked for a resource identified by
*hSelf*.

### `lpszResTypeName` [in]

Optional pointer to a name of a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) that
narrows the scope of resources to enumerate. If *lpszResTypeName* is specified, only
resources of the specified type are enumerated.

### `pResCallBack` [in]

Pointer to a user-defined function which will be called for each enumerated resource. This function must
conform to the definition of the [ResourceCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-lpresource_callback)
callback function (note that parameter names are not part of the definition; they have been added here for
clarity):

``` syntax
DWORD (*LPRESOURCE_CALLBACK)(
  HRESOURCE hSelf,
  HRESOURCE hEnum,
  PVOID pParameter
);
```

### `pParameter` [in]

A generic buffer that allows you to pass any kind of data to the callback function.
**ResUtilEnumResources** does not use this
parameter at all, it merely passes the pointer to the callback function. Whether you can pass
**NULL** for the parameter depends on how the callback function is implemented.

## Return value

If the operation succeeds or if *pResCallBack* returns
**ERROR_NO_MORE_ITEMS**, the function returns **ERROR_SUCCESS**.

If the operation fails, the function immediately halts the enumeration and returns the value returned by the
callback function.

## Remarks

**ResUtilEnumResources** is a convenient and
easy-to-use alternative to the
[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum) function.

**ResUtilEnumResources** must be run on a cluster
node because it only connects to the local cluster. The
[ResUtilEnumResourcesEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilenumresourcesex) function allows you to
specify a remote cluster.

The following example uses
**ResUtilEnumResources** to list the names and
states of all resources in the cluster.

```cpp
//////////////////////////////////////////////////////////////////////
//  ClusDocEx_EnumDemo.cpp
//
//  Uses the ResUtilEnumResources function to list the names and
//  states of all cluster resources.
//
//  To compile and run this example you will need two other examples
//  from the documentation:  ClusDocEx.h (see "ClusDocEx.h") and
//  ClusDocEx_GetControlCodeOutput.cpp (see "Getting Information with
//  Control Codes").
//
//////////////////////////////////////////////////////////////////////
#include "ClusDocEx.h"
#include "ClusDocEx_GetControlCodeOutput.cpp"

DWORD
MyCallbackFunction(
    HRESOURCE hSelf,
    HRESOURCE hCurrentEnum,
    PVOID pData );

LPRESOURCE_CALLBACK g_pMyCallbackFunction = &MyCallbackFunction;

int main( void )
{
    wprintf( L"\n\nResource (State)\n----------------\n" );
    DWORD dwResult = ResUtilEnumResources(
                         NULL,
                         NULL,
                         g_pMyCallbackFunction,
                         NULL );
    if( dwResult != ERROR_SUCCESS )
    {
        ClusDocEx_DebugPrint( L"ResUtilEnumResources returned an error.", dwResult );
        return 1;
    }
    else
        return 0;
}

DWORD
MyCallbackFunction(
    HRESOURCE hSelf,
    HRESOURCE hCurrentEnum,
    PVOID pData )
{
    DWORD dwResult           = ERROR_SUCCESS,
          cbNameSize         = 0,
          dwState            = 0;

    WCHAR* pszState    = NULL;
    WCHAR* pszEnumName = ClusDocEx_ResGetControlCodeOutput(
                            hCurrentEnum,
                            NULL,
                            CLUSCTL_RESOURCE_GET_NAME,
                            &cbNameSize );
    if( pszEnumName == NULL )
    {
        dwResult = GetLastError();
        goto EndFunc;
    }

    dwState = GetClusterResourceState(
                  hCurrentEnum,
                  NULL,
                  NULL,
                  NULL,
                  NULL );
    switch( dwState )
    {
    case ClusterResourceOnline:
        pszState = L"Online";
        break;
    case ClusterResourceOffline:
        pszState = L"Offline";
        break;
    case ClusterResourcePending:
        pszState = L"Pending";
        break;
    case ClusterResourceOnlinePending:
        pszState = L"OnlinePending";
        break;
    case ClusterResourceOfflinePending:
        pszState = L"OfflinePending";
        break;
    case ClusterResourceFailed:
        pszState = L"Failed";
        break;
    case ClusterResourceInitializing:
        pszState = L"Initializing";
        break;
    default:
        pszState = L"Unknown";
        break;
    }
    wprintf( L"%ls (%ls)\n", pszEnumName, pszState );

EndFunc:
    LocalFree( pszEnumName );
    return dwResult;
}

```

## See also

[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)

[ResourceCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-lpresource_callback)