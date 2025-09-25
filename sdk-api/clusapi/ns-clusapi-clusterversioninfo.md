# CLUSTERVERSIONINFO structure

## Description

Describes
information about the version of the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service)
installed locally on a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes).

## Members

### `dwVersionInfoSize`

Size, in bytes, of the data structure. Users must set this size prior to calling
[GetClusterInformation](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterinformation).

### `MajorVersion`

Identifies the major version number of the operating system installed on the local node. For example, for
version X.Y, the major version number is X.

### `MinorVersion`

Identifies the minor version number of the operating system installed on the local node. For example, for
version X.Y, the minor version number is Y.

### `BuildNumber`

Identifies the build number of the operating system installed on the local node, such as 224.

### `szVendorId`

Contains the vendor identifier information for the Cluster service installed on the local node.

### `szCSDVersion`

Contains the latest service pack installed on the node. If a Service Pack has not been installed, the
**szCSDVersion** member is empty.

### `dwClusterHighestVersion`

Identifies the highest version of the Cluster service with which the Cluster service installed on the local
node can join to form a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `dwClusterLowestVersion`

Identifies the lowest version of the Cluster service with which the Cluster service installed on the local
node can join to form a cluster.

### `dwFlags`

If the cluster nodes are running different versions of the Cluster service, this value is set to
**CLUSTER_VERSION_FLAG_MIXED_MODE**. If all cluster nodes are running the same version of
the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service), this value is 0.

### `dwReserved`

This value is reserved for internal use.

## Remarks

To obtain cluster version information, applications declare a
**CLUSTERVERSIONINFO** structure, specify the size of the
structure in the **dwVersionInfoSize** member, and call the
[GetClusterInformation](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterinformation) function.
**GetClusterInformation** fills in the structure
member data.

To prevent overwrites for all possible combinations of version information, always set
**dwVersionInfoSize** to:

`sizeof(CLUSTERVERSIONINFO)`

The **dwClusterHighestVersion** and **dwClusterLowestVersion**
values indicate whether the local node can join with another node to form a cluster. A join can succeed if one of
the following is true:

* The local node's highest version exactly matches the other node's highest version.
* The local node's lowest version exactly matches the other node's highest version.
* The local node's highest version exactly matches the other node's lowest version.

For more information on how the Cluster service creates and uses version numbers, see
[Version Compatibility](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/version-compatibility).

## See also

[GetClusterInformation](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterinformation)