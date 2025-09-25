# CLUSTER_SHARED_VOLUME_STATE_INFO_EX structure

## Description

Represents information about the state of a Cluster Shared Volume (CSV).

## Members

### `szVolumeName`

A Unicode string that contains the volume name of the CSV. The string ends in a terminating null character. The name that is provided can be either the cluster-assigned friendly name or the volume GUID path of the form "\\?\Volume{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}\".

### `szNodeName`

The node name of the node that hosts the CSV.

### `VolumeState`

A [CLUSTER_SHARED_VOLUME_STATE](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-cluster_shared_volume_state) enumeration value that specifies the state of the CSV.

### `szVolumeFriendlyName`

The friendly name of the CSV.

### `RedirectedIOReason`

A bitmask that specifies more specific reasons for the values stated in the *VolumeRedirectedIOReason* parameter.

This member can contain one or more of the following values:

#### RedirectedIOReasonUserRequest (0x0000000000000001)

A user request to enable direct access mode.

#### RedirectedIOReasonUnsafeFileSystemFilter (0x0000000000000002)

The file system filter is unsafe.

#### RedirectedIOReasonUnsafeVolumeFilter (0x0000000000000004)

The volume filter is unsafe.

#### RedirectedIOReasonFileSystemTiering (0x0000000000000008)

Tiered storage is enabled.

#### RedirectedIOReasonBitLockerInitializing (0x0000000000000010)

BitLocker is initializing.

#### RedirectedIOReasonReFs (0x0000000000000020)

TBD

**Windows Server 2012 R2, Windows Server 2012 and Windows Server 2008 R2:** This member was added in Windows Server 2016.

#### RedirectedIOReasonMax (0x8000000000000000)

All reasons.

### `VolumeRedirectedIOReason`

A bitmask that specifies the reasons that direct access mode is enabled on the CSV.

This member can contain one or more of the following values:

#### VolumeRedirectedIOReasonNoDiskConnectivity (0x0000000000000001)

There is no disk connectivity.

#### VolumeRedirectedIOReasonStorageSpaceNotAttached (0x0000000000000002)

The storage space is not attached.

#### VolumeRedirectedIOReasonVolumeReplicationEnabled (0x0000000000000004)

Replication is enabled on the volume.

**Windows Server 2012 R2, Windows Server 2012 and Windows Server 2008 R2:** This member was added in Windows Server 2016.

#### VolumeRedirectedIOReasonMax (0x8000000000000000)

All reasons.

## See also

[CLUSTER_SHARED_VOLUME_STATE_INFO](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_shared_volume_state_info)

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)