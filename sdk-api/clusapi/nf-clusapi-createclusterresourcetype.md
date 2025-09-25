# CreateClusterResourceType function

## Description

Creates a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) in a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_CREATE_CLUSTER_RESOURCE_TYPE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to the cluster to receive the new resource type.

### `lpszResourceTypeName` [in]

Pointer to a null-terminated Unicode string containing the name of the new resource type. The specified name must be unique within the cluster.

### `lpszDisplayName` [in]

Pointer to the [display name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/display-names) for the new resource type. While the content of *lpszResourceTypeName* should uniquely identify the resource type on all clusters, the content of *lpszDisplayName* should be a localized friendly name for the resource suitable for displaying to administrators.

### `lpszResourceTypeDll` [in]

Pointer to the fully qualified name of the [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) for the new resource type or the path name relative to the Cluster directory.

### `dwLooksAlivePollInterval` [in]

Default millisecond value to be used as the poll interval needed by the new resource type's [LooksAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plooks_alive_routine) function. The *dwLooksAlivePollInterval* parameter is used to set the resource type's [LooksAlivePollInterval](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types-looksalivepollinterval) property.

### `dwIsAlivePollInterval` [in]

Default millisecond value to be used as the poll interval needed by the new resource type's [IsAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pis_alive_routine) function. The *dwIsAlivePollInterval* parameter is used to set the resource type's [IsAlivePollInterval](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types-isalivepollinterval) property.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **CreateClusterResourceType** function only defines the resource type in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) and registers the resource type with the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service). To complete the process of installing a new resource type in a cluster, developers must install the resource DLLs and [Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) extension DLLs for the new types on each [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in the cluster. Also, if Cluster Administrator will be used on systems that are not member nodes, the extension DLLs must also be installed on those systems.

## See also

[DeleteClusterResourceType](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-deleteclusterresourcetype)

[IsAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pis_alive_routine)

[IsAlivePollInterval](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types-isalivepollinterval)

[LooksAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plooks_alive_routine)

[LooksAlivePollInterval](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types-looksalivepollinterval)