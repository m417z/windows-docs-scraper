# IGetClusterDataInfo::GetObjectCount

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns a count of the number of selected
[cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects).

## Return value

A count of the number of selected objects.

## Remarks

Because [Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) supports
only one selected object, the
**GetObjectCount** method always returns
1.

## See also

[IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)