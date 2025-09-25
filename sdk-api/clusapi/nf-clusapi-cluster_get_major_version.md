# CLUSTER_GET_MAJOR_VERSION macro

## Description

Extracts the major version portion of a [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) version number.

## Parameters

### `_ver`

Cluster service version number.

## Remarks

Cluster service version numbers are obtained from the [NodeHighestVersion](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes-nodehighestversion) and [NodeLowestVersion](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes-nodelowestversion) properties as well as the function [GetClusterInformation](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterinformation). For more information, see [Version Compatibility](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/version-compatibility).

In Windows Server 2016 Minor version has been renamed to upgrade version, but the [CLUSTER_GET_MINOR_VERSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-cluster_get_minor_version) macro remains for compatibility.

## See also

[CLUSTER_GET_MINOR_VERSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-cluster_get_minor_version)

[CLUSTER_GET_UPGRADE_VERSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-cluster_get_upgrade_version)

[CLUSTER_MAKE_VERSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-cluster_make_version)