# CLUSTER_SHARED_VOLUME_STATE_INFO structure

## Description

Represents information about the state of a Cluster Shared Volume (CSV).

## Members

### `szVolumeName`

A Unicode string that contains the volume name of the CSV. The string ends in a terminating null character. The name that is provided can be either the cluster-assigned friendly name or the volume GUID path of the form "\\?\Volume{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}\".

### `szNodeName`

The node name of the node that hosts the CSV.

### `VolumeState`

A [CLUSTER_SHARED_VOLUME_STATE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_shared_volume_state) enumeration value that specifies the state of the CSV.

## See also

[CLUSTER_SHARED_VOLUME_STATE_INFO_EX](https://learn.microsoft.com/windows/win32/api/clusapi/ns-clusapi-cluster_shared_volume_state_info_ex)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)