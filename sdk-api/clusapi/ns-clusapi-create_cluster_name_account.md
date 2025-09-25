# CREATE_CLUSTER_NAME_ACCOUNT structure

## Description

Describes a [cluster name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource and domain credentials used by the [CreateClusterNameAccount](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternameaccount) function to add a cluster to a domain. **PCREATE_CLUSTER_NAME_ACCOUNT** defines a pointer to this structure.

## Members

### `dwVersion`

The major version of the OS that runs on the cluster. This member must be set to a value greater than **CLUSAPI_VERSION_WINDOWSBLUE**.

### `lpszClusterName`

The cluster name that represents the cluster on the domain.

### `dwFlags`

Reserved for future use. This value must be "0".

### `pszUserName`

The user name for the domain credentials.

### `pszPassword`

The password for the domain credentials.

### `pszDomain`

The domain name to join.

### `managementPointType`

The management point type.

### `managementPointResType`

### `bUpgradeVCOs`

## See also

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)