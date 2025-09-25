# CLUSTER_RESOURCE_CLASS enumeration

## Description

Defines the class of a resource.

## Constants

### `CLUS_RESCLASS_UNKNOWN:0`

Resource class is unknown.

### `CLUS_RESCLASS_STORAGE`

Resource is a storage device, such as a
[Physical Disk resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/p-gly).

### `CLUS_RESCLASS_NETWORK`

Resource is a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/n-gly) device.

### `CLUS_RESCLASS_USER:32768`

Resource classes beginning at this value are user-defined.

## See also

[CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info)

[ClassInfo Property of the ClusResource Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresource-classinfo)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)