# CLUSPROP_RESOURCE_CLASS structure

## Description

Describes a resource class. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing the format,
  type, and length of the resource class value.
* A [CLUSTER_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_class) value describing the
  resource class. **CLUSTER_RESOURCE_CLASS** is an
  enumeration defined in ClusAPI.h.

## Members

### `rc`

Resource class described with one of these values enumerated by the
[CLUSTER_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_class) enumeration.

#### CLUS_RESCLASS_UNKNOWN (0)

Resource class is unknown.

#### CLUS_RESCLASS_STORAGE (1)

[Resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is a storage device, such as a
[Physical Disk](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disk) resource.

#### CLUS_RESCLASS_NETWORK (2)

[Resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) is a
[network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/n-gly) device.

#### CLUS_RESCLASS_USER (32768)

Resource belongs to a user-defined class. **CLUS_RESCLASS_USER** specifies the
beginning of the range for user-defined resource classes.

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a [CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) with a value
of **CLUSPROP_SYNTAX_RESCLASS** (0x00020002) and a **cbLength** field indicating
the count of bytes in the **rc** member.

## Remarks

A resource class identifies resources of similar capability. A
[resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) that defines its own resource class should
provide a unique identifier for the class that is set to a value greater than
**CLUS_RESCLASS_USER**. **CLUS_RESCLASS_USER** specifies the
beginning for user-defined resource class identifiers.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[CLUSTER_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_class)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)