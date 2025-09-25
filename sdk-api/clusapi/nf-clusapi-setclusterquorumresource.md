# SetClusterQuorumResource function

## Description

Establishes a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) as the
[quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) for a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_SET_CLUSTER_QUORUM_RESOURCE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the new quorum resource; or the existing
[quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) when
*dwMaxQuoLogSize* is
**CLUS_NODE_MAJORITY_QUORUM**.

### `lpszDeviceName` [in, optional]

Determines the drive letter and path that the Cluster service will use to maintain the quorum files on the
new quorum resource. Pass a null-terminated Unicode string or **NULL**, as follows.

* If you specify a drive letter in the path, the Cluster service will verify that the drive letter refers
  to a valid partition on the new quorum resource.
* If you do not specify a drive letter in the path, the Cluster service will use a default partition on the
  new quorum resource (see below).
* If **NULL**, the Cluster service will use a default partition and a default path
  name (see below).

The [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) uses the partition flagged as
**CLUSPROP_PIFLAG_DEFAULT_QUORUM** as the default partition (see
[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)), or, if the flag
cannot be found, the first available NTFS partition on the new quorum resource.

For the default path name, the Cluster service uses the previous path name if one exists; otherwise it uses
"MSCS".

### `dwMaxQuoLogSize` [in]

The quorum type value. Specify one of the three constants listed. When you specify **CLUS_NODE_MAJORITY_QUORUM**,  *hResource* must refer to the existing [quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource).

#### CLUS_HYBRID_QUORUM (1024 (0x400))

#### CLUS_NODE_MAJORITY_QUORUM (0 (0x0))

#### CLUS_LEGACY_QUORUM (4194304 (0x400000))

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error
code.

| Return code/value | Description |
| --- | --- |
| **ERROR_RESOURCE_NOT_ONLINE**<br><br>5004 (0x138C) | The quorum resource is not online. |

## Remarks

Do not call **SetClusterQuorumResource** from
a resource DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[GetClusterQuorumResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterquorumresource)