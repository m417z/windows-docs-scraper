## Description

Contains the properties of a cluster group. This structure is used to enumerate cluster groups in the
[ClusterGroupEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenumex) function.

## Members

### `dwVersion`

The version of the
**CLUSTER_GROUP_ENUM_ITEM** structure.

### `cbId`

The size, in bytes, of the **lpszId** field.

### `lpszId`

The Id of the cluster group.

### `cbName`

The size, in bytes, of the **IpszName** field.

### `lpszName`

The name of the cluster group.

### `state`

The current state of the cluster group.

### `cbOwnerNode`

The size, in bytes, of the **IpszOwnerNode** field.

### `lpszOwnerNode`

The name of the cluster node hosting the group.

### `dwFlags`

The group flags.

### `cbProperties`

The size, in bytes, of the **pProperties** field.

### `pProperties`

A pointer to a list of names of common properties.

### `cbRoProperties`

The size, in bytes, of the **pRoProperties** field.

### `pRoProperties`

A pointer to a list of names of read-only common properties.