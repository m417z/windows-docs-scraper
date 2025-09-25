# CLUS_PROVIDER_STATE_CHANGE_INFO structure

## Description

Contains data about the state of a [provider](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/p-gly) resource.

## Members

### `dwSize`

The size of this structure including the provider name and the terminating null character.

### `resourceState`

An enumerator from the [CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state) enumeration as its value. The following are the possible values for this member.

#### ClusterResourceInherited (0)

The resource has been inherited.

#### ClusterResourceOnline (2)

The resource is operational and functioning normally.

#### ClusterResourceOffline (3)

The resource is not operational.

#### ClusterResourceFailed (4)

The resource has [failed](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/f-gly).

#### ClusterResourceOnlinePending (129 (0x81))

The resource is in the process of coming online.

#### ClusterResourceOfflinePending (130 (0x82))

The resource is in the process of going offline.

### `szProviderId`

The globally unique ID of the provider resource. This value can also be passed to the *lpszResourceName* parameter of the [OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource) function instead of a resource's name.

## See also

[CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state)

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)