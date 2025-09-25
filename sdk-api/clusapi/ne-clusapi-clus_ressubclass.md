# CLUS_RESSUBCLASS enumeration

## Description

Identifies a resource subclass that manages a shared resource.

## Constants

### `CLUS_RESSUBCLASS_SHARED:0x80000000`

Identifies a resource subclass that manages a shared resource, such as a disk on a shared SCSI bus. The
[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) function with the
[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)
control code can retrieve a
[CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info) structure that contains
this information.

## See also

[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)

[CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)