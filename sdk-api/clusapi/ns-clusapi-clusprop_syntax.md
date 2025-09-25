# CLUSPROP_SYNTAX structure

## Description

Describes the format and type of a data value. It is used as the **Syntax** member of the
[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure.

## Members

### `dw`

A DWORD that describes the format and type of the data value. The
[CLUSTER_PROPERTY_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_syntax) enumeration defines the
possible values.

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.wFormat`

Numeric value describing only the format of the data value. ClusAPI.h defines the following values,
enumerated in the [CLUSTER_PROPERTY_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_format)
enumeration.

##### wFormat.CLUSPROP_FORMAT_BINARY (1)

Data is a binary value.

##### wFormat.CLUSPROP_FORMAT_DWORD (2)

Data is a **DWORD** value.

##### wFormat.CLUSPROP_FORMAT_EXPAND_SZ (4)

Data is a null-terminated Unicode string with unexpanded references to environment variables.

##### wFormat.CLUSPROP_FORMAT_EXPANDED_SZ (8)

Data is a null-terminated Unicode string with expanded references to environment variables.

##### wFormat.CLUSPROP_FORMAT_FILETIME (12 (0xC))

Data is a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

##### wFormat.CLUSPROP_FORMAT_LARGE_INTEGER (10 (0xA))

Data is a signed large integer.

##### wFormat.CLUSPROP_FORMAT_LONG (7)

Data is a signed **LONG** value.

##### wFormat.CLUSPROP_FORMAT_MULTI_SZ (5)

Data is an array of null-terminated Unicode strings.

##### wFormat.CLUSPROP_FORMAT_SECURITY_DESCRIPTOR (9)

Data is a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) in
[self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)
format. For more information about self-relative security descriptors, see
[Absolute and Self-Relative Security Descriptors](https://learn.microsoft.com/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

##### wFormat.CLUSPROP_FORMAT_SZ (3)

Data is a null-terminated Unicode string.

##### wFormat.CLUSPROP_FORMAT_ULARGE_INTEGER (6)

Data is an unsigned large integer.

##### wFormat.CLUSPROP_FORMAT_UNKNOWN (0)

Data is in an unknown format.

##### wFormat.CLUSPROP_FORMAT_USER (32768 (0x8000))

Data is in a user-defined format.

##### wFormat.CLUSPROP_FORMAT_WORD (11 (0xB))

Data is a **WORD** value.

### `DUMMYSTRUCTNAME.wType`

Numeric value that describes only the type of the data value. The
[CLUSTER_PROPERTY_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_type) enumeration defines the
possible values.

##### wType.CLUSPROP_TYPE_DISK_NUMBER (7)

Describes the number value of a disk resource. A disk number value is represented by a
[CLUSPROP_DISK_NUMBER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_dword)
structure.

##### wType.CLUSPROP_TYPE_DISK_SERIALNUMBER (10 (0xA))

Describes the serial number of a disk resource.

##### wType.CLUSPROP_TYPE_DISK_GUID (11 (0xB))

Describes the **GUID** of a disk resource.

##### wType.CLUSPROP_TYPE_DISK_SIZE (12 (0xC))

Describes the total size of the disk.

##### wType.CLUSPROP_TYPE_ENDMARK (0)

Designates the data value as the last entry in a property or value list.

##### wType.CLUSPROP_TYPE_LIST_VALUE (1)

Describes a data value in a property list. For example, in the property list passed to a
[control code function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions) for a property
validation operation, **CLUSPROP_TYPE_LIST_VALUE** is the required type to be
included with each property value.

##### wType.CLUSPROP_TYPE_NAME (4)

Describes a data value used as a name, such as a property name. A name value is represented by a
[CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))
structure.

##### wType.CLUSPROP_TYPE_PARTITION_INFO (8)

Describes a collection of information about a disk resource, such as its device name and volume label.
Partition data is represented by a
[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)
structure.

##### wType.CLUSPROP_TYPE_PARTITION_INFO_EX (13 (0xD))

Describes a collection of information about a disk resource, such as its device name and volume label.
Partition data is represented by a
[CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex)
structure.

##### wType.CLUSPROP_TYPE_RESCLASS (2)

Describes resource class information. A resource class value is described with a
[CLUSPROP_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class)
structure. Resource classes are returned when an application calls
[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) or
[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol) with one
of the following control codes.

[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)

[CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-class-info)

[CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-required-dependencies)

##### wType.CLUSPROP_TYPE_SCSI_ADDRESS (6)

Describes an [Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-address)
property for an [IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) resource. A SCSI
address value is represented by a
[CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)
structure.

##### wType.CLUSPROP_TYPE_SIGNATURE (5)

Describes a [Signature](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disks-signature) property for a
disk resource. A signature value is represented by a
[CLUSPROP_DISK_SIGNATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368374(v=vs.85))
structure.

##### wType.CLUSPROP_TYPE_UNKNOWN (-1)

The type is unknown.

##### wType.CLUSPROP_TYPE_USER (32768 (0x8000))

Describes the beginning of the range for users to define their own types. Associate this type with
user-defined private properties.

## Remarks

To parse data that is returned from a
[control code function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions), use the
**wFormat** member of this structure if the **wType** member
defines a type that the application cannot understand.

#### Examples

See [Creating Physical Disk Resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-physical-disk-resources)
and
[Building with CLUSPROP_BUFFER_HELPER](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/building-with-clusprop-buffer-helper).

## See also

[Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-address)

[CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)

[CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-class-info)

[CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-required-dependencies)

[CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary)

[CLUSPROP_DISK_NUMBER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_dword)

[CLUSPROP_DISK_SIGNATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368374(v=vs.85))

[CLUSPROP_DWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368375(v=vs.85))

[CLUSPROP_FILETIME](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_filetime)

[CLUSPROP_LONG](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_long)

[CLUSPROP_MULTI_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_sz)

[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)

[CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex)

[CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))

[CLUSPROP_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class)

[CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85))

**CLUSPROP_ULARGE_INTEGER**

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[CLUSTER_PROPERTY_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_format)

[CLUSTER_PROPERTY_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_syntax)

[CLUSTER_PROPERTY_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_type)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)

[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)

[Name (property for resources)](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-name)

[NodeName](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes-nodename)