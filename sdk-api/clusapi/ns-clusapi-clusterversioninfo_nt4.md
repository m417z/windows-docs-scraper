# CLUSTERVERSIONINFO_NT4 structure

## Description

TBD

## Members

### `dwVersionInfoSize`

Contains the size, in bytes, of the data structure. Users must set this size prior to calling the
[GetClusterInformation](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterinformation) function.

### `MajorVersion`

Identifies the major version number of the operating system that is installed on the local node. For example, for
version X.Y, the major version number is X.

### `MinorVersion`

Identifies the minor version number of the operating system that is installed on the local node. For example, for
version X.Y, the minor version number is Y.

### `BuildNumber`

Identifies the build number of the operating system that is installed on the local node, such as 224.

### `szVendorId`

Contains the vendor identifier information for the cluster service that is installed on the local node.

### `szCSDVersion`

Contains the latest service pack that is installed on the node. If a Service Pack is not installed, the
**szCSDVersion** member is empty.

## See also

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)