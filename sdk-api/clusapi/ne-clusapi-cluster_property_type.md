## Description

This enumeration defines the property types that are supported by a cluster [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists).

## Constants

### `CLUSPROP_TYPE_UNKNOWN:-1`

The property type is unknown.

### `CLUSPROP_TYPE_ENDMARK:0`

Designates the data value as the last entry in a property or value list.

### `CLUSPROP_TYPE_LIST_VALUE`

Describes a data value in a property list. For example, in the property list passed to a
[control code function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions) for a property validation
operation, **CLUSPROP_TYPE_LIST_VALUE** is the required type to be included with each
property value.

### `CLUSPROP_TYPE_RESCLASS`

Describes resource class information. A resource class value is described with a
[CLUSPROP_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class)
structure. Resource classes are returned when an application calls
[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) or
[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol) with one of
the following control codes:

[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)

[CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-class-info)

[CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-required-dependencies)

### `CLUSPROP_TYPE_RESERVED1`

Reserved for future use.

### `CLUSPROP_TYPE_NAME`

Describes a data value used as a name, such as a property name. A name value is represented by a
[CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))
structure.

### `CLUSPROP_TYPE_SIGNATURE`

Describes a [Signature](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disks-signature) property for
a disk resource. A signature value is represented by a
[CLUSPROP_DISK_SIGNATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368374(v=vs.85)) structure.

### `CLUSPROP_TYPE_SCSI_ADDRESS`

Describes an [Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-address)
property for an [IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) resource. A SCSI
address value is represented by a
[CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)
structure.

### `CLUSPROP_TYPE_DISK_NUMBER`

Describes the number value of a disk resource. A disk number value is represented by a
[CLUSPROP_DISK_NUMBER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_dword)
structure.

### `CLUSPROP_TYPE_PARTITION_INFO`

Describes a collection of information about a disk resource, such as its device name and volume label.
Partition data is represented by a
[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)
structure.

### `CLUSPROP_TYPE_FTSET_INFO`

Describes [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) set information.

**Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported.

### `CLUSPROP_TYPE_DISK_SERIALNUMBER`

Describes the serial number of a disk resource.

### `CLUSPROP_TYPE_DISK_GUID`

Describes the **GUID** of a disk resource.

### `CLUSPROP_TYPE_DISK_SIZE`

Describes the total size of a disk in bytes.

### `CLUSPROP_TYPE_PARTITION_INFO_EX`

Describes a collection of information about a disk resource, such as its device name and volume label.
Partition data is represented by a
[CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex)
structure.

### `CLUSPROP_TYPE_PARTITION_INFO_EX2`

Describes a collection of information about a disk resource, such as its device name and volume label.
Partition data is represented by a
[CLUSPROP_PARTITION_INFO_EX2](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex2)
structure.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available until Windows Server 2016 .

### `CLUSPROP_TYPE_STORAGE_DEVICE_ID_DESCRIPTOR`

Describes descriptor data for a storage class resource.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available until Windows Server 2016 .

### `CLUSPROP_TYPE_USER:32768`

Describes the beginning of the range for users to define their own types. Associate this type with
user-defined private properties.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[Type Property of the ClusPropertyValue Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluspropertyvalue-type)