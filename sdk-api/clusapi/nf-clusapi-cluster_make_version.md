# CLUSTER_MAKE_VERSION macro

## Description

Creates a Cluster service version number.

## Parameters

### `_maj`

Major version number.

### `_min`

Minor version number.

## Remarks

Cluster service version numbers are obtained from the [NodeHighestVersion](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes-nodehighestversion) and [NodeLowestVersion](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes-nodelowestversion) properties as well as the function [GetClusterInformation](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterinformation). For more information, see [Version Compatibility](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/version-compatibility).

## See also

[CLUSTER_GET_MAJOR_VERSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-cluster_get_major_version)

[CLUSTER_GET_MINOR_VERSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-cluster_get_minor_version)