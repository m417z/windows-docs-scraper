# CLUS_RESSUBCLASS_STORAGE enumeration

## Description

Identifies a resource subclass that manages a shared bus.

## Constants

### `CLUS_RESSUBCLASS_STORAGE_SHARED_BUS:0x80000000`

Identifies a resource subclass that manages a shared bus. The
[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) function with the
[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)
control code can retrieve a
[CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info) structure that contains
information for a resource subclass.

### `CLUS_RESSUBCLASS_STORAGE_DISK:0x40000000`

Identifies a resource subclass that manages a disk.

**Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not supported before Windows Server 2012 R2.

### `CLUS_RESSUBCLASS_STORAGE_REPLICATION:0x10000000`

Identifies a resource subclass that manages storage replication.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not supported before Windows Server 2016.

## See also

[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)

[CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)