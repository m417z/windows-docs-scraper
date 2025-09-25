# NOTIFY_FILTER_AND_TYPE structure

## Description

Represents a filter for a notification port that was created by the [CreateClusterNotifyPortV2](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyportv2) function. A filter specifies that a notification port accept notifications for the specified type of cluster object during the specified event.

## Members

### `dwObjectType`

A [CLUSTER_OBJECT_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_object_type) enumeration value that specifies the cluster object type for the filter.

### `FilterFlags`

A [CLUSTER_CHANGE_CLUSTER_V2](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_change_cluster_v2) enumeration value that specifies the type for the filter.

## See also

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)