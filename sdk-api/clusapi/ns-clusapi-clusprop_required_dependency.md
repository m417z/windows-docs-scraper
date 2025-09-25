# CLUSPROP_REQUIRED_DEPENDENCY structure

## Description

Describes a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) that is a required
[dependency](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) of another resource. This union is used as
a value in the [value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) returned from a
[CLUSCTL_RESOURCE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-required-dependencies) or
[CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-required-dependencies)
[control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) operation.

## Members

### `Value`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing whether the data
in the structure is a resource class or resource type name.

### `ResClass`

Resource class upon which a resource must depend. One of the following values are valid.

#### CLUS_RESCLASS_UNKNOWN (0)

A resource has a dependency on a resource of an unknown class.

#### CLUS_RESCLASS_STORAGE (1)

A resource has a dependency on a storage device, such as a
[Physical Disk](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disk) resource.

#### CLUS_RESCLASS_NETWORK (2)

A resource has a dependency on a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/n-gly) device.

#### CLUS_RESCLASS_USER (32768)

A resource has a dependency on a resource belonging to a user-defined class.
**CLUS_RESCLASS_USER** specifies the beginning of the range for user-defined resource
classes.

### `ResTypeName`

[Resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) upon which a resource must depend, such
as [IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address).

## Remarks

The **CLUSPROP_REQUIRED_DEPENDENCY**
structure describes mandatory dependencies. For example, a
[Print Spooler](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/print-spooler) resource has required dependencies on a
storage device and a [Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource. The first type of
dependency is described using a resource class; storage device resources belong to the
**CLUS_RESCLASS_STORAGE** resource class. The second type of dependency is described
using a resource type name, such as "Network Name". Therefore, when an application calls
[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) with the
[CLUSCTL_RESOURCE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-required-dependencies)
control code, a value list is returned with two entries: a
**CLUSPROP_REQUIRED_DEPENDENCY** structure
with the **ResClass** member set to **CLUS_RESCLASS_STORAGE**, and
a second **CLUSPROP_REQUIRED_DEPENDENCY**
structure with the **ResTypeName** member set to "Network Name".

#### Examples

See [Creating Value Lists](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-value-lists).

## See also

[CLUSCTL_RESOURCE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-required-dependencies)

[CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-required-dependencies)

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)