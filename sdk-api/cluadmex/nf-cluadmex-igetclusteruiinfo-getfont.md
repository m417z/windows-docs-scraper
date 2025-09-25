# IGetClusterUIInfo::GetFont

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns a handle to the font to be displayed on property and wizard pages.

## Return value

If **GetFont** is successful, it returns a
font handle.

## Remarks

The **GetFont** method returns the font handle
as **NULL**.
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) extensions should not
use this return value in their user interface displays.

## See also

[IGetClusterUIInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusteruiinfo)