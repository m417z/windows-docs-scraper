# IGetClusterUIInfo::GetLocale

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns the locale identifier to be used with property and wizard pages.

## Return value

**GetLocale** always returns the locale
identifier for the cluster.

## Remarks

[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) extensions call the
**GetLocale** method to retrieve the locale
identifier that can be used for loading dialog resources. A single Failover Cluster Administrator extension DLL
can support multiple languages.

## See also

[IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)