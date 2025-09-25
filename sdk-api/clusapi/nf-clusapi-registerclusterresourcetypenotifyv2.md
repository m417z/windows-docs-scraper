# RegisterClusterResourceTypeNotifyV2 function

## Description

Adds a notification type to a cluster notification port.This allows an application to register for notification events that only affect a particular cluster object.

## Parameters

### `hChange` [in]

A handle to the notification port.

### `hCluster` [in]

A handle to the cluster object.

### `Flags` [in]

A [CLUSTER_CHANGE_RESOURCE_TYPE_V2](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_change_resource_type_v2) enumeration value that specifies the notification type to add.

### `resTypeName` [in]

A pointer to a null-terminated Unicode string that contains the name of the resource type.

### `dwNotifyKey` [in]

The notification key that is returned from the [GetClusterNotifyV2](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotifyv2) function when the event occurs.

## Return value

**ERROR_SUCCESS** if the operation is successful; otherwise, a system error code.

## See also

[Resource Type Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-management-functions)