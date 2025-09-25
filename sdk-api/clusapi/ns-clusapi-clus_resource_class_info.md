# CLUS_RESOURCE_CLASS_INFO structure

## Description

Contains resource class data. It is used as the data member of a
[CLUSPROP_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class_info) structure and
as the return value of some [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) operations.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DUMMYUNIONNAME.dw`

Provides another way to access the resource class data.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DUMMYUNIONNAME.rc`

Resource class described with one of the following values enumerated from the
[CLUSTER_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_class) enumeration.

####### DUMMYSTRUCTNAME.DUMMYUNIONNAME.rc.CLUS_RESCLASS_UNKNOWN (0)

Resource class is unknown.

####### DUMMYSTRUCTNAME.DUMMYUNIONNAME.rc.CLUS_RESCLASS_STORAGE (1)

Resource is a storage device, such as a
[Physical Disk resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/p-gly).

####### DUMMYSTRUCTNAME.DUMMYUNIONNAME.rc.CLUS_RESCLASS_NETWORK (2)

Resource is a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/n-gly) device.

####### DUMMYSTRUCTNAME.DUMMYUNIONNAME.rc.CLUS_RESCLASS_USER (32768 (0x8000))

Resource classes beginning at this value are user-defined.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.SubClass`

A mask value that further describes the resource class. The following value is valid for storage class
resources such as [Physical Disk](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disk) resources.

###### DUMMYSTRUCTNAME.SubClass.CLUS_RESSUBCLASS_SHARED (0x80000000)

Indicates that the resource manages a shared resource such as a disk on a shared
[SCSI](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) bus.

### `DUMMYUNIONNAME.li`

Resource class and subclass described as a **ULARGE_INTEGER** value with a low
**DWORD** and a high **DWORD**.

## Remarks

A resource class identifies resources of similar capability. A
[resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) that defines its own resource class should
provide a unique identifier for the class that is set to a value greater than
**CLUS_RESCLASS_USER**. **CLUS_RESCLASS_USER** specifies the
beginning for user-defined resource class identifiers.

A **CLUS_RESOURCE_CLASS_INFO** structure is
returned by [ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) when the
*dwControlCode* parameter is set to
[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)
and is returned by
[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol) when
*dwControlCode* is set to
[CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-class-info).

## See also

[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)

[CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-class-info)

[CLUSPROP_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class_info)

[CLUSTER_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_class)

[CLUS_RESSUBCLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clus_ressubclass)

[CLUS_RESSUBCLASS_NETWORK](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clus_ressubclass_network)

[CLUS_RESSUBCLASS_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clus_ressubclass_storage)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)

[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol)