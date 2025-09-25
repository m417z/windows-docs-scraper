# GetClusterResourceNetworkName function

## Description

Retrieves the [Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-names-name) private property of the
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource on
which a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is
[dependent](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies). The **PCLUSAPI_GET_CLUSTER_RESOURCE_NETWORK_NAME** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the dependent resource.

### `lpBuffer` [out]

Buffer containing a null-terminated Unicode string that contains the
[Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-names-name) private property of the Network Name
resource on which the resource depends.

### `nSize` [in, out]

On input, pointer to a count of characters in the buffer pointed to by *lpBuffer*.
On output, pointer to a count of characters in the network name of the Network Name resource contained in the
buffer pointed to by *lpBuffer*, excluding the null-terminating character.

## Return value

If the operation succeeds, the function returns **TRUE**.

If the operation fails, the function returns **FALSE**. For more information about the
error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not call
**GetClusterResourceNetworkName** from any
resource DLL entry point function.
**GetClusterResourceNetworkName** can safely
be called from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)