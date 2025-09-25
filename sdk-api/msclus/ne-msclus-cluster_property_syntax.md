# CLUSTER_PROPERTY_SYNTAX enumeration

## Description

Provides the possible values for the syntax structures in a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists).

## Constants

### `CLUSPROP_SYNTAX_ENDMARK`

Marks the end of a value list.

### `CLUSPROP_SYNTAX_NAME`

Describes a property name, such as the [Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources-name)
property for resources and the [NodeName](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes-nodename) property for
nodes. A property name is represented by a
[CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85)) structure.

### `CLUSPROP_SYNTAX_RESCLASS`

Describes a resource class value. A resource class value is represented by a
[CLUSPROP_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class) structure.

### `CLUSPROP_SYNTAX_LIST_VALUE_SZ`

Describes a null-terminated Unicode string value in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_EXPAND_SZ`

Describes a null-terminated Unicode string value with unexpanded references to environment variables in a
property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_DWORD`

Describes a **DWORD** value in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_BINARY`

Describes a binary value in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_MULTI_SZ`

Describes an array of null-terminated Unicode string values in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_LONG`

Describes a signed **long** value in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_EXPANDED_SZ`

Describes a null-terminated Unicode string value with expanded references to environment variables in a
property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_SECURITY_DESCRIPTOR`

Describes a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) in
[self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format
in a property list. For more information about self-relative security descriptors, see
[Absolute and Self-Relative Security Descriptors](https://learn.microsoft.com/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

### `CLUSPROP_SYNTAX_LIST_VALUE_LARGE_INTEGER`

Describes a signed large integer value in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_ULARGE_INTEGER`

Describes an unsigned large integer value in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_WORD`

Describes a **WORD** value in a property list.

### `CLUSPROP_SYNTAX_LIST_VALUE_PROPERTY_LIST`

Describes a property list.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported until Windows Server 2016.

### `CLUSPROP_SYNTAX_LIST_VALUE_FILETIME`

Describes a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) value in a property list.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This enumeration value is not supported until Windows Server 2016.

### `CLUSPROP_SYNTAX_DISK_SIGNATURE`

Describes a master boot record (MBR) disk signature value represented by a
[CLUSPROP_DISK_SIGNATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368374(v=vs.85)) structure.

### `CLUSPROP_SYNTAX_SCSI_ADDRESS`

Describes the address for an [IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) resource. IP
Address resources store this address in their
[Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-addresses-address) private property. A SCSI address value
is represented by a [CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)
structure.

### `CLUSPROP_SYNTAX_DISK_NUMBER`

Describes a disk number value represented by a
[CLUSPROP_DISK_NUMBER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_dword) structure.

### `CLUSPROP_SYNTAX_PARTITION_INFO`

Describes a collection of information about a Physical Disk resource, such as its device name and volume
label. Partition information is represented by a
[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info) structure.

### `CLUSPROP_SYNTAX_FTSET_INFO`

Describes [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) set information.

### `CLUSPROP_SYNTAX_DISK_SERIALNUMBER`

Describes a null-terminated Unicode string value containing a serial number of a disk resource.

### `CLUSPROP_SYNTAX_DISK_GUID`

Describes a null-terminated Unicode string value containing the **GUID** of a
**GUID** partitioning table (GPT) disk resource.

### `CLUSPROP_SYNTAX_DISK_SIZE`

Describes a unsigned large integer value containing the total size of a disk in bytes.

### `CLUSPROP_SYNTAX_PARTITION_INFO_EX`

Describes a collection of information about a Physical Disk resource, such as its device name and volume
label. Partition information is represented by a
[CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex) structure.

### `CLUSPROP_SYNTAX_PARTITION_INFO_EX2`

Describes a collection of information about a Physical Disk resource, such as its device name and volume
label. The partition information is represented by a
[CLUSPROP_PARTITION_INFO_EX2](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex2) structure.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available until Windows Server 2016 .

### `CLUSPROP_SYNTAX_STORAGE_DEVICE_ID_DESCRIPTOR`

Describes descriptor data for a storage class resource.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not available until Windows Server 2016 .

## Remarks

The upper 2 bytes of a **CLUSTER_PROPERTY_SYNTAX**
must be a valid [CLUSTER_PROPERTY_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_type). The lower 2
bytes of a **CLUSTER_PROPERTY_SYNTAX** must be a
valid [CLUSTER_PROPERTY_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_format).

The client must not specify a syntax value of
**CLUSPROP_SYNTAX_LIST_VALUE_EXPANDED_SZ** when adding a property value to a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) structure. When constructing a
property list structure to return to the client, the server
must return two values for a property's value that is of syntax
**CLUSPROP_SYNTAX_LIST_VALUE_EXPAND_SZ**: the first value is of syntax
**CLUSPROP_SYNTAX_LIST_VALUE_EXPAND_SZ**, containing the property value, as it is stored
on the server, and the second is of syntax **CLUSPROP_SYNTAX_LIST_VALUE_EXPANDED_SZ**
which is the same property value where each embedded environment variable has been replaced by its value, as
stored on the server.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSTER_PROPERTY_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_format)

[CLUSTER_PROPERTY_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_type)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)