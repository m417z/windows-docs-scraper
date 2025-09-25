# MMC_FILTER_CHANGE_CODE enumeration

## Description

The
**MMC_FILTER_CHANGE_CODE** enumeration is introduced in MMC 1.2.

The
**MMC_FILTER_CHANGE_CODE** enumeration specifies the filter change codes that can be sent as the *arg* parameter of an
[MMCN_FILTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-filter-change) notification in calls to
[IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify).

## Constants

### `MFCC_DISABLE:0`

The filter view has been turned off.

### `MFCC_ENABLE:1`

The filter view has been turned on.

### `MFCC_VALUE_CHANGE:2`

The filter value of a column in a result view filter list has changed. The *param* parameter of the
[IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) method contains the column ID.

## See also

[Adding Filtered Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-filtered-views)

[MMCN_FILTER_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-filter-change)