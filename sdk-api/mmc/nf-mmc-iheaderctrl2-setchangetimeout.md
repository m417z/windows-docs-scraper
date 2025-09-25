# IHeaderCtrl2::SetChangeTimeOut

## Description

The **IHeaderCtrl2::SetChangeTimeOut** sets the time-out interval between the time a change takes place in the filter attributes and the posting of an
[MMCN_FILTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-filter-change) filter change notification, which is sent to the snap-in's
[IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) method.

## Parameters

### `uTimeout` [in]

Filter change interval in milliseconds. The default is an implementation detail of the header control, and as a result MMC does not know about it.

## Return value

This method can return one of these values.

## See also

[IHeaderCtrl2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl2)

[MMCN_FILTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-filter-change)