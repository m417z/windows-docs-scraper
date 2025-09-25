## Description

Represents the properties of a cluster resource. This structure is used to enumerate cluster resources in the [ClusterResourceEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenumex) function.

## Members

### `dwVersion`

The version of this structure.

### `cbId`

The size, in bytes, of the **lpszId** field.

### `lpszId`

The ID of the cluster resource.

### `cbName`

The size, in bytes, of the **IpszName** field.

### `lpszName`

The name of the cluster resource.

### `cbOwnerGroupName`

The size, in bytes, of the **IpszOwnerNode** field.

### `lpszOwnerGroupName`

The name of the cluster resource that hosts the group.

### `cbOwnerGroupId`

The size, in bytes, of the **lpszOwnerGroupId** field.

### `lpszOwnerGroupId`

The group ID of the cluster group for the resource.

### `cbProperties`

The size, in bytes, of the **pProperties** field.

### `pProperties`

A pointer to a list of names of common properties.

### `cbRoProperties`

The size, in bytes, of the **pRoProperties** field.

### `pRoProperties`

A pointer to a list of names of read-only common properties.

## See also

[ClusterResourceEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenumex)

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)